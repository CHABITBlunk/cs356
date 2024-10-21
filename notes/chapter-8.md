# chapter 8

## intrusion detection system (ids)

### logical components

- sensors - collect data
- analyzers - determine if intrusion occurred
- user interface - view output or control system behavior

### requirements

- run continually
- be fault tolerant
- resist subversion
- impose minimal system overhead
- configured according to system security policy
- adopt to changes in systems & users
- scale to monitor large numbers of systems
- provide graceful degradation of service
- allow dynamic reconfiguration

### analysis approaches

- anomaly detection
  - involves collection of data relating to behavior of legit users over long period of time
  - current observed behavior is analyzed to determine whether this behavior is that of a legit user or of intruder
- signature/heuristic detection
  - uses set of known malicious data patterns or attack rules compared with current behavior
  - aka misuse detection
  - can only identify known attacks for which is has patterns/rules

### anomaly detection

- statistical
  - analysis of observed behavior using univariate, multivariate, or time-series models of observed metrics
- knowledge based
  - approaches use an expert system that classifies observed behavior according to a set of rules that model legit behavior
- machine learning
  - approaches automatically determine a suitable classification model from training data using data mining techniques

### signature/heuristic detection

- signature approaches
  - match large collection of known patterns of malicious data against data stored on system or in transit over network
  - signatures need to be large enough to minimize false alarm rate, while still detecting sufficiently large fraction of malicious data
  - widely used in antivirus products, network traffic scanning proxies, & nids
- rule-based heuristic identification
  - involves use of rules for identifying known penetrations or penetrations that would exploit known weaknesses
  - rules can also be defined that identify suspicious behavior, even when behavior is within bounds of established patterns of usage
  - typically rules used are specific
  - snort is an example of a rule-based nids

### host-based intrusion detection system (hids)

- adds specialized layer of security software to vulnerable or sensitive systems
- can use either anomaly or signature & heuristic approaches
- monitors activity to detect suspicious behavior
  - primary purpose is to detect intrusions, log suspicious events, & send alerts
  - can detect both external & internal intrusions

### data sources & sensors

- fundamental component of intrusion detection is sensor that collects data
- common data sources
  - system call traces
  - audit records
  - file integrity checksums
  - registry access

### network-based ids (nids)

- monitors traffic of selected points on a network
- examines traffic packet by packet in real or close to real time
- may examine network transport &/ app-level protocol activity
- comprised of several sensors, 1+ servers for nids mgmt functions, & 1+ mgmt consoles for human interface
- analysis of traffic patterns may be done at sensor, mgmt server, or both

### distributed/hybrid ids

- combines info from several sensors both host and network based in a central analyzer that is able to better identify & respond to intrusion activity

### intrusion detection techniques

- attacks suitable for signature detection
  - app layer recon & attacks
  - transport layer recon & attacks
  - network layer recon & attacks
  - unexpected app services
  - policy violations
- attacks suitable for anomaly detection
  - dos attacks
  - scanning
  - worms

### stateful protocol analysis (spa)

- subset of anomaly detection that compares observed network traffic against predetermined universal vendor supplied profiles of benign protocol traffic
  - this distinguishes it from anomaly techniques trained with org specific traffic protocols
- understands & tracks network, transport, & application protocol states to ensure they progress as expected
- key disadvantage: high resource use

### logging alerts

- typical info logged by nids sensor
  - timestamp
  - connection or session id
  - event or alert type
  - rating
  - network, transport, & app layer protocols
  - source & destination ip
  - source & destination tcp/udp ports, or icmp types & codes
  - number of bytes transmitted over connection
  - decoded payload data, such as app requests & responses
  - state-related info

### ietf intrusion detection working group

- purpose is to define data formats & exchange procedures for sharing info of interest to intrusion detection & response systems and to mgmt systems that may need to interact with them
- working group issued following rfcs in 2007
  - rfc 4765
    - describes data model to represent info exported by ids & explains rationale for using this model
    - implementation of data model in xml is presented, & xml doctype definition is developed
  - rfc 4766
    - defines requirements for intrusion detection message exchange format (idmef) and for a comms protocol for communicating idmef
  - rfc 4767
    - describes intrusion detection exchange protocol (idxp), app-level protocol for exchanging data between ids entities
    - idxp supports mutual cia over connection oriented protocol

## classes of intruders

### cyber criminals

- individuals/members of organized crime group with goal of financial reward
- activities include
  - identity theft
  - theft of financial credentials
  - corporate espionage
  - data theft
  - data ransoming
- typically, they're young, often eastern european, russian, or southeast asian hackers who do business on web
- meet in underground forums to trade tips & data & coordinate attacks

### activists

- either individuals, usually working as insiders, or members of larger group of outsider attacks who are motivated by social/political causes
- aka hacktivists
  - skill level often quite low
- aim of attacks is to promote & publicize their cause via
  - website defacement
  - dos attacks
  - theft & distribution of data that results in negative publicity/compromise of targets

### state-sponsored orgs

- groups of hackers sponsored by govts to conduct espionage/sabotage
- aka advanced persistent threats (apts) due to their covert nature & persistence over extended periods involved with any attacks in this class
- widespread nature & scope of these activities by a wide range of countries from china to us, uk, & intelligence allies

### others

- hackers with motivations other than those above
- include classic hackers or crackers motivated by technical challenge or peer-group esteem & reputation
- many of those responsible for discovering new categories of buffer overflow vulnerabilities could be regarded as members of this class
- given wide availability of attack toolkits, there are a pool of hobby hackers using them to explore system & network security

## intruder skill levels

### apprentice

- hackers with minimal technical skill who primarily use existing attack toolkits
- likely comprise largest number of attackers, including many criminals & hacktivists
- given use of existing known tools, these are easiest to defend against
- aka script kiddies

### journeyman

- hackers with sufficient technical skill to modify & extend attack toolkits to use newly discovered or purchased vulnerabilities
- may be able to locate new vulnerabilities to exploit that are similar to some already known
- likely found in all intruder classes
- adapt tools for use by others

### master

- hackers with high level technical skills capable of discovering new categories of vulnerabilities
- write new powerful attack toolkits
- some of better known classical hackers are at this level
- some employed by state-sponsored orgs
- defending against these attacks is hardest

## honeypots

### definition

- decoy systems designed to
  - lure potential attacker away from critical systems
  - collect info about attacker's activity
  - encourage attacker to stay on system long enough for admins to respond
- systems filled with fabricated info that legit user wouldn't be able to access
- resources that have no production value
  - therefore incoming comms is most likely a probe, scan, or attack
  - initiated outbound comms suggest that system has probably been compromised

### classifications

- low interaction
  - consists of software package that emulates particular it services or systems well enough to provide realistic initial interaction, but doesn't execute a full version of those services/systems
  - provides less realistic target
  - often sufficient for use as component of distributed ids to warn of imminent attack
- high interaction
  - real system with full os, services, & apps, which are instrumented & deployed where they can be accessed by attackers
  - more realistic target that may occupy attacker for extended period
  - requires significantly more resources than low interaction
  - if compromised, could be used to initiate attacks on other systems

## intrusion examples

- remote root compromise
- web server defacement
- guessing/cracking passwords
- copying dbs containing credit card numbers
- viewing sensitive data without authorization
- running packet sniffer
- distributing pirated software
- using unsecured modem to access internal network
- impersonating executive to get info
- using unattended workstation
