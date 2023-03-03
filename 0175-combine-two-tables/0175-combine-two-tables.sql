# Write your MySQL query statement below
SELECT c.firstname, c.lastname, o.city, o.state from Person as c left JOIN address as o on c.personId=o.personId;