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
