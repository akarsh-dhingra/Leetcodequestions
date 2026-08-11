# Write your MySQL query statement below

SELECT e.employee_id
FROM employees as e
WHERE e.salary <30000
AND e.manager_id IS NOT NULL
AND NOT EXISTS (SELECT 1 from EMPLOYEES m WHERE m.employee_id = e.manager_id )
ORDER BY e.employee_id