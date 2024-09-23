# chapter 5 - db & data center security

## db security

### reasons db security hasn't kept pace with increased reliance on dbs

- increasing reliance on cloud tech to partially or completely host corporate db
- drastic imbalance between complexity of modern db mgmt systems (dbms) & security technique used to protect these critical systems
- complex, sophisticated interaction protocol (sql)
- effective db security requires strategy based on a full understanding of security vulnerabilities of sql
- typical organization lacks full-time db security personnel
- most enterprise environments consist of a heterogeneous mixture of db, enterprise, & os platforms -> more complexity hurdles for security personnel

### dbs

- structured collection of data stored for use by 1+ apps
- contains relationships between data items & groups of data items
- can sometimes contain sensitive data that needs to be secured
- query language
  - provides uniform interface to db for users & apps
- dbms
  - suite of programs for constructing & maintaining db
  - offers ad-hoc query facilities to multiple users & apps

### relational dbs

- table of data consisting of rows & cols
  - each col holds a particular type of data
  - each row contains a specific value for each col
  - ideally has 1 col where all values are unique, forming a key for that row
- enables creation of multiple tables linked together by unique identifier present in all tables
- use relational query language to access db

### relational db elements

- relation - table/file
- tuple - row/record
- attribute - col/field
- primary key
  - unique key identifies row
  - consists of 1+ column names
- foreign key
  - links 1 table to attrs in another
- view/virtual table
  - result of a query that returns selected rows & cols from 1+ tables
  - views often used for security purposes

### sql

- standardized language to define schema, manipulate & query data in a relational db
- several similar versions of ansi/iso standard
- all follow same basic syntax & semantics
- statements used to
  - create tables
  - insert & delete data in tables
  - create views
  - retrieve data with query statements

### sql injection attacks (sqli)

- one of the most prevalent & dangerous network-based security threats
- designed to exploit the nature of web app pages
- sends malicious sql commands to db server
- most common attack goal is bulk extraction of data
- depending on environment, sql injection can be exploited to
  - modify/delete data
  - execute arbitrary os commands
  - launch dos attacks
- typically works by prematurely terminating a text string & appending a new command

### sqli attack avenues

- user input
- server variables
  - attackers can forge values placed in http/network headers & exploit this vulnerability by placing data directly into headers
- second-order injection
  - relies on data already present in db to trigger an sql injection attack, so when attack occurs, input that modifies query to cause an attack comes from system itself rather than user
- cookies
  - attackers can alter cookies so that when the app server builds an sql query based on cookie content, structure & function of query modified
- physical user input
  - applying user input that constructs an attack outside realm of web requests

### inband attacks

- uses same comms channel for injecting sql & retrieving results
- retrieved data presented directly in app web page
- includes
  - tautology
    - injects code in 1+ conditionals so that they're always true
  - end-of-line (eol) comment
    - after injecting code from a particular field, legit code that follows are nullified through usage of eol comments
  - piggybacked queries
    - attacker adds more queries beyond intended query, piggybacking attack on top of legit request

### inferential attack

- no transfer of data, but attacker is able to reconstruct info by sending particular requests & observing resulting behavior of website/db server
- includes
  - illegal/logically incorrect queries
    - lets attacker gain important info about web app's db's structure & type
    - preliminary, info-gathering step
  - blind sql injection
    - allows attackers to infer data present in db even when system is sufficiently secure to not display any erroneous info to user

### out-of-band attack

- data retrieved using a different channel
- can be used when there are limits on info retrieval, but outbound connectivity from db server is lax

### sqli countermeasures

- defensive coding
  - manual defensive coding practices
  - parameterized query insertion
  - sql dom
- detection
  - signature based
  - anomaly based
  - code analysis
- run-time prevention
  - check queries at runtime to see if they conform to a model of expected queries

### db access control (dbac)

- dbac system determines user's access rights
- can support several admin policies
  - centralized admin
    - small number of privileged users can grant/revoke access rights
  - ownership-based admin
    - creator of table may grant & revoke access rights to table
  - decentralized admin
    - owner of table may grant & revoke authorization rights to other users, allowing them to grant & revoke access rights to table

### sql access controls

- 2 commands for managing access rights
  - grant
    - used to grant access rights/can be used to assign user to role
  - revoke
    - revokes access rights/roles
- typical access rights
  - select
  - insert
  - update
  - delete
  - references

### rbac

- rbac eases admin burden & improves security
- db rbac needs to provide these capabilities
  - create/delete roles
  - define permissions for a role
  - assign & cancel assignment of users to roles
- categories of db suers
  - app owner
    - end user who owns db objects as part of app
  - end user
    - operates on db objects via a particular app but doesn't own any db objects
  - admin
    - user who has admin responsibility for part/all of db

### inference detection

- some inference detection algorithm needed for these
- 2 approaches
  - inference detection during db design
    - approach removes an inference channel by altering db structure or changing access control regime
    - techniques in this category often result in unnecessarily stricter access controls that reduce availability
  - inference detection at query time
    - approach seeks to eliminate an inference channel violation during queries
    - if inference channel detected, query denied/altered

### db encryption

- db typically most valuable info resource for any org
  - protected by multiple layers of security
    - firewalls, authentication, general access control systems, db access control systems, db encryption
    - encryption becomes last line of defense in db security
  - can be applied to entire db, at record level, attr level, or field level
