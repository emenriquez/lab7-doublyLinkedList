#include <iostream>
#include <cassert>
#include <string>
#include "StudentList.h"

using namespace std;

// Simple test framework
int tests_passed = 0;
int tests_failed = 0;

void test_assert(bool condition, const string& test_name) {
    if (condition) {
        cout << "✓ PASS: " << test_name << endl;
        tests_passed++;
    } else {
        cout << "✗ FAIL: " << test_name << endl;
        tests_failed++;
    }
}

void print_results() {
    cout << "\n========== TEST RESULTS ==========\n";
    cout << "Tests passed: " << tests_passed << endl;
    cout << "Tests failed: " << tests_failed << endl;
    cout << "Total tests: " << (tests_passed + tests_failed) << endl;
    if (tests_failed == 0) {
        cout << "🎉 ALL TESTS PASSED! 🎉\n";
    } else {
        cout << "❌ Some tests failed. Keep working!\n";
    }
    cout << "==================================\n";
}

void test_listSize() {
    cout << "\n--- Testing listSize() ---\n";
    
    StudentList test;
    test_assert(test.listSize() == 0, "Empty list size should be 0");
    
    Student s1("Alice", 1, 3.5);
    test.addFront(s1);
    test_assert(test.listSize() == 1, "List size should be 1 after adding one student");
    
    Student s2("Bob", 2, 3.2);
    test.addBack(s2);
    test_assert(test.listSize() == 2, "List size should be 2 after adding two students");
}

void test_addFront() {
    cout << "\n--- Testing addFront() ---\n";
    
    StudentList test;
    Student s1("Alice", 1, 3.5);
    
    // Test basic functionality - should not crash
    test.addFront(s1);
    test_assert(test.listSize() == 1, "Size should be 1 after adding one student to front");
    
    // Test multiple additions
    Student s2("Bob", 2, 3.2);
    Student s3("Charlie", 3, 2.8);
    test.addFront(s2);
    test.addFront(s3);
    test_assert(test.listSize() == 3, "Size should be 3 after adding three students to front");
}

void test_addBack() {
    cout << "\n--- Testing addBack() ---\n";
    
    StudentList test;
    Student s1("Alice", 1, 3.5);
    
    // Test basic functionality
    test.addBack(s1);
    test_assert(test.listSize() == 1, "Size should be 1 after adding one student to back");
    
    // Test multiple additions
    Student s2("Bob", 2, 3.2);
    Student s3("Charlie", 3, 2.8);
    test.addBack(s2);
    test.addBack(s3);
    test_assert(test.listSize() == 3, "Size should be 3 after adding three students to back");
}

void test_printList() {
    cout << "\n--- Testing printList() ---\n";
    
    StudentList test;
    
    cout << "Testing empty list print (should not crash):\n";
    test.printList();
    test_assert(true, "printList() should not crash on empty list");
    
    Student s1("Alice", 1, 3.5);
    test.addFront(s1);
    cout << "Testing single student print:\n";
    test.printList();
    test_assert(true, "printList() should not crash with one student");
    
    Student s2("Bob", 2, 3.2);
    test.addBack(s2);
    cout << "Testing multiple students print:\n";
    test.printList();
    test_assert(true, "printList() should not crash with multiple students");
}

void test_popBack() {
    cout << "\n--- Testing popBack() ---\n";
    
    StudentList test;
    
    // Test empty list
    cout << "Testing popBack on empty list (should print error message):\n";
    test.popBack();
    test_assert(test.listSize() == 0, "Size should remain 0 after popping from empty list");
    
    // Add students and test popping
    Student s1("Alice", 1, 3.5);
    Student s2("Bob", 2, 3.2);
    Student s3("Charlie", 3, 2.8);
    test.addBack(s1);
    test.addBack(s2);
    test.addBack(s3);
    
    test.popBack();
    test_assert(test.listSize() == 2, "Size should be 2 after one popBack");
    
    test.popBack();
    test.popBack();
    test_assert(test.listSize() == 0, "Size should be 0 after popping all elements");
    
    // Test popping from empty list again
    test.popBack();
    test_assert(test.listSize() == 0, "Size should remain 0 after popping from empty list");
}

