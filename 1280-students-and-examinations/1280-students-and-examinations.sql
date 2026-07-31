SELECT z.student_id,z.student_name, z.subject_name,COUNT(e.subject_name) as attended_exams
FROM(
SELECT *
from Students
CROSS JOIN Subjects 
) as z
LEFT JOIN Examinations as e
ON z.student_id=e.student_id AND z.subject_name=e.subject_name
GROUP BY z.student_name,z.subject_name,z.student_id
ORDER BY
    z.student_id,
    z.subject_name;
-- SELECT *
-- FROM (
-- SELECT *
-- from Students
-- CROSS JOIN Subjects 
-- ) as z
-- LEFT JOIN Examinations AS c
-- ON z.student_id=c.student_id
-- GROUP BY c.subject_name
