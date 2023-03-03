# Write your MySQL query statement below
SELECT firstname, lastname, city, state from Person left JOIN Address on Person.personId=Address.personId;