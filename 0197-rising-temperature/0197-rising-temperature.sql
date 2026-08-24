SELECT t.id
FROM Weather as t 
JOIN Weather as s
ON t.recordDate=s.recordDate + INTERVAL 1 DAY

WHERE t.temperature>s.temperature