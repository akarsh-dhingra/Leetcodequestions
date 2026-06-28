SELECT u.unique_id,e.name
FROM EmployeeUNI AS u
RIGHT JOIN Employees AS e
ON u.id=e.id