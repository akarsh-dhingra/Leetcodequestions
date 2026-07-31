-- Temperature higher than the previous Days 

SELECT t.id
FROM Weather as t
JOIN Weather as y
ON t.recordDate=y.recordDate+1
WHERE t.temperature>y.temperature
-- Today's DATE=Yesterday's Date+1
-- Yesterday's Date=Today's DATE-1

