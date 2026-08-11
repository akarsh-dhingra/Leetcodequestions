SELECT if(mod(id,2)=0,id-1,if(id<(select MAX(id) from seat),id+1,id)) as id,student
FROM Seat 
ORDER BY id