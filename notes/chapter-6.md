# malware

### definition

- nist 800-83: "a program that is inserted into a system, usually covertly, with the intent of compromising confidentiality, integrity, or availability of victim's data, apps, or os or otherwise annoying or disrupting victim"

### malicious software

- programs exploiting system vulnerabilities
- categorization
  - program fragments that need a host program
    - viruses, logic bombs, backdoors
  - independent self-contained programs
    - worms, bots
- classified as replicating or not
- sophisticated threat to computer systems

### terminology

- virus
- worm
- logic bomb
- trojan
- backdoor (trapdoor)
- mobile code
- auto-rooter kit (virus generator)
- spammer & flooder programs
- keyloggers
- rootkit
- zombie, bot

### classification of malware

- 2 broad categories
  - how does it propagate?
  - what does it do/payload once it reaches a target?
- classification
  - those that need a host program
  - those that are independent & self-contained
  - does it replicate?

### types of malware

- propagation mechanisms
  - infection of existing content by viruses that is then spread to other systems
  - exploit of software vulnerabilities by worms or drive-by downloads to allow malware to replicate
  - social engineering attacks that convince users to bypass security mechanisms to install trojans or respond to phishing
- payload actions performed by malware once target system reached
  - corruption of system/data files
  - theft of service/make system zombie as part of botnet
  - theft of information from system/keylogging
  - stealthing/hiding presence on system

### attack kits

- initially, development & deployment of malware required considerable technical skill by software authors
  - development of virus creation toolkits in early 1990s, then more general attack kits in 2000s greatly assisted in development & deployment of malware
- toolkits often known as "crimeware"
  - include a variety of propagation mechanisms & payload modules that even novices can deploy
  - variants that can be generated by attackers using these toolkits creates a significant problem for those defending systems against them
- examples
  - zeus
  - angler

### attack sources

- another significant malware development: attackers being individuals often motivated to demonstrate their technical competence -> more organized & dangerous attack sources
  - politically motivated attackers
  - criminals
  - organized crime
  - orgs that sell services to companies & nations
  - govt agencies

### advanced persistent threat (apt)

- well-resourced, persistent application of a wide variety of intrusion technologies & malware to selected targets (usually business or political)
- typically attributed to state-sponsored orgs & criminal enterprises
- differ from other types of attack by their careful target selection & stealthy intrusion efforts over extended periods
- high profile attacks include aurora, rsa, apt1, and stuxnet
- characteristics
  - advanced
    - used by attackers of a wide variety of intrusion technologies & malware including development of custom malware if required
    - individual components may not necessarily be technically advanced but are carefully selected to suit chosen target
  - persistent
    - determined application of attacks over an extended period against chosen target in order to maximize chance of success
    - variety of attacks may be progressively applied until target compromised
  - threat
    - threats to selected targets as result of organized, capable, & well-funded attackers' intent to compromise
- attacks
  - aim
    - varies from theft of intellectual property or security & infrastructure related data to physical disruption of infrastructure
  - techniques used
    - social engineering
    - spear-phishing email
    - drive-by downloads from selected compromised websites likely to be visited by personnel in target org
  - intent
    - to infect target with sophisticated malware with multiple propagation mechanisms & payloads
    - once they have gained initial access to systems in target org, more attacks tools are used to maintain & extend access

## viruses

### definition

- piece of software that infects programs
  - modifying them to include copy of virus so it executes secretly when host program is run
- specific to os & hardware, taking advantage of details & weaknesses
- typical virus phases
  - dormant
  - propagation
  - triggering
  - execution

### structure

- components
  - infection mechanism - enables replication
  - trigger - event that activates payload
  - payload - what it does, malicious or benign
- prepended/postpended/embedded
- when infected program invoked, executes virus code, then original program code
- can block initial infection (difficult) or propagation (with access controls)

### classification

