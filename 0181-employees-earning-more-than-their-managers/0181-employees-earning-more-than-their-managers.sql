-- Write your PostgreSQL query statement below
-- Find Employees who earn more than their managers 

SELECT e.name as employee
FROM Employee as e
JOIN Employee as m
ON e.managerId=m.id
WHERE e.salary>m.salary