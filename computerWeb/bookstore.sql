CREATE DATABASE  bookstore


CREATE TABLE publisher (
    pid INT(30),
    name VARCHAR(255),
    PRIMARY KEY (pid)
);

CREATE TABLE author (
    aid INT(30),
    name VARCHAR(255),
    PRIMARY KEY (aid)
);

CREATE TABLE book (
    bid INT(5),
    name VARCHAR(255),
    aid INT(30),
    pid INT(30),
    PRIMARY KEY (bid),
    FOREIGN KEY (aid) REFERENCES author(aid),
    FOREIGN KEY (pid) REFERENCES publisher(pid)
);