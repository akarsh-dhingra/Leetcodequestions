SELECT c.id,c.movie,c.description,c.rating
from Cinema as c
Where c.description !='boring' AND c.id%2!=0
ORDER BY c.rating DESC
