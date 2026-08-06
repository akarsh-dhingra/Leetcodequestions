SELECT a.activity_date as day, COUNT(distinct(a.user_id)) as active_users
FROM Activity as a
WHERE a.activity_date BETWEEN '2019-06-28' AND '2019-07-27'
GROUP BY a.activity_date 



-- The table shows the user activities for a social media website. 
-- 2019-06-28 - 2019-07-27 