SELECT users.name, COUNT(*) as count 
FROM users 
LEFT JOIN friends 
ON users.id = friends.user1 OR users.id = friends.user2
WHERE users.sex = 'f' 
GROUP BY users.id, users.name;