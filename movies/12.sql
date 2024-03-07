--List the movies in which both Johnny Depp and Helena Bonham Carter starred
SELECT m.title
FROM movies m
JOIN stars s
ON m.id = s.movie_id
JOIN people p
ON p.id = s.person_id
JOIN stars s1
ON m.id = s1.movie_id
JOIN people p1
ON p1.id = s1.person_id
WHERE p.name = 'Johnny Depp' AND p1.name = 'Helena Bonham Carter'
