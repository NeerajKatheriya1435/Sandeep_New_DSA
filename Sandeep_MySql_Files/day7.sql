-- SELECT * FROM company_db.employees;
-- use join_practice;

-- select * from orders;

-- select order_id
-- from orders o
-- where exists (
-- select 1
-- from products p
-- where o.product_id=p.product_id
-- );

-- select order_id
-- from orders o
-- where not exists (
-- select 1
-- from products p
-- where o.product_id=p.product_id
-- );

-- use company_db;
-- select * from employees;

-- select department, sum(salary) as "Total salary"
-- from employees
-- group by department;

select city, sum(salary) as "Total salary"
from employees
group by city
having sum(salary)>200000 and sum(salary)<300000;
