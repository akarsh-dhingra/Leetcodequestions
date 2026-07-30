# Write your MySQL query statement below
SELECT c.name as Customers
FROM CUSTOMERS AS C
LEFT JOIN ORDERS AS O
ON C.id=O.customerId
WHERE O.id IS NULL