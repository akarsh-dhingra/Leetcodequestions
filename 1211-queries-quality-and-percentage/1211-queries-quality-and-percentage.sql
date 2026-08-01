-- Avg of ratio b/w query rating and its position.
-- poor query percentage:The percentage of all queries with rating less than 3.

SELECT q.query_name as query_name, ROUND(AVG(q.rating/q.position),2) as quality , 
ROUND(SUM(
    CASE
        WHEN rating < 3 THEN 1
        ELSE 0
    END
)/COUNT(*)*100,2) as poor_query_percentage 
FROM Queries as q
GROUP BY q.query_name

