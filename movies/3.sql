-- List all the movies with release date 2018 or later
SELECT title
FROM movies
WHERE year >= 2018
ORDER BY title
