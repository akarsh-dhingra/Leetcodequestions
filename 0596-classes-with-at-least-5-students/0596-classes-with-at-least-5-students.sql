SELECT class 
FROM Courses as c
GROUP BY class
HAVING count(student)>=5