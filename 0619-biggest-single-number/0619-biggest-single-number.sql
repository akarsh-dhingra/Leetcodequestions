SELECT MAX(s.num) as num
FROM (
SELECT num
FROM MyNumbers  
GROUP BY num
HAVING COUNT(NUM)=1
) as s
