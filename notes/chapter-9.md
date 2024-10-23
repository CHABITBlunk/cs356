# chapter 9

## firewalls

### need for firewalls

- internet connectivity is essential, however it creates a threat
- effective means of protecting lans
- inserted between premises network & internet to establish controlled link
  - can be single computer system or set of 2+ systems working together
- used as perimeter defense
  - single choke point to impose security & auditing
  - insulates internal systems from external attacks

### characteristics

- design goals
  - all traffic must pass through firewall
  - only authorized traffic as defined by local security policy will be allowed to pass
  - firewall itself immune to penetration

### access policy

- critical component in planning & implementation of a firewall is specifying a suitable access policy
  - lists types of traffic authorized to pass through firewall
  - includes addr ranges, protocols, apps, & content types
- policy should be developed from org's info security risk assessment & policy
- should be developed from a broad spec of which traffic types org needs to support, then refined to detail filter elements which can then be implemented within an appropriate firewall topology

### filter characteristics

- ip addr & protocol values
  - used by packet filter & stateful inspection firewalls
  - typically used to limit access to specific services
- app protocol
  - used by app level gateway that relays & monitors exchange of info for specific app protocols
- user identity
  - typically for inside users who identify themselves using secure authentication tech
- network activity
  - controls access based on considerations such as time of request, rate of requests, or other activity patterns

### capabilities & limits

- capabilities
  - defines single choke point
  - provides location for monitoring security events
  - convenient platform for several internet functions that are not security related
  - can serve as platform for ipsec
- limits
  - cannot protect against attacks bypassing firewall
  - may not protect fully against internal threats
  - improperly secured wlan can be accessed from outside org
  - portable devices may be infected outside network then used internally

### packet filtering firewall

- applies rules to each incoming & outgoing ip packet
  - typically a list of rules based on matches in ip/tcp header
  - forwards/discards packet based on rules match
- filtering rules based in packet info
  - source ip
  - destination ip
  - source & destination transport level addr
  - ip protocol field
  - interface
- 2 default policies
  - discard - prohibit unless expressly permitted
    - more conservative, controlled, visible to users
  - forward - permit unless expressly prohibited
    - easier to manage & use but less secure
- advantages
  - simple
  - typically transparent to users
  - very fast
- weaknesses
  - cannot prevent attacks that employ app specific vulnerabilities or functions
  - limited logging functionality
  - don't support advanced user authentication
  - vulnerable to attacks on tcp/ip protocol bugs
  - improper config can lead to breaches

### stateful inspection firewall

- tightens rules for tcp traffic by creating a dir of outbound tcp connections
- entry for each currently established connection
- packet filter allows incoming traffic to high-numbered ports only for those packets that fit profile of an entry in this dir
- reviews packet info but also records info about tcp connections
- keeps track of tcp sequence numbers to prevent attacks that depend on sequence number
- inspects data for protocols like ftp, im, & sips commands

### app level gateway

- aka app proxy
- acts as relay of app level traffic
  - user contacts gateway using tcp/ip app
  - user authenticated
  - gateway contacts app on remote host & relays tcp segments between server & user
- must have proxy code for each app
  - may restrict app features supported
- tend to be more secure than packet filters
- disadvantage is additional processing overhead on each connection

### circuit level gateway

- circuit level proxy
  - sets up 2 tcp connections, 1 between itself & tcp user on inner host, 1 on outside host
  - relays tcp segments from 1 connection to other without examining contents
  - security function consists of determining which connections will be allowed
- typically used when inside users trusted
  - may use app level gateway inbound & circuit level gateway outbound
  - lower overheads

### socks circuit level gateway

- socks v5 defined in rfc1928
- designed to provide framework for client-server apps in tcp/udp domains to conveniently & securely use services of network firewall
- client app contacts socks server, authenticates, sends relay request
  - server evaluates & establishes/denies connection

### bastion hosts

- system identified as critical strong point in network's security
- serves as platform for app/circuit level gateway
- common characteristics
  - runs secure os, only essential services
  - may require user auth to access proxy or host
  - each proxy can restrict features, hosts accessed
  - each proxy is small, simple, checked for security
  - each proxy independent, non-privileged
  - limited disk use, hence read-only code