void test_popFront() {
    cout << "\n--- Testing popFront() ---\n";
    
    StudentList test;
    
    // Test empty list
    cout << "Testing popFront on empty list (should print error message):\n";
    test.popFront();
    test_assert(test.listSize() == 0, "Size should remain 0 after popping from empty list");
    
    // Add students and test popping
    Student s1("Alice", 1, 3.5);
    Student s2("Bob", 2, 3.2);
    Student s3("Charlie", 3, 2.8);
    test.addFront(s1);
    test.addFront(s2);
    test.addFront(s3);
    
    test.popFront();
    test_assert(test.listSize() == 2, "Size should be 2 after one popFront");
    
    test.popFront();
    test.popFront();
    test_assert(test.listSize() == 0, "Size should be 0 after popping all elements");
    
    // Test popping from empty list again
    test.popFront();
    test_assert(test.listSize() == 0, "Size should remain 0 after popping from empty list");
}

void test_insertStudent() {
    cout << "\n--- Testing insertStudent() ---\n";
    
    StudentList test;
    
    // Test inserting at index 0 (empty list)
    Student s1("Alice", 1, 3.5);
    test.insertStudent(s1, 0);
    test_assert(test.listSize() == 1, "Size should be 1 after inserting at index 0");
    
    // Test inserting at valid index
    Student s2("Bob", 2, 3.2);
    test.insertStudent(s2, 1);
    test_assert(test.listSize() == 2, "Size should be 2 after inserting at index 1");
    
    // Test inserting at invalid index (should add to back)
    Student s3("Charlie", 3, 2.8);
    cout << "Testing insert at invalid index (should print message and add to back):\n";
    test.insertStudent(s3, 10);
    test_assert(test.listSize() == 3, "Size should be 3 after inserting at invalid index");
}

void test_retrieveStudent() {
    cout << "\n--- Testing retrieveStudent() ---\n";
    
    StudentList test;
    
    // Test retrieving from empty list
    cout << "Testing retrieve from empty list (should print error message):\n";
    Student result = test.retrieveStudent(999);
    test_assert(result.name == "nobody", "Should return dummy student for non-existent ID");
    
    // Add students
    Student s1("Alice", 1, 3.5);
    Student s2("Bob", 2, 3.2);
    Student s3("Charlie", 3, 2.8);
    test.addBack(s1);
    test.addBack(s2);
    test.addBack(s3);
    
    // Test retrieving existing student
    result = test.retrieveStudent(2);
    test_assert(result.name == "Bob", "Should retrieve Bob with ID 2");
    test_assert(result.id == 2, "Retrieved student should have correct ID");
    test_assert(result.GPA == 3.2f, "Retrieved student should have correct GPA");
    
    // Test retrieving non-existent student
    cout << "Testing retrieve non-existent student (should print error message):\n";
    result = test.retrieveStudent(999);
    test_assert(result.name == "nobody", "Should return dummy student for non-existent ID");
}

void test_removeStudentById() {
    cout << "\n--- Testing removeStudentById() ---\n";
    
    StudentList test;
    
    // Test removing from empty list
    cout << "Testing remove from empty list (should print error message):\n";
    test.removeStudentById(999);
    test_assert(test.listSize() == 0, "Size should remain 0 when removing from empty list");
    
    // Add students
    Student s1("Alice", 1, 3.5);
    Student s2("Bob", 2, 3.2);
    Student s3("Charlie", 3, 2.8);
    test.addBack(s1);
    test.addBack(s2);
    test.addBack(s3);
    
    // Test removing existing student
    test.removeStudentById(2);
    test_assert(test.listSize() == 2, "Size should be 2 after removing one student");
    
    // Test removing non-existent student
    cout << "Testing remove non-existent student (should print error message):\n";
    test.removeStudentById(999);
    test_assert(test.listSize() == 2, "Size should remain 2 when removing non-existent student");
    
    // Remove remaining students
    test.removeStudentById(1);
    test.removeStudentById(3);
    test_assert(test.listSize() == 0, "Size should be 0 after removing all students");
}

