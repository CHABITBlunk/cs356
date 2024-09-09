# user authentication

## user authentication

### rfc 2828

- rfc 2828 defines user authentication as "the process of verifying an identity claimed by or for a system identity"

### authentication process

- identification step
  - fundamental building block & primary line of defense
  - presenting an identifier to the security system
- verification
  - basis for access control & user accountability
  - presenting/generating authentication info that corroborates binding between entity & identifier

### user authentication

- 4 means of authentication
  - something individual knows (password, pin, answers to prearranged questions)
  - something individual possesses (token)
  - something individual is (static biometrics)
  - something individual does (voice pattern, handwriting, typing rhythm)

## password authentication

### password authentication

- widely used line of defense against intruders
  - user provides name/login & password
  - system compares password with hashed password stored for that specified login
- user id
  - determines that user authorized to access system
  - determines user privileges
  - used in discretionary access control

### vulnerabilities

- offline dictionary attack
- specific account attack
- popular password attack
- password guessing against single user
- workstation hijacking
- exploiting user mistakes
- exploiting multiple password use
- electronic monitoring

### countermeasures

- controls to prevent unauthorized access to password file
- intrusion detection measures
- rapid reissuance of compromised passwords
- account lockout mechanisms
- policies to inhibit users from selecting common passwords
- training in & enforcement of password policies
- automatic workstation logout
- policies against similar passwords on network devices

### use of hashed passwords

- throw a little salt and the password into a slow hash function
  - salt makes each password guaranteed unique

### unix implementation

- original scheme
  - up to 8 printable characters in length
  - 12-bit salt used to modify des encryption into 1-way hash function
  - zero value repeatedly encrypted 25 times
  - output translated to 11-char sequence
- now regarded as inadequate
  - still often required for compatibility with existing account mgmt software or multivendor environments

### improved implementations

- recommended hash function based on md5
  - salt up to 48 bits
  - password length unlimited
  - produces 128-bit hash
  - uses inner loop with 1000 iterations to achieve slowdown
- openbsd uses blowfish block cipher based hash algorithm called bcrypt
  - most secure version of unix hash/salt scheme
  - uses 128-bit salt to create 192-bit hash value

### password cracking

- dictionary attacks
  - develop large dictionary of possible passwords & try each against password file
  - each password must be hashed using each salt value, then compared to stored hash values
- rainbow table attacks
  - pre-compute enormous table of hash values for all salts
  - can be countered by using sufficiently large salt value & hash length

### password file access control

- can block offline guessing attacks by denying access to encrypted passwords
- make available only to privileged users
- shadow password file
  - separate file from user ids where hashed passwords are kept
- vulnerabilities
  - weakness in os that allows access to file
  - accident with persmisisons making it readable
  - users with same password on other systems
  - access from backup media
  - sniff passwords in network traffic

### password selection techniques

- user education
  - users can be told importance of using hard-to-guess passwords & can be provided with guideines for selecting strong passwords
- computer generated passwords
  - users have trouble remembering them
- reactive password checking
  - system periodically runs its own password cracker to find guessable passwords
- proactive password checking
  - user allowed to select their own password, however system checks to see if password allowable, if not, rejects it
  - goal is to eliminate guessable passwords while allowing user to select a password that is memorable

### proactive password checking

- password cracker
  - compile large dictionary of passwords to not use
- rule enforcement
  - specific rules that passwords must adhere to
- bloom filter
  - probabilistic data structure using a bit map. hash a word n times & place a 1 at bit index for each hash
  - by definition, this can check for if a value is "possibly in the set" or "definitely not in the set"
    - can get false positives
  - extremely efficient, all you need is a few hash functions
  - used to build a table based on dictionary using hashes
  - check desired password against this table

## other authentication methods

### token authentication

- object user possesses to authenticate
  - e.g. embossed card, magnetic stripe card, memory card, smartcard

### biometric authentication

- attempts to authenticate sb based on unique physical characteristics
- based on pattern recognition
- technically complex & expensive compared to passwords & tokens