### host based firewalls

- used to secure individual host
- available in os or can be provided as add-on package
- filter & restrict packet flows
- common location is server
- advantages
  - filtering rules can be tailored to host
  - protection provided independent of topology
  - provides additional layer of protection

### personal firewall

- controls traffic between pc/workstation & internet/enterprise network
- for both home or corporate use
- typically is software module on pc
- can be housed in router that connects all home computers to a dsl, cable modem, or other internet interface
- typically much less complex than server based or standalone firewalls
- primary role: deny unauthorized remote access
- may also monitor outgoing traffic to detect & block worms & malware activityj

### firewall topologies

- host-resident
  - includes personal & server firewalls
- screening router
  - single router between internal & external networks with stateless or full packet filtering
- single bastion inline
  - single firewall device between internal & external router
- single bastion T
  - has third network interface on bastion to a dmz where externally visible servers are placed
- double bastion inline
  - dmz sandwiched between bastion firewalls
- double bastion T
  - dmz on separate network interface on bastion firewall
- distributed firewall config
  - used by large businesses & govt orgs

## intrusion prevention systems (ips)

### ips

- aka intrusion detection & prevention systems (idps)
- is extension of ids that includes capability to attempt to block or prevent detected malicious activity
- can be host based, network based, or distributed/hybrid
- can use anomaly detection to identify behavior from illegitimate users, or signature/heuristic detection to identify known malicious behavior
- can block traffic like a firewall, but makes use of ids algorithms to determine when to do so

### host based ips (hips)

- can make use of either signature/heuristic or anomaly detection techniques to identify attacks
  - signature: focus on specific content of app network traffic, or of sequences of system calls, looking for patterns that have been identified as malicious
  - anomaly: look for behavior patterns that indicate malware
- examples of types of malicious behavior addressed by hips
  - modification of system resources
  - privilege escalation
  - buffer overflow
  - access to email contact list
  - dir traversal
- capability can be tailored to specific platform
- set of general purpose tools may be used for a desktop or server
- some packages designed to protect specific types of servers, such as web servers & db servers
  - in this case, hips looks for particular app attacks
- can use sandbox approach
  - sandboxes especially suited to mobile code such as java applets & scripting languages
  - hips quarantines such code in an isolated area, then runs code & monitors its behavior
- areas for which hips typically offers desktop protection
  - system calls
  - fs access
  - system registry settings
  - host i/o

### role of hips

- many industry observers see enterprise endpoint, including desktops & laptops, as now main target for hackers & criminals
  - thus security vendors focus more on developing endpoint security products
  - traditionally, endpoint security has been provided by collection of distinct products, such as antivirus, antispyware, antispam, & personal firewalls
- approach is effort to provide an integrated, single-product suite of functions
  - advantages of integrated hips approach
    - various tools work closely together
    - threat prevention more comprehensive
    - mgmt easier
- a prudent approach is to use hips as 1 element in a defense in depth strategy that involves network level devices, such as firewalls or network based ips

### network based ips (nips)

- inline nids with authority to modify/discard packets & break tcp connections
- makes use of signature/heuristic detection & anomaly detection
- may provide flow data protection
  - requires app payload in a sequence of packets to be reassembled
- methods used to identify malicious packets
  - pattern matching
  - stateful matching
  - protocol anomaly
  - traffic anomaly
  - statistical anomaly

### digital immune system

- comprehensive defense against malicious behavior caused by malware
- developed by ibm & refined by symantec
- motivation for this development includes rising threat of internet based malware, increasing speed of its propagation provided by internet, & need to acquire a global view of situation
- success depends on ability of malware analysis system to detect new & innovative malware strains

### snort inline

- enables snort to function as ips
- includes replace option which allows snort user to modify packets rather than drop them
  - useful for honeypot implementation
  - attackers see failure but cannot figure out why it occurred
- drop
  - snort rejects packet based on options defined in rule & logs result
- reject
  - packet rejected, result logged, & error message returned
- sdrop (silent drop)
  - packet rejected but not logged
