# chapter 2

## symmetric encryption

### block ciphers

- processes input of 1 block of elements at a time
- produces an output block for each input block
- can reuse keys
- more common

### stream ciphers

- processes input elements continuously
- produces output 1 element at a time
- primary advantage is that they are almost always faster & use less code
- encrypts plaintext one byte at a time

### block cipher concepts

1. divide (plaintext) data into fixed blocks

- des divides message into 64-bit blocks

2. apply algorithm to each block

- input is block & symmetric key
- output is block of encrypted data

3. transmit encrypted block
4. decrypt block

- input is block & symmetric key
- output is block of decrypted data

### data encryption standard (des)

- most widely used encryption scheme
  - fips pub 46
  - referred to as data encryption algorithm (dea)
  - uses 64-bit plaintext block & 56-bit key to produce a 64-bit ciphertext block
- strength concerns
  - concerns about algorithm
    - des is most studied encryption algorithm in existence
  - use of 56-bit key
    - electronic frontier foundation (eff) announced in 1998 that it had broken a des encryption

### triple des (3des)

- repeats basic des algorithm 3x using either 2/3 unique keys
- 1st standardized for use in financial applications in ansi standard x9.17 in 1985
- attractions
  - 168-bit key length overcomes vulnerability to brute-force attack of des
  - underlying algorithm is same as des
- drawbacks
  - algorithm is sluggish
  - uses 64-bit block size

### advanced encryption standard (aes)

- 3des not suitable for long term use
- block size (bits): 128
- key size (bits): 128, 192, or 256

### practical security issues

- typically symmetric encryption is applied to a unit of data larger than a single 64/128-bit block
- electronic codebook (ecb) mode is the simplest approach to multiple-block encryption
  - each block of plaintext is encrypted using the same key
  - cryptanalysts may be able to exploit regularities in plaintext
- modes of operation
  - alternative techniques developed to increase security of symmetric block encryption for large sequences
  - overcomes weakness of ecb

## asymmetric encryption

### diffie-hellman key exchange

- a & b have common paint
- add secret colors
- a & b exchange their paints
- add same secret colors
- end up with exact same common secret

### public key encryption structure

- based on mathematical functions
- uses 2 separate keys (public & private)
- public key is made public for others to use
- some form of protocol is needed for distribution of keys

### simple key-pair example

- key-pairs normally derived from very large prime numbers
- algorithms
  - encrypt: ciphertext = plaintext^e % n
  - decrypt: plaintext = ciphertext^d % n
- for this example, we use 3 small integers for simplicity
  - set keys to <e=3, n=55> & <d=27,n=55>
- e.g.: encrypt number 43 into 32, then back again into 43

### requirements for public-key cryptosystems

- computationally easy to create key pairs
- either key can be used for each role
- computationally easy for sender knowing public key to encrypt messages
- computationally infeasible for opp to otherwise recover original message

### public key algorithms

- rsa (rivest, shamir, adleman)
  - developed in 1977
  - only widely accepted public-key encryption algorithm
  - given tech advances need 1024+ bit keys. 2048 bits now more common
- diffie-hellman
  - only allows exchange of secret key
- digital signature standard (dss)
  - provides only digital signature function with sha1
- elliptic curve cryptography (ecc)
  - new, security like rsa but with much smaller keys

### cryptography applications

- common to encrypt transmitted data
  - "data in motion"
  - e.g. tls (https)
- stored data
  - "data at rest"
    - can be copied, backed up, & recovered
  - approaches
    - backend appliances
    - lib-based tape encryption
    - background laptop/pc data encryption, disk

### elliptic curve cryptography

- operates on elliptic curve mathematical equations
- utilizes a set of points to form ecc operations
- each key corresponds to a point on the curve
  - private key (random number)
  - public key (derived from private key via scalar multiplication, i.e. a series of dot products)
- public key generation
  - perform repeated additions (dot products) of a point on the elliptic curve a certain number of times
    - num repetitions determined by private key
- advantages
  - efficient - shorter key lengths
  - resistant to quantum attacks
  - scalable
    - widely used in modern cryptographic protocols (tls)
    - suitable for resource-constrained applications (e.g. iot)

## message authentication

### message authentication

- protects against active attacks
- verifies received message is authentic
  - contents haven't been altered
  - from authentic source
  - timely & in correct sequence

### hash function requirements

- can be applied to a block of data of any size
- produces fixed-length output
- H(x) needs to be easy to compute
- one-way or pre-image resistant
  - computationally infeasible to find x such that H(x) = h
- second pre-image resistant or weak collision resistant
  - computationally infeasible to find y != x such that H(y) = H(x)

### security of hash functions

- 2 approaches
  - cryptanalysis - exploit logical weaknesses in algorithm
  - brute-force attack - strength of hash depends solely on length of hash code produced by algorithm
- sha most widely used hash algorithm
- additional secure hash function applications
  - passwords
  - intrusion detection
    - store H(F) for each file on system & secure hash values

### digital signatures

- used for authenticating both source & data integrity
- created by encrypting hash code with private key
- doesn't provide confidentiality
  - even in case of complete encryption, message safe from alteration but not eavesdropping

## random numbers

### use of random numbers

- keys for public-key algorithms
- stream key for symmetric stream cipher
- symmetric key for use as temporary session key or in creating digital envelope
- handshaking to prevent replay attacks
- session key

### pseudorandom vs random

- often use algorithmic technique to create pseudorandom numbers which satisfy statistical randomness tests
  - caveat: likely predictable
- true rng use a nondeterministic source
  - e.g. radiation, gas discharge, leaky capacitors
  - increasingly provided on modern processors
