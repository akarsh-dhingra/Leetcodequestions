-- Solution to find all sales that occured in the FY each product 
-- was sold: 
SELECT s.product_id,s.year AS first_year,s.quantity,s.price
FROM Sales as s
WHERE (s.product_id,s.year) IN (SELECT product_id,min(year) FROM SALES GROUP BY product_id)
-- For each product_id 