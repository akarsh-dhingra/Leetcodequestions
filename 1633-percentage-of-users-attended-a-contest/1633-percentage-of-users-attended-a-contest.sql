SELECT r.contest_id , ROUND((COUNT(r.user_id) /(SELECT COUNT(*) FROM USERS))*100,2) as percentage
FROM register as r
left join Users as u
on u.user_id=r.user_id
GROUP BY r.contest_id 
ORDER BY percentage DESC, contest_id ASC
