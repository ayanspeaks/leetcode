# Write your MySQL query statement below
SELECT EU.unique_id, E.name
FROM Employees as E LEFT OUTER JOIN EmployeeUNI as EU 
ON E.id=EU.id 