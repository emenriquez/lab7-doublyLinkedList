// test file - do not modify
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <ctime>
#include <iostream>
using namespace std;

#include "StudentList.cpp" 

TEST_CASE("listSize") {
    StudentList test;
    CHECK(test.listSize() == 0);
}

TEST_CASE("addFront") {
    StudentList test;
    Student newGuy;
    CHECK_NOTHROW(test.addFront(newGuy));

    // check size update
    CHECK(test.listSize() == 1);

    // multiple adds
    Student newGirl, newDude, newGal;
    test.addFront(newGirl);
    test.addFront(newDude);
    test.addFront(newGal);

    CHECK(test.listSize() == 4);
}

TEST_CASE("addBack") {
    StudentList test;
    Student newGuy;
    CHECK_NOTHROW(test.addBack(newGuy));

    // check size update
    CHECK(test.listSize() == 1);

    // multiple adds
    Student newGirl, newDude, newGal;
    test.addBack(newGirl);
    test.addBack(newDude);
    test.addBack(newGal);

    CHECK(test.listSize() == 4);
}

TEST_CASE("printList") {
    StudentList test;
    Student newGuy("carl"), newGirl("carla");
    CHECK_NOTHROW(test.printList());
    test.addFront(newGuy);
    CHECK_NOTHROW(test.printList());
    test.addBack(newGirl);
    CHECK_NOTHROW(test.printList());
}

TEST_CASE("popBack") {
    StudentList test;

    // add students
    Student newGirl, newDude, newGal;
    test.addBack(newGirl);
    test.addFront(newDude);
    test.addBack(newGal);

    CHECK(test.listSize() == 3);

    test.popBack();
    CHECK(test.listSize() == 2);
    test.popBack();
    test.popBack();
    CHECK(test.listSize() == 0);

    CHECK_NOTHROW(test.popBack());
    CHECK_NOTHROW(test.popBack());
    CHECK(test.listSize() == 0);
}

TEST_CASE("popFront") {
    StudentList test;

    // add students
    Student newGirl, newDude, newGal;
    test.addBack(newGirl);
    test.addFront(newDude);
    test.addBack(newGal);

    CHECK(test.listSize() == 3);

    test.popFront();
    CHECK(test.listSize() == 2);
    test.popFront();
    test.popFront();
    CHECK(test.listSize() == 0);

    CHECK_NOTHROW(test.popFront());
    CHECK_NOTHROW(test.popFront());
    CHECK(test.listSize() == 0);
}

TEST_CASE("insertStudent") {
    StudentList test;

    // add students
    Student newGirl, newDude, newGal;
    test.addBack(newGirl);
    test.addFront(newDude);
    test.addBack(newGal);

    CHECK(test.listSize() == 3);

    // insert students
    Student newNewGirl, newNewDude, newNewGal;
    CHECK_NOTHROW(test.insertStudent(newNewGirl, 0));
    CHECK(test.listSize() == 4);

    CHECK_NOTHROW(test.insertStudent(newNewDude, 2));
    CHECK(test.listSize() == 5);

    CHECK_NOTHROW(test.insertStudent(newNewGal, 8));
    CHECK(test.listSize() == 6);
}

TEST_CASE("retrieveStudent") {
    StudentList test;
    Student resultStudent;

    // add students
    Student newGirl("suzy", 12, 3.2);
    Student newDude("jeff", 99, 1.7);
    Student newGal("sam", 63, 1.8);
    test.addBack(newGirl);
    test.addFront(newDude);
    test.addBack(newGal);

    CHECK(test.listSize() == 3);

    // retrieve by id
    CHECK_NOTHROW(test.retrieveStudent(999));
    resultStudent = test.retrieveStudent(999);
    CHECK(resultStudent.name == "nobody");
    
    resultStudent = test.retrieveStudent(99);
    CHECK(resultStudent.name == newDude.name);

    resultStudent = test.retrieveStudent(63);
    CHECK(resultStudent.name == newGal.name);


    // more students
    Student newNewGirl("nancy", 1, 2.65);
    Student newNewDude("carlitos", 11, 3.3);
    Student newNewGal("pam", 111, 3.7);
    test.addBack(newNewGirl);

    test.addBack(newNewDude);

    test.addFront(newNewGal);
}

