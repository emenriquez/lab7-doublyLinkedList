## Getting Started with Your Doubly Linked List Implementation

### Quick Start
1. Open `StudentList.cpp` and implement the required functions
2. Run `./run_tests.sh` to test your implementation
3. Keep implementing until all tests pass!

### Implementation Tips

#### Constructor
- Initialize `head` and `tail` to `nullptr`
- Initialize `numStudents` to 0

#### Adding Students (addFront/addBack)
- Create a new Node with the student data
- Handle the empty list case separately
- Update `head`/`tail` pointers as needed
- Don't forget to increment `numStudents`

#### Removing Students (popFront/popBack)
- Check for empty list and print error message
- Handle the single-node case (when head == tail)
- Update pointers correctly
- Don't forget to delete the node and decrement `numStudents`

#### Doubly Linked List Pointers
Remember: each node has both a `next` AND a `prev` pointer!
- When adding: set both next and prev pointers
- When removing: update both neighbors' pointers

### Common Mistakes to Avoid
1. Forgetting to update `numStudents`  
2. Not handling empty list cases
3. Memory leaks (not deleting removed nodes)
4. Not updating both `next` and `prev` pointers
5. Not handling the single-node case properly

### Testing Strategy
Start with the basic functions first:
1. Constructor and listSize()
2. addFront() and addBack()
3. printList() (helps with debugging)
4. popFront() and popBack()
5. Then move on to the more complex functions