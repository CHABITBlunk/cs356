# internet authentication apps

## kerberos

### overview

- initialy developed at mit
- software utility available in both public domain & commercially supported versions
- issued as internet standard & is defacto standard for remote auth
- overall scheme is that of trusted third party auth service
- requires that user prove their identity for each service invoked & requires servers to prove their identity to clients

### protocol

- involves clients, app servers, & kerberos server
  - designed to counter various threats to security of client/server dialogue
  - obvious security risk is impersonation
  - servers must be able to confirm identities of clients who request service
- use authentication server (as)
  - user initially negotiates with as for identity verification
  - as verifies identity, then passes info to app server which will then accept service requests from client
- need to find a way to do this securely
  - if client sends user's password to as over network, an attacker could observe it
  - attacker could impersonate as & send false validation

### realms

- environment consists of
  - kerberos server
  - number of clients registered with server
  - number of app servers sharing keys with server
- referred to as a realm
  - networks of clients & servers under different admin orgs generally constitute different realms
- if multiple realms
  - kerberos servers must share secret key & trust kerberos server in other realm to authenticate its users
  - participating servers in 2nd realm must also be willing to trust kerberos server in 1st realm

### versions 4 & 5

- 1st version widely used was v4 published in late '80s
- improvements in v5
  - encrypted message tagged with encryption algorithm identifier
    - enables users to configure kerberos to use algorithm other than des
  - supports auth forwarding
    - enables client to access server & have that server access another on behalf of client
    - supports method for interrealm authentication that requires fewer secure key exchanges than in v4

### performance issues

- large client-server installations
  - very little performance impact in large scale environment if system properly configured
    - security best assured by placing server on separate, isolated machine
      - motivation for multiple realms is administrative, not performance related

### cert authority (ca)

- cert consists of
  - public key with identity of key's owner
  - signed by trusted third party
  - typically, third party is ca trusted by user community (e.g. govt agency, telecomms company, financial institution, other trusted peak org)
- user can present their public key to authority in a secure manner & obtain cert
  - user can then publish cert or send it to others
  - anyone needing this user's publi key can obtain cert & verify that it is valid with attached trusted signature

### x.509

- specified in rfc 5280
- most widely accepted format for public key certs
- certs used in most network security apps, including
  - ipssec
  - ssl
  - secure electronic transactions (set)
  - s/mime
  - ebusiness apps

### specialized variants

- conventional (long-lived)
  - ca & "end user" certs
  - typically issued for validity periods of months to years
- short-lived
  - used to provide auth for apps such as grid computing, while avoiding some overheads & limitations of conventional certs
  - validity periods from hours to days, which limits period of misuse if compromised
  - because they are usually not issued by ca's, there are issues with verifying them outside their issuing org
- proxy
  - used to provide auth for apps such as grid computing, while addressing limitations of short-lived certs
  - defined in rfc 3820
  - identified by presence of "proxy cert" extension
  - allow "end user" cert to sign another cert
  - allow user to easily create credential to access resources in some environment without needing to provide their full cert & right
- attr certs
  - defined in rfc 5755
  - use different cert format to link user's identity to set of attrs typically used for auth & access control
  - user may have many different attr certs, with different set of attrs for different purposes
  - defined in an "attrs" extension

### public key infrastructure (pki)

- set of hardware, software, people, policies, & procedures needed to create, manage, store, distribute, & revoke digital certs based on asymmetric cryptography
- developed to enable secure, convenient, & efficient acquisition of public keys
- "trust store"
  - list of ca's & their public keys