- boot sector
- file infector
- macro
  - became very common in mid-1990s
    - platform-independent
    - infect documents
    - easily spread
  - exploit macro capability of office apps
    - executable program embedded in office doc
    - often a form of Basic
  - more recent releases include protection
  - recognized by many antivirus programs
- encrypted
- stealth
- polymorphic - only change appearance on propagation
- metamorphic - change everything on propagation
- email
  - more recent
  - e.g. melissa
    - exploits ms word macro in attached doc
    - if attachment opened, macro activates
    - sends email to all on user's address list
    - does local damage
  - saw versions triggered reading email -> much faster propagation

### countermeasures

- prevention - ideal but difficult
- realistic requirements
  - detection
  - identification
  - removal
- if detected but can't identify or remove, must discard & replace infected program

### antivirus evolution

- virus & antivirus have both evolved
- early viruses had simple code, easily removed
- as they become more complex, so must the countermeasures
- generations
  - first - signature scanners
  - second - heuristics
  - third - memory resident, identify actions
  - fourth - combination packages

### generic decryption

- runs executables through gd scanner
  - cpu emulator to interpret instructions
  - virus scanner to check known virus signatures
  - emulation control module to manage process
- lets virus decrypt itself in interpreter
- periodically scan for virus signatures
- issue: interpreting & scanning is long
  - tradeoff chance of detection vs. time delay

## worms

### definition

- replicating program that propagates over net
  - email, remote exec, remote login
- phases like virus
  - dormant, propagation, triggering, execution
  - propagation phase: searches for other systems, connects to it, copies self to it, runs
- may disguise itself as a system proc
- concept seen in brunner's _shockwave rider_
- implemented by xerox palo alto labs in 1980s

### morris worm

- one of best known worms
- released by robert morris in 1988
- various attack on unix systems
  - cracking password file to use login/password to log onto other systems
  - exploiting bug in finger protocol
  - exploiting bug in sendmail
- success -> gain remote shell access
  - sent bootstrap program to copy over worm

### worm replication methods

- email/instant messenger
  - worm sends copy of itself to other systems as attachment
- file sharing
  - creates copy of itself or infects a file as a virus on removable media
- remote execution capability
  - worm executes copy of itself on another system
- remote file access/transfer capability
  - worm uses remote file access/transfer service to copy itself from one system to another
- remote login capability

### target discovery

- scanning (fingerprinting)
  - first function in propagation phase
  - searches for other systems to infect
- random
  - each compromised host probes random addrs in ip addr space using a different seed
  - produces high volume of internet traffic which may cause generalized disruption even before actual attack is launched
- hit-list
  - first compiles long list of potentially vulnerable machines
  - once list compiled, attacker begins infecting machines on list
  - each infected machine provided with a portion of list
  - result: short scanning period which may make it more difficult to detect infection
- topological
  - uses info contained on an infected victim machine to find more hosts to scan
- local subnet
  - if a host can be infected behind a firewall, that host then looks for targets in its own lan
  - host uses subnet addr structure to find other hosts that would otherwise be protected by firewall

### notable worm attacks

- code red
  - july 2001 exploiting ms iis bug
  - probes random ips, does ddos
  - consumes significant net capacity when active
- code red ii variant includes backdoor
- sql slammer
  - early 2003, attacks ms sql server
  - compact & very rapid spread
- mydoom
  - mass-mailing email worm that appeared in 2004
  - installed remote access backdoor in infected systems

### worm technology

- multiplatform
- multi-exploit
- ultrafast spreading
- polymorphic
- metamorphic
- transport vehicles
- zero-day exploit

### mobile code

- programs that can be shipped unchanged to a heterogeneous collection of platforms & executed with identical semantics
- transmitted from a remote system to a local system, then executed on local system
- often acts as carrier for viruses, worms, or trojans
- takes advantage of vulnerabilities to perform its own exploits
- popular vehicles
  - java applets
  - activex
  - javascript
  - vbscript
- common ways of using mobile code for malicious operations on a local system
  - cross-site scripting
  - interactive & dynamic websites
  - email attachments
  - downloads from untrusted sites/software

