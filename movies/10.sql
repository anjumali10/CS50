-- List the people who directed a movie that recieved a rating at least 9.0
SELECT DISTINCT p.name
FROM movies m
JOIN ratings r
ON m.id = r.movie_id
JOIN directors d
ON m.id = d.movie_id
JOIN people p
ON p.id = d.person_id
WHERE r.rating >= 9.0
