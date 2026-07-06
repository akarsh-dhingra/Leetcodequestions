SELECT t1.id
FROM Weather as t1
JOIN Weather as t2
ON t1.recordDate=t2.recordDate+ INTERVAL '1 days'
WHERE t1.temperature>t2.temperature
