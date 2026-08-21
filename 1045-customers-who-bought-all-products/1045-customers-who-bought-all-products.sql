SELECT c.customer_id
FROM Customer as c
LEFT JOIN Product as p
ON c.product_key=p.product_key
GROUP BY c.customer_id
HAVING count(distinct c.product_key) = (SELECT COUNT(*) FROM PRODUCT)