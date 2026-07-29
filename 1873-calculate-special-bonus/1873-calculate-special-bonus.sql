-- If the id of employee is an odd number the bouns+=100% else 

SELECT employee_id,
    CASE 
        WHEN employee_id%2=1 AND name not like 'M%'
        THEN SALARY
        ELSE 0
    END AS bonus
FROM EMPLOYEES
ORDER BY employee_id

