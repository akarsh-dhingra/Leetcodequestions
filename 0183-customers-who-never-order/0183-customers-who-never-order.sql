SELECT c.name as Customers
FROM customers as c
LEFT JOIN ORDERS as o
ON c.id=o.customerId
WHERE o.customerId IS null
