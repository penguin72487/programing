
CREATE TABLE Student (
    sid CHAR(8) NOT NULL,
    name VARCHAR(12) NOT NULL,
    tel VARCHAR(15),
    birthday DATETime,
    GPA FLOAT,
    PRIMARY KEY (sid)
);
CREATE TABLE Course (
    c_no CHAR(8) NOT NULL,
    tutle VARCHAR(30) NOT NULL,
    credit INT DEFAULT 3,
    PRIMARY KEY (c_no)
);
CREATE TABLE employee (
    eid CHAR(8) NOT NULL,
    name VARCHAR(12) NOT NULL,
    tel VARCHAR(15),
    PRIMARY KEY (eid)
);
CREATE TABLE Instructors (
    eid CHAR(8) NOT NULL,
    name VARCHAR(12) NOT NULL,
    rank VARCHAR(12),
    department VARCHAR(12),
    PRIMARY KEY (eid),
    FOREIGN KEY (eid) REFERENCES Employee(eid)
);
CREATE TABLE classes (
    
    eid CHAR(8) NOT NULL,
    sid CHAR(8) NOT NULL,
    c_no CHAR(8) NOT NULL,
    time DATETime,
    room VARCHAR(12),
    score FLOAT,
    PRIMARY KEY (c_no, eid,sid),
    FOREIGN KEY (c_no) REFERENCES Course(c_no),
    FOREIGN KEY (eid) REFERENCES Instructors(eid),
    FOREIGN KEY (sid) REFERENCES Student(sid)
);
insert into Student 
values ('s073','錢昱名','0912345678','1999-01-01',3.5);
