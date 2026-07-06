-- Write your PostgreSQL query statement below

-- addressId

SELECT p.firstName,p.lastName,a.city,a.state
FROM PERSON AS p
LEFT JOIN Address as a
ON p.personId=a.personId
