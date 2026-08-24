SELECT *
FROM Cinema as c 
WHERE c.id %2!=0 AND c.description!="boring"
order by c.rating DESC