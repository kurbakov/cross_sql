## Cross SQL handler

The implementation of the single interface to access data from different databases and aggregate the data in memory.

### Example:
Let we have the databases A and B.  
The database A has the table 'students':
```sql
create table students as (
id int8,
first_name varchar(64),
last_name varchar(64),
city varchar(64)
);
```

The database B has the table 'lection':
```sql
create table lection as (
id int8,
student_id int8,
lection_name varchar(64),
city varchar(64)
);
```

The goal is to implenet the functionality to aggreagte data from 2 databses.
```sql
Select A.students.first_name, A.students.last_name
From {select * from students;}::A as a
Join {select * from lection;}::B as d
  ON a.id = b.student_id
Where a.city in (‘City 1’, ‘City 2’)
AND b.lection_name = 'my lection name';
```

![alt text](https://github.com/kurbakov/project_z/blob/master/uml_class.png)
