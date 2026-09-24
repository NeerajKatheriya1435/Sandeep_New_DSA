-- CREATE DATABASE join_practice;
-- USE join_practice;

-- CREATE TABLE customers (
--     customer_id INT PRIMARY KEY,
--     customer_name VARCHAR(50) NOT NULL,
--     city VARCHAR(30),
--     email VARCHAR(50) UNIQUE
-- );

-- CREATE TABLE products (
--     product_id INT PRIMARY KEY,
--     product_name VARCHAR(50) NOT NULL,
--     category VARCHAR(30),
--     price DECIMAL(10,2)
-- );

-- CREATE TABLE orders (
--     order_id INT PRIMARY KEY,
--     customer_id INT,
--     product_id INT,
--     quantity INT,
--     order_date DATE,

--     FOREIGN KEY (customer_id) REFERENCES customers(customer_id),
--     FOREIGN KEY (product_id) REFERENCES products(product_id)
-- );

INSERT INTO customers VALUES
(1, 'Rahul', 'Bareilly', 'rahul@gmail.com'),
(2, 'Aman', 'Delhi', 'aman@gmail.com'),
(3, 'Priya', 'Lucknow', 'priya@gmail.com'),
(4, 'Neha', 'Noida', 'neha@gmail.com'),
(5, 'Rohit', 'Bareilly', 'rohit@gmail.com'),
(6, 'Sneha', 'Agra', 'sneha@gmail.com'),
(7, 'Vikas', 'Delhi', 'vikas@gmail.com'),
(8, 'Pooja', 'Jaipur', 'pooja@gmail.com');

INSERT INTO products VALUES
(101, 'Laptop', 'Electronics', 55000),
(102, 'Mobile', 'Electronics', 25000),
(103, 'Keyboard', 'Accessories', 1500),
(104, 'Mouse', 'Accessories', 800),
(105, 'Monitor', 'Electronics', 12000),
(106, 'Headphones', 'Accessories', 2500),
(107, 'Printer', 'Electronics', 15000),
(108, 'Webcam', 'Accessories', 3500);

INSERT INTO orders VALUES
(1001, 1, 101, 1, '2026-09-01'),
(1002, 1, 103, 2, '2026-09-02'),
(1003, 2, 102, 1, '2026-09-03'),
(1004, 3, 105, 2, '2026-09-04'),
(1005, 4, 104, 3, '2026-09-05'),
(1006, 5, 106, 1, '2026-09-06'),
(1007, 2, 107, 1, '2026-09-07'),
(1008, 6, 102, 2, '2026-09-08'),
(1009, 7, 108, 1, '2026-09-09'),
(1010, 3, 103, 1, '2026-09-10'),
(1011, 5, 105, 1, '2026-09-11'),
(1012, 1, 104, 2, '2026-09-12');

-- select * from orders;

-- SELECT o.order_id,c.customer_name, p.product_name,o.quantity,p.category
-- FROM customers c
-- JOIN orders o
-- ON c.customer_id = o.customer_id
-- JOIN products p
-- ON o.product_id = p.product_id;

-- USE join_practice;
-- select * from customers;

select order_id, product_id
from orders
where product_id in (
select product_id
from products
where category="Electronics");
