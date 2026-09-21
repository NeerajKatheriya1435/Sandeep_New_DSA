use sandeep;

CREATE TABLE cities (
city_id INT PRIMARY KEY,
city_name VARCHAR(50)
);

-- insert into cities(city_id,city_name) values
-- (101,"Noida"),
-- (102,"Hardoi"),
-- (103,"Delhi"),
-- (104,"Noida"),
-- (106,"Delhi");

-- CREATE TABLE students (
-- roll_no INT PRIMARY KEY,
-- name VARCHAR(50),
-- city_id INT,
-- FOREIGN KEY (city_id) REFERENCES cities(city_id)
-- );

-- insert into students(roll_no,name,city_id) values
-- (1,"Shiva",101),
-- (2,"Rohan",102),
-- (3,"Radha",101),
-- (4,"Mohan",102),
-- (5,"Shiva",104);

-- select * from students;

-- SELECT students.name, cities.city_name,cities.city_id
-- FROM students
-- INNER JOIN cities
-- ON students.city_id = cities.city_id;

-- SELECT students.roll_no, students.name, cities.city_name,cities.city_id
-- FROM students
-- left JOIN cities
-- ON students.city_id = cities.city_id;

-- SELECT students.roll_no, students.name, cities.city_name,cities.city_id
-- FROM students
-- right JOIN cities
-- ON students.city_id = cities.city_id;

-- SELECT students.name, cities.city_name
-- FROM students
-- CROSS JOIN cities;
