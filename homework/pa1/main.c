#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

struct message {
  unsigned size;
  char *content;
};

struct message read_message(const char *fname) {
  struct message out;
  FILE *fp = fopen(fname, "r");
  if (fp == NULL) {
    printf("File Does Not Exist\n");
    exit(EXIT_FAILURE);
  }

  struct stat st;
  if (stat(fname, &st) != 0) {
    perror("stat");
    exit(EXIT_FAILURE);
  }

  out.size = st.st_size;
  out.content = malloc(out.size);
  if (out.content == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  fread(out.content, 1, out.size, fp);
  fclose(fp);
  return out;
}

int scencrypt(const char *msgfname, const char *keyfname,
              const char *outfname) {
  struct message msg = read_message(msgfname);
  struct message key = read_message(keyfname);

  char *out = malloc(msg.size);
  if (out == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  for (unsigned i = 0, j = 0; i < msg.size; i++) {
    if (j == key.size) {
      j = 0;
    }
    out[i] = msg.content[i] ^ key.content[j++];
  }

  FILE *outfp = fopen(outfname, "w");
  if (outfp == NULL) {
    perror("fopen");
    free(out);
    return EXIT_FAILURE;
  }

  fwrite(out, 1, msg.size, outfp);
  fclose(outfp);
  free(out);
  free(msg.content);
  free(key.content);
  return EXIT_SUCCESS;
}

void padchars(char *block, unsigned size) {
  for (unsigned i = 0; i < size; i++) {
    if (block[i] == 0x0) {
      block[i] = 0x81;
    }
  }
}

void swapchars(char *block, unsigned size, int reverse) {
  if (reverse) {
    for (unsigned i = 0, j = size - 1; i < j; i++, j--) {
      if (block[j] % 2 == 0) {
        char temp = block[j];
        block[j] = block[i];
        block[i] = temp;
      }
    }
  } else {
    for (unsigned i = 0, j = size - 1; i < j; i++, j--) {
      if (block[i] % 2 == 0) {
        char temp = block[i];
        block[i] = block[j];
        block[j] = temp;
      }
    }
  }
}

void blockxor(const char *msg, const char *key, char *output, unsigned size) {
  for (unsigned i = 0; i < size; i++) {
    output[i] = msg[i] ^ key[i];
  }
}

int bcencryptdecrypt(const char *msgfname, const char *keyfname,
                     const char *outfname, int encrypt) {
  struct message msg = read_message(msgfname);
  struct message key = read_message(keyfname);
  if (key.size < 16) {
    key.content = realloc(key.content, 16);
    if (key.content == NULL) {
      perror("realloc");
      return EXIT_FAILURE;
    }
    padchars(key.content, 16);
    key.size = 16;
  }
  if (key.size > 16) {
    fprintf(stderr, "block key must be exactly 16 chars\n");
    free(msg.content);
    free(key.content);
    return EXIT_FAILURE;
  }

  FILE *out = fopen(outfname, "w");
  if (out == NULL) {
    perror("fopen");
    free(msg.content);
    free(key.content);
    return EXIT_FAILURE;
  }

  char *msgblock = malloc(key.size);
  char *output = malloc(key.size);
  if (msgblock == NULL || output == NULL) {
    perror("malloc");
    fclose(out);
    free(msg.content);
    free(key.content);
    return EXIT_FAILURE;
  }

  for (unsigned i = 0; i < msg.size; i += key.size) {
    memset(msgblock, 0x81, key.size);
    for (unsigned j = 0; j < key.size && i + j < msg.size; j++) {
      msgblock[j] = msg.content[i + j];
    }

    if (encrypt) {
      blockxor(msgblock, key.content, output, key.size);
      swapchars(msgblock, key.size, 0);
    } else {
      swapchars(output, key.size, 1);
      blockxor(msgblock, key.content, output, key.size);
    }

    fwrite(output, 1, key.size, out);
  }

  fclose(out);
  free(msgblock);
  free(output);
  free(msg.content);
  free(key.content);
  return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
  if (argc != 6) {
    fprintf(stderr,
            "usage: %s [B|S] <input_file> <output_file> <key_file> [E|D]\n",
            argv[0]);
    return EXIT_FAILURE;
  }

  if (!(strcmp(argv[5], "E") == 0 || strcmp(argv[5], "D") == 0)) {
    printf("Invalid Mode Type\n");
    return EXIT_FAILURE;
  }

  if (strcmp(argv[1], "B") == 0) {
    return bcencryptdecrypt(argv[2], argv[4], argv[3],
                            strcmp(argv[5], "E") == 0);
  } else if (strcmp(argv[1], "S") == 0) {
    return scencrypt(argv[2], argv[4], argv[3]);
  } else {
    fprintf(stderr, "Invalid Function Type\n");
    return EXIT_FAILURE;
  }
}
