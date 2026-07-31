# Write your MySQL query statement below
SELECT p.project_id,ROUND(avg(e.experience_years),2) as average_years
FROM Project AS p
LEFT JOIN Employee as e
ON p.employee_id=e.employee_id
group by p.project_id

