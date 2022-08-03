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

TEST_CASE("addBack") {}