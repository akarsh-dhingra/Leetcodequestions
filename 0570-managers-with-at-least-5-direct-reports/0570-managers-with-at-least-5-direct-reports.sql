SELECT m.name
from Employee as e
JOIN Employee as m 
ON e.managerId=m.id
GROUP by m.id
HAVING count(e.id)>=5