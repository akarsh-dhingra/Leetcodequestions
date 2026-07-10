SELECT s.user_id ,ROUND((COUNT(CASE WHEN c.action = 'confirmed' THEN 1 END) * 1.0) / COUNT(s.user_id),2) AS confirmation_rate
FROM Signups as s
LEFT JOIN Confirmations as c
ON s.user_id=c.user_id
GROUP BY s.user_id;


