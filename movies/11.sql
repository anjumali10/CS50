-- List the top five rated movies in which Chadwick Boseman starred in
SELECT m.title
FROM movies m
JOIN ratings r
ON m.id = r.movie_id
JOIN stars s
ON m.id = s.movie_id
JOIN people p
ON p.id = s.person_id
WHERE p.name = 'Chadwick Boseman'
ORDER BY r.rating DESC
LIMIT 5