TEST_CASE("removeStudentById") {
    StudentList test;

    // add students
    Student newGirl("suzy", 12, 3.2);
    Student newDude("jeff", 99, 1.7);
    Student newGal("sam", 63, 1.8);
    test.addBack(newGirl);
    test.addFront(newDude);
    test.addBack(newGal);

    CHECK(test.listSize() == 3);   

    // wrong ID
    CHECK_NOTHROW(test.removeStudentById(999));
    CHECK(test.listSize() == 3);

    test.removeStudentById(99);
    CHECK(test.listSize() == 2);

    // repeat removal
    CHECK_NOTHROW(test.removeStudentById(99));
    CHECK(test.listSize() == 2);

    test.removeStudentById(63);
    CHECK(test.listSize() == 1);

    test.removeStudentById(12);
    CHECK(test.listSize() == 0);  

    // empty list
    CHECK_NOTHROW(test.removeStudentById(99));
    CHECK(test.listSize() == 0);
}

TEST_CASE("updateGPA") {
    StudentList test;
    Student resultStudent;

    // add students
    Student newGirl("suzy", 12, 3.2);
    Student newDude("jeff", 99, 1.7);
    Student newGal("sam", 63, 1.8);
    test.addBack(newGirl);
    test.addFront(newDude);
    test.addBack(newGal);

    CHECK_NOTHROW(test.updateGPA(99, 3.89f));
    test.updateGPA(12, 3.3);
    test.updateGPA(63, 1.999);

    resultStudent = test.retrieveStudent(99);
    CHECK(resultStudent.GPA == 3.89f);

    resultStudent = test.retrieveStudent(12);
    CHECK(resultStudent.GPA == 3.3f);

    resultStudent = test.retrieveStudent(63);
    CHECK(resultStudent.GPA == 1.999f);

}

TEST_CASE("mergeList") {
    StudentList test;
    Student resultStudent;

    // add students
    Student newGirl("suzy", 12, 3.2);
    Student newDude("jeff", 99, 1.7);
    Student newGal("sam", 63, 1.8);
    test.addBack(newGirl);
    test.addFront(newDude);
    test.addBack(newGal);

    CHECK(test.listSize() == 3);

    // more students
    StudentList test2;
    Student newNewGirl("nancy", 1, 2.65);
    Student newNewDude("carlitos", 11, 3.3);
    Student newNewGal("pam", 111, 3.7);
    Student latestStudent("guy", 81, 3.12);
    test2.addBack(newNewGirl);
    test2.addBack(newNewDude);
    test2.addFront(newNewGal);
    test2.insertStudent(latestStudent, 1);

    CHECK(test2.listSize() == 4);

    // merge and check new lists
    CHECK_NOTHROW(test.mergeList(test2));
    CHECK(test.listSize() == 7);
    CHECK(test2.listSize() != 4);
}

TEST_CASE("honorRoll") {
    StudentList test2;
    StudentList honors;

    Student newNewGirl("nancy", 1, 2.65);
    Student newNewDude("carlitos", 11, 3.3);
    Student newNewGal("pam", 111, 3.7);
    Student latestStudent("guy", 81, 3.12);
    test2.addBack(newNewGirl);
    test2.addBack(newNewDude);
    test2.addFront(newNewGal);
    test2.insertStudent(latestStudent, 1);

    honors = test2.honorRoll(3.2);
    CHECK(honors.listSize() == 2);

    honors = test2.honorRoll(3.5);
    CHECK(honors.listSize() == 1);

    honors = test2.honorRoll(4.0);
    CHECK(honors.listSize() == 0);

    honors = test2.honorRoll(0.0);
    CHECK(honors.listSize() == 4);
}