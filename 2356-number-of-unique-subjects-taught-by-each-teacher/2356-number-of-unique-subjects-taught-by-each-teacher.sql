SELECT t.teacher_id , COUNT(distinct(t.subject_id)) as cnt 
FROM Teacher as t
GROUP BY t.teacher_id