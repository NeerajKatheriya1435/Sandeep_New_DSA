
-- create database mybank;

-- use mybank;

-- CREATE TABLE accounts (
--     acc_id INT PRIMARY KEY,
--     name VARCHAR(50) NOT NULL,
--     balance DECIMAL(10,2) NOT NULL
-- );

-- INSERT INTO accounts (acc_id, name, balance) VALUES
-- (101, 'Rahul', 50000.00),
-- (102, 'Amit', 30000.00),
-- (103, 'Priya', 45000.00),
-- (104, 'Neha', 25000.00),
-- (105, 'Vikas', 60000.00);

-- select * from accounts;

-- start transaction;

-- update accounts
-- set balance=balance-20000
-- where acc_id=102;

-- update accounts
-- set balance=balance+20000
-- where acc_id=105;

-- commit;

-- select * from accounts

-- START TRANSACTION;

-- UPDATE accounts
-- SET balance = balance - 10000
-- WHERE acc_id = 105;
-- commit;
-- select * from accounts

-- ROLLBACK;
-- select * from accounts;

-- START TRANSACTION;

-- UPDATE accounts SET balance = balance - 20000 WHERE acc_id = 105;
-- SAVEPOINT sp1;
-- UPDATE accounts SET balance = balance + 20000 WHERE acc_id = 102;

-- ROLLBACK TO sp1;
-- COMMIT;
