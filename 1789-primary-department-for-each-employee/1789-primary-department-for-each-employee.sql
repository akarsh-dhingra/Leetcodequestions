-- that when an employee belongs to only one department, their primary column is 'N'.
SELECT
    e.employee_id,
    CASE
        WHEN COUNT(*) = 1 THEN MAX(department_id)
        ELSE MAX(
            CASE
                WHEN primary_flag = 'Y'
                THEN department_id
            END
        )
    END AS department_id
FROM Employee AS e
GROUP BY e.employee_id;