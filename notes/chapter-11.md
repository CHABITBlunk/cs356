# chapter 11

## software security

### security flaws

- critical web app security flaws include 5 related to insecure code
  - unvalidated input
  - cross-site scripting
  - buffer overflow
  - injection flaws
  - improper error handling
- occur as consequence of insufficient checking & validation of data & error codes in programs
- awareness of these issues is critical initial step in writing more secure program code
- emphasis should be placed on need for devs to address these known areas of concern

### reducing software vulnerabilities

- nist recommendations
  - use improved methods for specifying & building software to stop vulnerabilities before they occur
  - use better & more efficient testing techniques to find vulnerabilities before they can be exploited
  - build more resilient architectures to reduce impact of vulnerabilities

### software security, quality, & readability

- quality & readability
  - concerned with accidental failure of program as result of some theoretically random, unanticipated input, system interaction, or use of incorrect code
  - improve using structured design & testing to identify & eliminate as many bugs as possible from program
  - concern is not how many bugs, but how often they are triggered
- software security
  - attacker chooses profitability distribution, specifically targeting bugs that result in a failure that can be exploited by attacker
  - triggered by inputs that differ dramatically from what is usually expected
  - unlikely to be identified by common testing approaches

### defensive programming

- designing & implementing software so that it continues to function even when under attack
- requires attention to all aspects of program execution, environment, & type of data it processes
- software able to detect erroneous conditions resulting from some attack
- aka secure programming
- key rule is to never assume anything, check all assumptions & handle any possible error states
- programmers often make assumptions about type of inputs a program will receive & environment in which it executes
  - assumptions need to be validated by program & all potential features handled gracefully & safely
- requires changed mindeset to traditional programming practices
  - programmers must understand how failures can occur & steps needed to reduce chance of them occuring in their programs
- conflicts with business pressures to keep development times as short as possible to maximize market advantage

### security by design

- security & reliability are common design goals in most engineering disciplines
- software development not as mature
- recent years have seen increasing efforts to improve secure software development processes
- software assurance forum for excellence in code (safecode)
  - develop publications outlining industry best practices for software assurance & providing practical advice for implementing proven methods for secure software development

### handling program input

- incorrect handling very common
- input is any source of data from outside & whose value is not explicitly known by programmer when code was written
- must identify all data sources
- explicitly validate assumptions on size & type of values before use

### input size & buffer overflow

- programmers often make assumptions about max expected size of input
  - allocated buffer size not confirmed -> buffer overflow
- testing may not identify vulnerability
  - test inputs unlikely to include large enough inputs to trigger overflow
- safe coding treats all input as dangerous

### interpretation of program input

- program input may be binary or text
  - binary interpretation depends on encoding, usually app specific
- increasing variety in charsets used
  - care needed to identify which set is being used & what chars are being read
- failure to validate may result in exploitable vulnerability
- 2014 heartbleed openssl bug is recent example of failure to check validity of binary input value

### injection attacks

- flaws relating to invalid handling of input data, specifically when program input data can influence flow of execution of program
- most often occur in scripting languages
  - encourage reuse of other programs & system utilities where possible to save coding effort
  - often used as web cgi scripts

### cross-site scripting (xss) attacks

- attacks where input provided by one used is subsequently output to another user
- commonly seen in scripted web apps
  - vulnerability involves inclusion of script code into html content
  - script code may need to access data associated with other pages
  - browsers impose security checks & restrict data access to pages originating from same site
- exploit assumption that all content from one site is equally trusted, hence permitted to interact with other content from site
- xss reflection vulnerability
  - attacker includes malicious script content in data supplied to site

### validating input syntax

- necessary to ensure that data conform with any assumptions made about data before subsequent use
- input data should be compared against what is wanted
- alternative is to compare input data with known dangerous values
- by only accepting known safe data, program more likely to remain secure

### alternate encodings

- may have multiple means of encoding text
- growing requirement to support users around globe & to interact with them using their own lanugages
- unicode used for internationalization
  - uses 16-bit value for chars
  - utf-8 encodes as 1-4 byte sequences
  - many unicode decoders accept any valid equivalent sequence
- canonicalization
  - transforming input data into single, standard, minimal representation
  - once this is done, input data can be compared with single representation of acceptable input values
