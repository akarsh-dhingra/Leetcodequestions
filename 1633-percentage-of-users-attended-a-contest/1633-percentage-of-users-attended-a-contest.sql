SELECT c.contest_id, ROUND((COUNT(c.user_id)/(SELECT COUNT(*) from users)*100),2) as percentage
FROM Register as c 
LEFT JOIN Users as r
ON c.user_id=r.user_id
GROUP BY c.contest_id
ORDER BY percentage DESC ,c.contest_id ASC