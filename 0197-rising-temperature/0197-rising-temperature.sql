SELECT t.id
FROM Weather as t
JOIN Weather as y
ON t.recordDate=y.recordDate + INTERVAL 1 DAY 
where t.temperature> y.temperature


