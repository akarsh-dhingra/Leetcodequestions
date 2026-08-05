SELECT r.contest_id as contest_id, ROUND(COUNT(r.user_id)/(SELECT COUNT(*) FROM USERS)*100,2) AS percentage
FROM Register as r
LEFT JOIN Users as u
ON r.user_id=u.user_id
GROUP BY r.contest_id
ORDER BY 
percentage DESC,
r.contest_id ASC
