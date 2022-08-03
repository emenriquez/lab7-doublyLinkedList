#include <iostream>
#include <string>
using namespace std;

// Implement the "StudentList" data structure with a doubly linked list implementation.

class Student {
	public:
		string name;
		int id;
		float GPA;

		Student(string inName = "nobody", int inId = -1, float inGPA = 0.0) {
			name = inName;
			id = inId;
			GPA = inGPA;
		}
};

class Node {
	public:
		Student data;
		Node *next;
		Node *prev;

		Node(Student x, Node *nextPtr = nullptr, Node *prevPtr = nullptr)
		{
			data = x;
			next = nextPtr;
			prev = prevPtr;
		}
};

class StudentList {
	private:
		Node *head;
		Node *tail;
		int numStudents;

	public:
		StudentList();
		int listSize();
		void addFront(Student s);
		void addBack(Student s);
		void printList();
		void popFront();
		void popBack();
		void insertStudent(Student s, int index);
		Student retrieveStudent(int idnumber);
		void removeStudentById(int idnumber);
		void updateGPA(int idnumber, float newGPA);
		void mergeList(StudentList &otherlist);
		StudentList honorRoll(float minGPA);
};