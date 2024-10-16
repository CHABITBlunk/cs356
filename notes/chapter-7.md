# denial of service attacks

### dos

- an action that prevents/impairs authorized use of networks, systems, or apps by exhausting resources such as cpu, ram, storage, &c
- form of attack on availability of service
- categories of resources that can be attacked
  - network bandwidth
    - relates to capacity of network links connecting a server to internet
    - for most organizations, this is their connection to the isp
  - system resources
    - aims to overload/crash network handling software
  - app resources
    - typically involves a number of valid requests, each of which consumes significant resources, thus limiting ability of server to respond to requests from other users

### classic dos attacks

- flooding ping command
  - aim of attack is to overwhelm capacity of network connection to target organization
  - traffic can be handled by higher capacity links on path, but packets are discarded as capacity decreases
  - source of attack clearly identified unless spoofed addr is used
  - network performance notably affected

### source addr spoofing

- use forged source addr usually via raw socket interface on os's
  - makes attacking systems harder to identify
- attacker generates large volumes of packets that have target system as destination addr
- router connected to final, lower capacity link will get congested
- requires network engineers to specifically query flow info from their routers
- backscatter traffic - advertise routes to unused ip addrs to monitor attack traffic

### syn spoofing

- most common dos attack
- attacks availability of server to respond to tcp connection requests by overflowing tables used to manage them -> legit users are denied from server
- attack on system resources, specifically network handling code in os

### flooding attacks

- classified based on network protocol used
- intent is to overload network capacity on some link to a server
- virtually any type of network packet can be used
- types
  - icmp flood
    - ping flood using icmp echo request packets
    - traditionally, network admins allow such packets into their network because ping is useful
  - udp flood
    - uses udp packets delivered to same port number on target system
  - tcp syn flood
    - sends tcp packets to target system
    - total volume of packets is aim of attack rather than system code

### ddos

- use of multiple systems to generate attacks
- typically done using a botnet

### http based attacks

- http flood
  - attack that bombards web servers with http requests
  - consumes considerable resources
  - spidering
    - bots starting from given http link & following all links on provided web site in a recursive way
- slowloris
  - attempts to monopolize by sending http requests that never complete
  - eventually consumes web server's connection capacity
  - uses legit http traffic
  - existing intrusion detection & prevention solutions that rely on signatures to detect attacks will generally not recognize slowloris

### reflection attacks

- attacker sends packets to known service on intermediary with a spoofed source addr of actual target system
- when intermediary responds, response sent to target
- "reflects" attack off intermediary (reflector)
- goal: generate enough volumes of packets to flood link to target system without altering intermediary
- basic defense against these attacks is blocking packets with spoofed sources

### dns amplification attacks

- use packets directed at legit dns server as intermediary
- attacker creates a series of dns requests containing spoofed source addr of target system
- exploit dns behavior to convert a small request to a much larger response (amplification)
- target flooded with responses
- basic defense against this attack is to prevent use of spoofed source addrs

### dos attack defenses

- can't be prevented entirely
- high traffic volumes may be legit
  - high publicity about specific site
  - activity on very popular site
  - described as slashdotted, flash crowd, or flash event
- 4 lines of defense against ddos
  - attack prevention & preemption
  - attack detection & filtering
  - attack source traceback & identification
  - attack reaction

### dos prevention

- block spoofed source addrs on routers close to source as possible
- filters may be used to ensure path back to claimed source addr is one being used by current packet
  - filters must be applied to traffic before it leaves isp's network or at point of entry to their network
- use modified tcp connection handling code
  - cryptographically encode critical info in a cookie that is sent as server's initial sequence number
    - legit client responds with ack packet containing incremented sequence number cookie
  - drop entry for incomplete connection from tcp connections table when it overflows
- block ip directed broadcasts
- block suspicious services & combinations
- manage app attacks with a type of graphical puzzle (captcha) to distinguish legit human requests
- good general system security practices
- use mirrored & replicated servers when high performance & reliability required

### responding to dos attacks

- good incident response plan
  - details on how to contact technical personnel for isp
  - needed to impose traffic filtering upstream
  - details of how to respond to attack
- antispoofing, directed broadcast, & rate limiting filters should have been implemented
- ideally have network monitors & ids to detect & notify abnormal traffic patterns
- identify type of attack
  - capture & analyze packets
  - design filters to block attack traffic upstream
  - identify & correct system/app bug
- have isp trace packet flow back to source
  - may be difficult & time consuming
  - necessary if planning legal action
- implement contingency plan
  - switch to alt backup servers
  - commisison new servers at new site with new addrs
- update incident response plan
  - analyze attack & response for future handling
