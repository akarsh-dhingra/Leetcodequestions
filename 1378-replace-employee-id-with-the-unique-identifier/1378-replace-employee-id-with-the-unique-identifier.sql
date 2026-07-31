SELECT a.unique_id , e.name as name
FROM Employees as e
LEFT JOIN EmployeeUNI as a
ON e.id=a.id

