SELECT distinct(v.customer_id),
count(*) OVER (PARTITION BY v.customer_id) as count_no_trans
FROM visits as v
LEFT JOIN transactions t
ON v.visit_id = t.visit_id
WHERE t.transaction_id IS null 