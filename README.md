# Lab 7 - Doubly Linked Lists
Complete the exercises in StudentList.cpp (class/function definitions - no main() function should be written).

In this lab you will implement a doubly-linked list.

## How to Run Tests

### Option 1: Using the test script (Recommended)
Simply run the test script:
```bash
./run_tests.sh
```

### Option 2: Manual compilation
Compile and run the tests manually:
```bash
g++ -std=c++11 -o test_program simple_tests.cpp StudentList.cpp
./test_program
```

## Understanding the Tests

The test file `simple_tests.cpp` contains unit tests for each function you need to implement:

- `test_listSize()` - Tests the listSize() function
- `test_addFront()` - Tests adding students to the front of the list
- `test_addBack()` - Tests adding students to the back of the list
- `test_printList()` - Tests printing the list contents
- `test_popBack()` - Tests removing students from the back
- `test_popFront()` - Tests removing students from the front
- `test_insertStudent()` - Tests inserting students at specific positions
- `test_retrieveStudent()` - Tests retrieving students by ID
- `test_removeStudentById()` - Tests removing students by ID
- `test_updateGPA()` - Tests updating student GPAs
- `test_mergeList()` - Tests merging two lists
- `test_honorRoll()` - Tests creating honor roll lists

## Testing Individual Functions

To focus on specific functions while developing, you can comment out the other test function calls in the `main()` function of `simple_tests.cpp`.

## Demo code

You can also try your own demo code to test your class objects and methods in `demo.cpp`. To run this code:
```bash
g++ -std=c++11 -o demo_program demo.cpp StudentList.cpp
./demo_program
```

## Tips for Success

1. Start with the basic functions: constructor, listSize(), addFront(), addBack()
2. Make sure to update the `numStudents` counter in all functions that add or remove students
3. Handle edge cases like empty lists gracefully
4. Remember that this is a doubly-linked list, so maintain both `next` and `prev` pointers
5. Test frequently by running the tests after implementing each function