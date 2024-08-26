# chapter 1

### computer security

- protection afforded to automated information system in order to attain the applicable objectives of preserving the integrity, availability, and confidentiality of information system resources (includes hardware, software, firmware, info/data, telecomms)

### key security concepts

- integrity
  - guard info against unauthorized modification/destruction
- confidentiality
  - preserve authorized restrictions on info access & disclosure
- availability
  - ensure timely & reliable access to & use of info
- authenticity
  - verifying that users are who they are & that transmission was valid
- accountability
  - actions of an entity can be traced uniquely to that entity

### aaa in compsec

- authentication
- authorization
- accounting

### compsec challenges

- not simple
- must consider potential attacks
- uses counter-intuitive procedures
- involves algorithms & secret info
- must decide where to deploy mechanisms
- battle of wits between attacker & admin
- not perceived as benefit until fails
- requires regular monitoring
- too often an after-thought
- _regarded as impediment to using system_

### vulnerabilities & attacks

- system resource vulnerabilities may become
  - corrupted (loss of integrity)
  - leaky (loss of confidentiality)
  - unavailable (loss of availability)
- attacks are threats carried out & may be
  - passive
  - active
  - insider
  - outsider

### countermeasures

- means used to deal with security attacks
  - prevent
  - detect
  - recover
- may result in new vulnerabilities
- will have residual vulnerability
- goal is to minimize risk given constraints

### threat consequences

- unauthorized disclosure
  - exposure, interception, inference, intrusion
- deception
  - masquerade, falsification, repudiation
- disruption
  - incapacitation, corruption, obstruction
- usurpation
  - misappropriation, misuse

### network security attacks

- either passive or active
- passive
  - eavesdropping
  - release of message contents
  - traffic analysis
  - hard to detect so aim to prevent
- active attacks
  - modify/fake data
  - masquerade
  - replay
  - modification
  - dos
  - hard to prevent so aim to detect

### security functional requirements

- technical measures
  - access control
  - id & auth
  - system & communication protection
  - system & info integrity
- mgmt controls & procedures
  - awareness & training
  - audit & accountability
  - certification, accreditation, & security assessments
  - contingency planning
  - maintenance
  - physical & environmental protection
  - planning
  - personnel security
  - risk assessment
  - systems & services acquisition
- overlapping technical & mgmt
  - config mgmt
  - incident response
  - media protection

### standards bodies

- x.800, security architecture for osi
- systematic way of defining requirements for security & characterizing approaches to satisfying them
- defines
  - security attacks - compromise security
  - security mechanism - act to detect, prevent, recover from attack
  - security service - counter security attacks

### security strategy

- specification/policy
  - what is scheme supposed to do?
  - codify in policy & procedures
- implementation/mechanisms
  - how does it do it?
  - prevention, detection, response, recovery
- correctness/assurance
  - does it really work?
  - assurance, evaluation

### attack plan for in class activity

- passive
  - getting as much information as possible and then having a very clear plan of attack
  - keeping this on the personal side, e.g. using phishing and emotional manipulation, is a very good idea at first. probably also a good idea to get a job there
- active
  - using a rubber ducky
  - reverse shell
  - generate a ssh key pair on a machine with a lot of sensitive information
    - keep like a massive drive of all their email
  - trojans
  - posing as a cybersecurity company to get their information and "teach" them
  - find someone who works for the company and interrogate them
