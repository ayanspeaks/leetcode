select EU.unique_id, E.name from Employees as E left outer join EmployeeUNI as EU
on E.id = EU.id

/*SELECT EU.unique_id, E.name
FROM Employees as E LEFT OUTER JOIN EmployeeUNI as EU 
ON E.id=EU.id */