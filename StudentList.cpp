	#include "StudentList.h"

	// Define a constructor to initialize the list. The list starts with no Students
    StudentList::StudentList() {
        head = nullptr;
        tail = nullptr;
        numStudents = 0;
    }

	// return the number of students currently in the list
	int StudentList::listSize() {
		return numStudents;
	}

	//add a Node with a student to the front (head) of the list.
	void StudentList::addFront(Student s) {
		// TODO: Implement this function
		// Don't forget to update numStudents!
	}

	//add a Node with a student to the back (tail) of the list.
	void StudentList::addBack(Student s) {
		// TODO: Implement this function
		// Don't forget to update numStudents!
	}

	//Print out the names of each student in the list.
	void StudentList::printList() {
		// TODO: Implement this function
		// Handle empty list case
	}

	// Remove the Node with the student at the back (tail) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popBack() {
		// TODO: Implement this function
		// Handle empty list case - print error message
		// Don't forget to update numStudents and delete the node!
	}

	// Remove the Node with the student at the front (head) of the list
	// should not fail if list is empty! Print an error message if this occurs
	// Don't forget that your head and tail pointers will be null pointers if the list is empty
	void StudentList::popFront() {
		// TODO: Implement this function
		// Handle empty list case - print error message
		// Don't forget to update numStudents and delete the node!
	}

	//insert a student at the position "index".
	// for this list, count head as index 0
	// if index is outside of current list range, 
	// print a message and insert the student at the back of the list
	// the previous Node at your target index should be moved forward. "For exampe, Node with student at index i, becomes index i+1" 
	// Remember that you already have methods that can add students to the front or back of list if needed! Don't repeat this code.
	void StudentList::insertStudent(Student s, int index) {
		// TODO: Implement this function
		// Use addFront() and addBack() when appropriate!
	}

	//find the student with the given id number and return them
	// if no student matches, print a message 
	// and create and return a dummy student object
	Student StudentList::retrieveStudent(int idNum) {
		// TODO: Implement this function
		// Return a dummy Student() if not found
		Student dummy;  // This creates a dummy student with default values
		return dummy;
	}

	// Remove a Node with a student from the list with a given id number
	// If no student matches, print a message and do nothing
	void StudentList::removeStudentById(int idNum) {
		// TODO: Implement this function
		// Don't forget to update numStudents and delete the node!
	}

	//Change the gpa of the student with given id number to newGPA
	void StudentList::updateGPA(int idNum, float newGPA) {
		// TODO: Implement this function
	}

	//Add all students from otherList to this list.
	//otherlist should be empty after this operation.
	/*
	For example, if the list has 3 students:
	s1 <-> s2 <-> s3
	and otherList has 2 students
	s4 <-> s5
	then after mergeList the currently list should have all 5 students
	s1 <-> s2 <-> s3 <-> s4 <-> s5
	and otherList should be empty and have zero students.
	*/
	void StudentList::mergeList(StudentList &otherList) {
		// TODO: Implement this function
		// Make sure to clear otherList after merging!
	}

	//create a StudentList of students whose gpa is at least minGPA.
	//Return this list.  The original (current) list should
	//not be modified (do not remove the students from the original list).
	StudentList StudentList::honorRoll(float minGPA) {
		// TODO: Implement this function
		StudentList honorsList;
		return honorsList;
	}
