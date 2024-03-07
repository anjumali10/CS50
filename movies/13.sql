-- List all the people who starred in the movie in which Kevin Bacon also starred
SELECT p.name
FROM movies m
JOIN stars s
ON m.id = s.movie_id
JOIN people p
ON p.id = s.person_id
JOIN stars s1
ON m.id = s1.movie_id
JOIN people p1
ON p1.id = s1.person_id
WHERE (p1.name = 'Kevin Bacon' AND p1.birth = 1958) AND NOT p.name = 'Kevin Bacon'

