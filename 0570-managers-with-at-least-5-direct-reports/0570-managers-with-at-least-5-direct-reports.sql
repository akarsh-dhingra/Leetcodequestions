SELECT e.name
from Employee as e
JOIN Employee as m
ON e.id=m.managerId
GROUP BY e.id,e.name
HAVING COUNT(*)>=5