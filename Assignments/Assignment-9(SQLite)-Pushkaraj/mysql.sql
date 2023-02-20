-- CREATE TABLE Actor(ID NOT NULL PRIMARY KEY, Fname NOT NULL, Lname NOT NULL, Gender NOT NULL);
--CREATE TABLE Movie(ID NOT NULL PRIMARY KEY, Name NOT NULL, Year NOT NULL, Rank NOT NULL);NULL P

-- INSERT INTO Actor(ID, Fname, Lname, Gender)
-- VALUES(16, "Amir", " Khan", "Male")

-- UPDATE Movie
-- SET Rank = 7.4
-- WHERE ID = 9;

--SELECT Name, Year, Rank FROM Actor CROSS JOIN Movie;
--SELECT MID, Name, Rank FROM Actor INNER JOIN Movie;
--SELECT MID, Name, Rank FROM Actor NATURAL JOIN Movie

-- ALTER TABLE Movie
FOREIGN KEY (MID) REFERENCES Actor(ID)
