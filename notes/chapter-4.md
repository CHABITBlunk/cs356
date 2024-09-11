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
- often provided using access matrix
  - 1 dimension consists of identified subjects that may attempt data access to resources
  - other dimension lists objects that may be accessed
- each entry in matrix indicates access rights of particular subject for particular object
