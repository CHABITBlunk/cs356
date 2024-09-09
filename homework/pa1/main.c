#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  if (argc == 6) {
    // arg 1: check for block or stream
    if (strcmp(argv[1], "B") != 0 || strcmp(argv[1], "S") != 0) {
      printf("invalid function type");
      return EXIT_FAILURE;
    }
    // arg 2: check if input file path leads to a file
    if (fopen(argv[2], "r") == NULL) {
      printf("input file does not exist");
      return EXIT_FAILURE;
    }
    // arg 4: check if key file path leads to a file
    if (fopen(argv[4], "r") == NULL) {
      printf("key file does not exist");
    }
    // arg 5: check for encrypt or decrypt
    if (strcmp(argv[5], "E") != 0 || strcmp(argv[5], "D") != 0) {
      printf("invalid mode type");
      return EXIT_FAILURE;
    }
  }
  return EXIT_SUCCESS;
}

// function to encrypt & decrypt using a stream cipher
// TODO: this is essentially done. fix main and then test
char *scencrypt(const char *msgfname, const char *keyfname,
                const char *outfname) {
  // msg stats, fp, length, & string
  // <sys/stat.h> is *the* tool for this
  struct stat msgst;
  FILE *msgfp = fopen(msgfname, "r");
  stat(msgfname, &msgst);
  unsigned msglen = msgst.st_size;
  char msg[msglen];
  fgets(msg, msglen, msgfp);

  // key stats, fp, length, & string
  struct stat keyst;
  FILE *keyfp = fopen(keyfname, "r");
  stat(keyfname, &keyst);
  unsigned keylen = keyst.st_size;
  char key[keylen];
  fgets(key, keylen, keyfp);

  // output string
  char out[msglen];

  // algorithm
  int i = 0, j = 0;
  while ((i++) < msglen) {
    if (j == keylen) {
      j = 0;
    }
    out[i] = msg[i] ^ key[j];
    j++;
  }

  // create output fp
  FILE *outfp = fopen(outfname, "w");
  if (outfp == NULL) {
    return EXIT_FAILURE;
  }
  // write to out file
  fputs(out, outfp);
  return EXIT_SUCCESS;
}

void padchars(char block[16]) {
  for (int i = 0; i < 16; i++) {
    if (block[i] == 0 && block[i + 1] == 0) {
      block[i] = 8;
      if (i <= 15) {
        block[i + 1] = 1;
      }
    }
  }
}

// function to encrypt using a block cipher
int bcencrypt(const char *infname, const char *keyfname) {
  FILE *keyfp = fopen(keyfname, "r");
  struct stat keyst;
  stat(keyfname, &keyst);
  if (keyst.st_size > 16) {
    printf("key longer than 16 bytes\n");
    return EXIT_FAILURE;
  }
  char keyblock[16];
  fgets(keyblock, sizeof(keyblock), keyfp);
  padchars(keyblock);
  FILE *infp = fopen(infname, "r");
  struct stat inst;
  stat(infname, &inst);
  if (inst.st_size < 16) {
  }
  return EXIT_SUCCESS;
}
