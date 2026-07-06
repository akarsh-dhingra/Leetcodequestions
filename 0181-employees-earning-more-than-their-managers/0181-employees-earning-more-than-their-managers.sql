-- Write your PostgreSQL query statement below
-- Find Employees who earn more than their managers 

SELECT m.name as Employee
FROM Employee as m
JOIN Employee as e
ON m.managerId=e.id
WHERE m.salary>e.salary