void test_updateGPA() {
    cout << "\n--- Testing updateGPA() ---\n";
    
    StudentList test;
    
    // Test updating in empty list
    cout << "Testing update GPA in empty list (should print error message):\n";
    test.updateGPA(999, 4.0f);
    
    // Add students
    Student s1("Alice", 1, 3.5);
    Student s2("Bob", 2, 3.2);
    test.addBack(s1);
    test.addBack(s2);
    
    // Test updating existing student
    test.updateGPA(1, 4.0f);
    Student result = test.retrieveStudent(1);
    test_assert(result.GPA == 4.0f, "Alice's GPA should be updated to 4.0");
    
    // Test updating non-existent student
    cout << "Testing update GPA for non-existent student (should print error message):\n";
    test.updateGPA(999, 4.0f);
}

void test_mergeList() {
    cout << "\n--- Testing mergeList() ---\n";
    
    StudentList test1;
    StudentList test2;
    
    // Add students to first list
    Student s1("Alice", 1, 3.5);
    Student s2("Bob", 2, 3.2);
    test1.addBack(s1);
    test1.addBack(s2);
    
    // Add students to second list
    Student s3("Charlie", 3, 2.8);
    Student s4("Diana", 4, 3.9);
    test2.addBack(s3);
    test2.addBack(s4);
    
    int originalSize1 = test1.listSize();
    int originalSize2 = test2.listSize();
    
    // Merge lists
    test1.mergeList(test2);
    
    test_assert(test1.listSize() == originalSize1 + originalSize2, 
                "First list should contain all students after merge");
    test_assert(test2.listSize() == 0, "Second list should be empty after merge");
}

void test_honorRoll() {
    cout << "\n--- Testing honorRoll() ---\n";
    
    StudentList test;
    
    // Add students with different GPAs
    Student s1("Alice", 1, 3.5);   // Should be on honor roll (>= 3.2)
    Student s2("Bob", 2, 2.8);     // Should NOT be on honor roll
    Student s3("Charlie", 3, 3.9); // Should be on honor roll (>= 3.2)
    Student s4("Diana", 4, 3.1);   // Should NOT be on honor roll
    
    test.addBack(s1);
    test.addBack(s2);
    test.addBack(s3);
    test.addBack(s4);
    
    // Test honor roll with GPA >= 3.2
    StudentList honors = test.honorRoll(3.2f);
    test_assert(honors.listSize() == 2, "Honor roll should contain 2 students with GPA >= 3.2");
    test_assert(test.listSize() == 4, "Original list should remain unchanged");
    
    // Test honor roll with higher GPA requirement
    StudentList highHonors = test.honorRoll(3.6f);
    test_assert(highHonors.listSize() == 1, "Honor roll should contain 1 student with GPA >= 3.6");
    
    // Test honor roll with very low GPA requirement
    StudentList allStudents = test.honorRoll(0.0f);
    test_assert(allStudents.listSize() == 4, "Honor roll should contain all 4 students with GPA >= 0.0");
}

int main() {
    cout << "========================================\n";
    cout << "    DOUBLY LINKED LIST UNIT TESTS\n";
    cout << "========================================\n";
    cout << "Running tests for StudentList implementation...\n";
    
    // Run all tests
    test_listSize();
    test_addFront();
    test_addBack();
    test_printList();
    test_popBack();
    test_popFront();
    test_insertStudent();
    test_retrieveStudent();
    test_removeStudentById();
    test_updateGPA();
    test_mergeList();
    test_honorRoll();
    
    // Print final results
    print_results();
    
    return (tests_failed == 0) ? 0 : 1;
}
