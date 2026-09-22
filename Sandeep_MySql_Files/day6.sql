
use company_db;
SELECT * FROM employees;

SELECT emp_name
FROM employees
WHERE emp_id = (
SELECT emp_id
FROM employees
WHERE city_name = 'Delhi'
);