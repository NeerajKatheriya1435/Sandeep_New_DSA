-- create database rohit;

-- use rohit;

-- create table students(
-- id integer,
-- name varchar(30),
-- email varchar(30),
-- weight float
-- )

-- insert into students (id,name,email,weight)
-- value (101,"Rohan","rohan@rohan.com",53.78);


-- insert into students (id,name,email,weight) values 
-- (102,"Shiva","shiva@shiva.com",63.78),
-- (103,"Mohan","mohan@mohan.com",87.73),
-- (104,"Radha","radha@radha.com",45.72),
-- (105,"Sandeep","sandeep@sandeep.com",78.94);

-- select * from students;
-- select name as "Student Name",email as "Gmail" from students;

-- SET SQL_SAFE_UPDATES = 0;

-- update students
-- set name="Sohan"
-- where id=103;

-- select * from students;

-- delete from students
-- where id=105;

-- use sajidsir;
-- drop table std;
-- drop database sajidsir;

use sandeep;

create table employee(
id integer primary key,
name varchar(30) not null,
email varchar(30) unique,
age int check (age>18),
status varchar(20) default "Not Active",
department varchar(20),
city varchar(15)
);

select * from employee;

-- insert into employee(id,name,email,age,department,city,status) values
-- (101,"Shiva","shiva@gmail.com",45,"HR","Noida","Active");

-- insert into employee(id,name,email,age,department,city) values
-- (102,"Riya","riya@gmail.com",78,"HR","Hardoi");

INSERT INTO employee (id, name, email, age, status, department, city) VALUES
(1, 'Rahul Sharma', 'rahul@gmail.com', 25, 'Active', 'IT', 'Delhi'),
(2, 'Priya Singh', 'priya@gmail.com', 28, 'Active', 'HR', 'Noida'),
(3, 'Amit Kumar', 'amit@gmail.com', 32, 'Not Active', 'Finance', 'Bareilly'),
(4, 'Neha Verma', 'neha@gmail.com', 24, 'Active', 'IT', 'Lucknow'),
(5, 'Rohit Gupta', 'rohit@gmail.com', 35, 'Active', 'Sales', 'Delhi'),
(6, 'Anjali Sharma', 'anjali@gmail.com', 27, 'Not Active', 'Marketing', 'Noida'),
(7, 'Vikas Yadav', 'vikas@gmail.com', 22, 'Active', 'IT', 'Bareilly'),
(8, 'Pooja Mishra', 'pooja@gmail.com', 30, 'Active', 'HR', 'Lucknow'),
(9, 'Suresh Kumar', 'suresh@gmail.com', 42, 'Not Active', 'Finance', 'Delhi'),
(10, 'Kavita Singh', 'kavita@gmail.com', 26, 'Active', 'Sales', 'Agra'),
(11, 'Arjun Mehta', 'arjun@gmail.com', 29, 'Active', 'IT', 'Mumbai'),
(12, 'Sneha Kapoor', 'sneha@gmail.com', 31, 'Not Active', 'HR', 'Delhi'),
(13, 'Manish Tiwari', 'manish@gmail.com', 38, 'Active', 'Finance', 'Noida'),
(14, 'Riya Gupta', 'riya11@gmail.com', 23, 'Active', 'Marketing', 'Bareilly'),
(15, 'Deepak Singh', 'deepak@gmail.com', 45, 'Not Active', 'Sales', 'Lucknow'),
(16, 'Simran Kaur', 'simran@gmail.com', 27, 'Active', 'IT', 'Chandigarh'),
(17, 'Nitin Sharma', 'nitin@gmail.com', 34, 'Active', 'Finance', 'Delhi'),
(18, 'Komal Verma', 'komal@gmail.com', 21, 'Not Active', 'HR', 'Agra'),
(19, 'Rakesh Gupta', 'rakesh@gmail.com', 40, 'Active', 'Sales', 'Mumbai'),
(20, 'Ayesha Khan', 'ayesha@gmail.com', 29, 'Active', 'Marketing', 'Noida'),
(21, 'Karan Malhotra', 'karan@gmail.com', 36, 'Not Active', 'IT', 'Lucknow'),
(22, 'Shivani Joshi', 'shivani@gmail.com', 25, 'Active', 'HR', 'Bareilly'),
(23, 'Mohit Agarwal', 'mohit@gmail.com', 33, 'Active', 'Finance', 'Agra'),
(24, 'Divya Chauhan', 'divya@gmail.com', 28, 'Not Active', 'Marketing', 'Delhi'),
(25, 'Varun Saxena', 'varun@gmail.com', 41, 'Active', 'IT', 'Mumbai'),
(26, 'Nisha Patel', 'nisha@gmail.com', 22, 'Active', 'Sales', 'Noida'),
(27, 'Abhishek Jain', 'abhishek@gmail.com', 37, 'Not Active', 'Finance', 'Chandigarh'),
(28, 'Swati Agarwal', 'swati@gmail.com', 26, 'Active', 'HR', 'Lucknow'),
(29, 'Gaurav Bansal', 'gaurav@gmail.com', 44, 'Active', 'Marketing', 'Delhi'),
(30, 'Tanvi Srivastava', 'tanvi@gmail.com', 24, 'Not Active', 'IT', 'Bareilly');