### mobile phone worms

- first: cabir worm (2004)
- lasco & commwarrior (2005)
- communicate through bluetooth or mms
- targets smartphone
- can completely disable phone, delete data on phone, or force device to send costly messages
- commwarrior replicates via bluetooth to other phones, sends itself as an mms file to contacts & as an auto reply to incoming texts

### worm countermeasures

- overlaps with antivirus
- once worm is on system, av can detect
- worms also cause significant net activity
- worm defense approaches
  - signature-based worm scan filtering
  - filter-based worm containment
  - payload classification-based worm containment
  - threshold random walk scan detection
  - rate limiting/halting

## other kinds of malware

### drive-by downloads

- exploits browser & plugin vulnerabilities so when user views attacker-controlled webpage, page contains code that exploits bug to install malware on system without user's knowledge or consent
- in most cases, malware doesn't actively propagate like a worm
- spreads when users visit webpage

### watering hole attacks

- variant of drive-by download used in highly targeted attacks
- attacker researches intended victims to identify websites they're likely to visit, then scans these sites to identify those with vulnerabilities that allow their compromise
- wait for intended victims to visit compromised sites
- attack code may even be written so that it will only infect systems belonging to target org & take no action for other visitors to site
- greatly increases likelihood of site compromise remaining undetected

### malvertising

- places malware on sites without compromising them
- attacker pays for advertisements that are highly likely to be placed on intended target websites & incorporate malware in them
- attackers use ads to infect visitors to sites
- malware code may be dynamically generated to reduce chance of detection or only infect specific systems
- has grown rapidly in recent years because they're easy to place on desired sites, raises little concern, hard to track
- attackers can place these ads very quickly when they expect their intended victims to browse the website, greatly reducing visibility

### clickjacking

- aka ui redress attack
- using similar technique, keystrokes can also be hijacked
  - user can be led to believe they're typing in password, but are typing into invisible frame controlled by attacker
- vulnerability used by attacker to collect an infected user's clicks

### social engineering

- spam
  - unsolicited bulk email
  - significant carrier of malware
  - used for phishing
- trojan
  - program/utility containing harmful hidden code
  - used to accomplish functions that attacker can't do directly
- mobile trojans
  - first: skuller (2004)
  - target is smartphone

### bots

- program taking over other computers
- used to launch hard-to-trace attacks
- if coordinated, this forms a botnet
- characteristics
  - remote control facility via irc/http
  - spreading mechanism
    - attack software, vulnerability, scanning strategy
- various applicable countermeasures

### rootkits

- set of programs installed for admin access
- malicious & stealthy changes to host os
- may hide its existence
  - subverting report mechanisms on procs, files, registry entries, &c
- may be
  - persistent, memory-based, or vm-based
  - user mode, kernel mode, or external mode
- installed by user via trojan or intruder
- range of necessary countermeasures

### malware countermeasures

- ideally, prevention
  - policy
  - awareness
  - vulnerability mitigation
  - threat mitigation
- when & if prevention fails
  - detection
  - identification
  - removal
- antivirus
  - 1st gen - simple scanners
  - 2nd gen - heuristic scanners
  - 3rd gen - activity traps
  - 4th gen - full-featured protection
- sandboxing
  - running potentially malicious code in a sandbox to monitor behavior without damaging real system
- host based behavior blocking software
- digital immune systems

### perimeter scanning approaches

- antivirus software typically included in mail & web proxy services running on an org's firewall & dis
- may also be included in dis traffic analysis component
- may include intrusion prevention measures, blocking flow of any suspicious traffic
- approach is limited to scanning malware
- ingress monitors
  - located at border between enterprise network & internet
  - 1 technique is to look for incoming traffic to unused local ip addrs
- egress monitors
  - located at egress point of individual lans as well as at border between enterprise network & internet
  - monitors outgoing traffic for signs of scanning or other suspicious behavior