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
- can sometimes contian sensitive data that needs to be secured
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
