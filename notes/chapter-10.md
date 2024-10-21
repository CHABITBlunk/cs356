# chapter 10

## buffer overflow

### notable attacks

- 2014 - heartbleed
- 2016 - adobe flash player
- 2017 - exquifax data breach, wannacry ransomware attack
- 2018 - meltdown & spectre vulnerabilities
- 2019 - whatsapp voip, capital one data breach
- 2023 - fortinet

### buffer overflow

- very common attack mechanism
  - first widely used by morris worm
- prevention techniques known
- still of major concern
  - legacy of buggy code in widely deployed os's & apps
  - continued careless programming practices by programmers
- definition: a condition at an interface under which more input can be placed into a buffer or data holding area than capacity allocated, overwriting other info

### buffer overflow basics

- programming error when proc attempts to store data beyond limits of fixed-size buffer
- overwrites adjacent mem locations
  - locations could hold other program vars, params, or program control flow data
- buffer could be located on stack, in heap, or in data section of proc
- consequences
  - corruption of program data
  - unexpected transfer of control
  - mem access violations
  - execution of code chosen by attacker

### buffer overflow attacks

- to exploit a buffer overflow, an attacker needs
  - to identify a buffer overflow vulnerability in some program that can be triggered using externally sourced data under attacker's control
  - to understand how that buffer is stored in mem & determine potential for corruption
- identifying vulnerable programs can be done by
  - inspection of program source
  - tracing execution of programs as they process oversized input
  - using tools such as fuzzing to automatically identify potentially vulnerable programs

### programming language history

- at machine level, data manipulated by machine instructions executed by cpu are stored in registers or mem
- asm programmer responsible for correct interpretation of any saved data value
- c & related languages
  - high-level control structures but allow direct access to mem -> vulnerable to buffer overflow
  - have large legacy of widely used, unsafe, hence vulnerable code
- modern high-level languages have strong notion of type & valid operations
  - not vulnerable to buffer overflow
  - does incur overhead, some limits on use

### stack buffer overflows

- occur when buffer located on stack
  - aka stack smashing
  - used by morris worm
  - exploits included an unchecked buffer overflow
- still being widely exploited
- stack frame
  - when one fn calls another, it needs somewhere to save return addr
  - also needs locations to save params to be passed into called fn and to possibly save register values

### shellcode

- code supplied by attacker
  - often saved in buffer being overflowed
  - traditionally transferred control to a shell
- machine code
  - specific to cpu & os
  - traditionally needed good asm skills to create
  - more recently, a number of sites & tools have been developed that automate this
- metasploit
  - provides useful info to people who perform penetration, ids signature development, & exploit research

### stack overflow variants

- target program
  - trusted system utility
  - network service daemon
  - commonly used lib code
- shellcode fns
  - launch remote shell when connected to
  - create reverse shell that connects back to hacker
  - use local exploits that establish a shell
  - flush firewall rules that currently block other attacks
  - break out of chroot environment, giving full access to system

### buffer overflow defenses

- approaches
  - compile-time
    - aim to harden programs to resist attacks in new programs
  - run-time
    - aim to detect & abort attacks in existing programs

## compile-time defenses

### programming language

- use modern high-level language
  - not vulnerable to buffer overflow attacks
  - compiler enforces range checks & permissible operations on vars
- disadvantages
  - additional code must be executed at run time to impose checks
  - flexibility & safety traded for resource use
  - distance from underlying machine language & architecture means that access to some instructions & resources is lost
  - limits usefulness in writing code, such as device drivers, that must interact with such resources

### safe coding techniques

- c designers placed much more emphasis on space efficiency & performance considerations than on type safety
  - assumed programmers would exercise due care in writing code
- programmers need to inspect code & rewrite any unsafe coding
  - e.g. openbsd project
- programmers have audited existing code base, including os, stdlibs, & common utilities
  - result: one of safest os's in widespread use

### language extensions/safe libs

- handling dynamically allocated mem is more problematic because size info not available at compile time
  - requires exstension & use of lib routines
    - programs & libs need to be recompiled
    - likely to have problems with third-party apps
- concern with c is use of unsafe stdlib routines
  - one approach has been to replace these with safer variants
    - e.g. libsafe
    - lib implemented as dynamic lib arranged to load before existing stdlibs

### stack protection

- add fn entry & exit code to check stack for signs of corruption
- use random canary
  - value needs to be unpredictable
  - should be different on different systems
- stackshield & return addr defender (rad)
  - gcc extensions that include additinoal fn entry & exit code
    - fn entry writes copy of return addr to safe region of mem
    - fn exit code checks return addr in stack frame against saved copy
    - if change found, abort program

## run-time defenses

### executable addr space protection

- use vram support to make some regions of mem non-executable
  - requires support from mmu
  - long existed on sparc/solaris systems
  - recent on x86 linux/unix/windows
- issues
  - support for executable stack code
  - special provisions needed

### addr space randomization

- manipulate location of key data structures
  - stack, heap, global data
  - using random shift for each proc
  - large addr range on modern systems means wasting some has negligible impact
- randomize location of heap buffers
- random location of stdlib fns

### guard pages

- place guard pages between critical regions of mem
  - flagged in mmu as illegal addrs
  - any attempted access aborts proc
- further extension places guard pages betwen stack frames & heap buffers
  - cost in execution time to support large number of page mappings necessary

## other overflow techniques

### replacement stack frame

- variant that overwrites buffer & saved frame pointer addr
  - saved frame pointer value changed to refer to dummy stack frame
  - current fn returns to replacement dummy frame
  - control transferred to shellcode in overwritten buffer
- off-by-one attacks
  - coding error that allows 1 more byte to be copied than there is space available
- defenses
  - any stack protection mechanisms to detect mods to stack frame or return addr by fn exit code
  - use non-executable stacks
  - randomization of stack in mem & of system libs

### return to system call

- defenses
  - any stack protection mechanisms to detect mods to stack frame/return addr by fn exit code
  - use non-executable stacks
  - randomization of stack in mem & of system libs
- stack overflow variant replaces return addr with stdlib fn
  - response to non-executable stack defenses
  - attacker constructs suitable params
  - fn returns & lib fn executes
  - attacker may need exact buffer addr
  - can even chain 2 lib calls

### heap overflow

- attack buffer located in heap
  - typically located above program code
  - mem requested by programs to use dynamic data structures (such as linked lists of records)
- no return addr
  - hence no easy transfer of control
  - may have fn pointers can exploit
  - or manipulate mgmt data structures
- defenses
  - making heap non-executable
  - randomizing alloc of mem on heap

### global data overflow

- defenses
  - non-executable or random global data region
  - move fn pointers
  - guard pages
- can attack buffer located in global data
  - may be located above program code
  - if has pointer & vulnerable buffer
  - or adjacent proc mgmt tables
  - aim to overwrite fn pointer later called
