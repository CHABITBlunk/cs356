# access control

### access control principles

- in a broad sense, all computer security is concerned with access control
- rfc 4949 defines computer security as "measures that implement & assure security services in a computer system, particularly those that assure access control service"

### access control policies

- discretionary access control (dac)
  - controls access based on identity of requestor & on access rules (authorizations) stating what requestors are allowed to do
- mandatory access control (mac)
  - controls access based on comparing security labels with security clearances
- role-baesd access control (rbac)
  - controls access based on roles that users have within system & on rules stating what accesses are allowed to users in given roles
- attribute-based access control (abac)
  - controls accss based on attributes of user, resource to be accessed, & current environmental conditions

### subjects, objects, & access rights

- subject
  - entity capable of accessing objects
  - 3 classes: owner, group, world
- object
  - resource to which access is controlled
  - entity used to contain &/ receive information
- access right
  - describes way in which a subject may access an object
  - includes
    - read
    - write
    - execute
    - delete
    - create
    - search
    - ownership

### discretionary access control (dac)

- scheme in which an entity may be granted access rights that permit entity, by its own volition, to enable another entity to access some resource
- often provided using access matrices
  - 1 dimension consists of identified subjects that may attempt data access to resources
  - other dimension lists objects that may be accessed
- each entry in matrix indicates access rights of particular subject for particular object

### protection domains

- set of objects together with access rights to those objects
- offers more flexibility when associating capabilities
- in terms of access matrix, a row defines a protection domain
- user can spawn procs with a subset of its access rights
- association between proc & domain can be static or dynamic
- in user mode, certain areas of mem are protected from use - certain instructions may not be executed
- in kernel mode, privileged instructions may be executed - protected areas of mem may be accessed

### unix file access control

- files administered using inodes (index nodes)
  - control structures with key info needed for particular file
  - several file names may be associated with 1 inode
  - an active inode is associated with exactly 1 file
  - file attrs, permissions, & control info are stored in inode
  - disk has inode table/list that contains all inodes of all files in fs
  - when file is opened, its inode is brought into main mem, then stored in a mem-resident inode table
- dirs stored in hierarchical tree
  - may contain files &/ other dirs
- unique user id
- member of primary group identified by group id
- belongs to specific group
- 12 protection bits
  - specify rwx for owner, group, all other users
- owner id, gid, & protection bits are part of file's inode

### traditional unix file access control

- set user id (setuid)
- set group id (setgid)
  - system temporarily uses rights of file owner/group in addition to real user's rights when making access control decisions
  - enables privileged programs to access files/resources not generally accessible
- sticky bit
  - when applied to dir, it specifies that only the owner of any file in the dir can rename, move, or delete that file
- superuser
  - is exempt from usual access control restrictions
  - has system-wide access

### access control lists (acls) in unix

- modern unix-like systems support acls
  - e.g. freebsd, openbsd, linux, solaris
- freebsd
  - `setfacl` assigns a list of unix uids & gids
  - any number of users & groups can be associated with a file
  - rwx protection bits
  - a file doesn't need to have an acl
  - includes additional protection bit that indicates whether file has extended acl
- when proc requests access to a fs object, 2 steps are required
  1. select most appropriate acl
  2. check if matching entry contains sufficient permissions

### role-based access control (rbac)

- very similar to dac, but the user dimension of the matrix is replaced with roles that can be assigned or are based on sessions

### constraints - rbac

- provide a means of adopting rbac to the specifics of administrative & security policies of an org
- a defined relationship among roles or a condition related to roles
- types
  - mutually exclusive
    - a user can only be assigned to one role in the set (either during a session or statically)
    - any permission can be granted to only 1 role in the set
  - cardinality
    - setting a maximum number wrt roles
  - prerequisite roles
    - dictates that a user can only be assigned to a particular role if it is already assigned to some other specified role

### attribute-based access control (abac)

- can define authorizations that express conditions on properties of both resource and subject
- strength is in flexibility & expressive power
- main obstacle to its implementation is concerns about performance wrt evaluating predicates on both resource & user properties for each access
- web services have been pioneering technologies through the introduction of xamcl (extensive access control markup language)
- considerable interest in cloud applications

### abac attributes

- subject attrs
  - subject is active entity that causes info to flow among objects or changes in system state
  - attrs define identity & characteristics of subject
- object attrs
  - object (resource) is a passive info system-related entity containing/receiving info
  - objects have attrs that can be leverages to make access control decisions
- environment attrs
  - describe operational, technical, & situational environment/context in which info access occurs
  - so far largely ignored in most access control policies

### abac merits

- distinguishable because it controls access to objects by evaluating rules against attrs of entities, operations, & environment relevant to request
- relies upon evaluation of attrs of subject, object, & formal relationship/access control rule defining allowable operations for subject-object attr combinations in a given environment
- systems are capable of enforcing dac, rbac, & mac concepts
- allows unlimited number of attrs to be combined to satisfy any access control rule

### abac policies

- a policy is a set of rules & relationships that govern allowable behavior within org, based on privileges of subjects & how resources are to be protected under which environment conditions
- typically written from perspective of object that needs protecting & privileges available to subjects
- privileges represent authorized behavior of subject & are defined by an authority & embodied in policy

### identity, credential, & access mgmt (icam)

- a comprehensive approach to managing & implementing digital identities, credentials, & access control
- developed by us govt
- designed to
  - create trusted digital identity representations of individuals & nonperson entities (npes)
  - bind those identities to credntials that may serve as proxy for individual or npe in access transactions
  - use credentials to provide authorized access to an agency's resources

### identity mgmt

- concerned with assigning attrs to a digital identity & connecting that digital identity to an individual or npe

### credential mgmt

- mgmt of life cycle of credential
  - e.g. smart cards, private/public keys, digital certs
- encompasses 5 logical components
  - an authorized individual sponsors an individual for a credential to establish the need for the credential
  - sponsored individual enrolls for credential
  - credential produced
  - credential issued to individual
  - credential must be maintained over its life cycle

### support elements needed for enterprise-wide access control facility

- resource mgmt
  - rules would include credential requirements & what user attrs, resource attrs, & environmental conditions are required for access
- privilege mgmt
- policy mgmt

### identity federation

- term used to describe the technology, standards, policies, & procs that allow an org to trust digital identities, identity attrs, & credentials created & issued by another org
- addresses 2 questions
  - how do you trust identities of individuals from external orgs who need access to your systems
  - how do you vouch for identities of individuals in your org when they need to collaborate with external orgs

### open id trust framework

- openid
  - open standard that allows users to be authenticated by cooperating sites using a third party service
- oidf (openid foundation)
  - international nonprofit committed to enabling, promoting, & protecting openid tech
- icf (info card foundation)
  - nonprofit working to evolve the info card ecosystem
- oitf (open id trust framework)
  - standardized, open spec of a trust framework for id & attr exchange, develpoed by oidf & icf
- oix (open id exchange)
  - independent, international provider of cert trust frameworks conforming to oitf model
- axn (attr exchange network)
  - online internet-scale gateway for id service providers & relying parties to efficiently access user asserted, permissioned, & verified online id attrs in high volumes at affordable costs
