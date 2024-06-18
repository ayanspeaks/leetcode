# Write your MySQL query statement below
Select 
    Signups.user_id as user_id ,
    ifnull(round(sum(action = 'confirmed') / count(*), 2), 0.00) as confirmation_rate
from 
    Signups
left join 
    Confirmations using(user_id)
group by 
    user_id ; 