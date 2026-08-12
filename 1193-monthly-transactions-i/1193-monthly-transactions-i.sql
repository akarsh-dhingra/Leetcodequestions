SELECT DATE_FORMAT(trans_date,'%Y-%m') as month,country,COUNT(amount) as trans_count,SUM(
CASE 
    WHEN state='approved' then 1
    ELSE 0
END) AS approved_count, SUM(amount) as trans_total_amount, 
SUM(
    CASE 
        WHEN state='approved' then amount
        ELSE 0
END
) as approved_total_amount
FROM Transactions 
GROUP BY month,country
-- Our primary key will become month,country 
-- No. of transactions and their amount 
-- No of approved transactions and their amount 



