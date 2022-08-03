	#include "StudentList.h"

	// initialize the list. The list starts with no Students
    StudentList::StudentList() {}

	// return the number of students currently in the list
	int StudentList::listSize() {
		return -1;
	}

	//add a student to the front (head) of the list.
	void StudentList::addFront(Student s) {}

	//add a student to the back (tail) of the list.
	void StudentList::addBack(Student s) {}

	//Print out each student in the list.
	void StudentList::printList() {}

	// Remove the student at the back (tail) of the list
	// should not fail if list is empty
	void StudentList::popBack() {}

	// Remove the student at the front (head) of the list
	// should not fail if list is empty
	void StudentList::popFront() {}

	//insert a student at the position "index".
	// for this list, count head as index 0
	void StudentList::insertStudent(Student s, int index) {}

	//find the student with the given id number and return them
	// if no student matches, print a message 
	// and return a dummy student object
	Student StudentList::retrieveStudent(int idnumber) {
		Student fixthis;
		return fixthis;
	}

	// Remove a student from the list with a given id number
	// If no student matches, print a message and do nothing

	//Change the gpa of the student with given id number to newGPA
	void StudentList::updateGPA(int idnumber, float newGPA) {}

	//Add all students from otherlist to this list.
	//otherlist should be empty after this operation.
	void StudentList::mergeList(StudentList &otherlist) {}

	//create a list of students whose gpa is at least minGPA.
	//Return this list.  The original list should
	//not be modified (do not remove the students from the original list).
	StudentList StudentList::honorRoll(float minGPA) {
		StudentList fixthis;
		return fixthis;
	}