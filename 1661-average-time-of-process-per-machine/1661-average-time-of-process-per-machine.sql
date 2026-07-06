-- I need to group by machine_id
SELECT a.machine_id, 
    ROUND(AVG(e.timestamp-a.timestamp)::NUMERIC,3) as processing_time
FROM ACTIVITY AS a
JOIN ACTIVITY AS e
ON a.machine_id=e.machine_id AND a.process_id=e.process_id
WHERE a.activity_type='start'
AND e.activity_type='end'
GROUP BY a.machine_id