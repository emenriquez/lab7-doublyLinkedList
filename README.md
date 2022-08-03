# Lab 7 - Doubly Linked Lists
Complete the exercises in StudentList.cpp (class/function definitions - no main() function should be written).

In this lab you will implement a doubly-linked list. 

### Pointers & Variables:
1.	**Head:** This pointer will always point to the top Node of your stack, when you push use this pointer to locate the top Node.
2.	**Tail:**  This pointer will always point to the bottom Node of the stack, set this pointer when the stack pushes its first item.
3.	**Count:** Use this integer variable to store the number of items in your Stack, *increase* when you push, *decrease* when you pop.

### Functions:
1.	**LLStack:** Class constructor, initialize the pointers & variables to reflect an empty Stack.
2.	**Top:** Returns the string data from the top Node.
3.	**Size:** Returns the number of items in your Stack.
4.	**Push(string):** Push a new Node with data=string. Update, if necessary, *head*, *tail* and *count*.
5.	**Pop:** Removes the top Node of the stack and delete the Node to save memory. Update, if necessary, head, tail and count.

### Class Node:
1.	String data: This variable will store the string of the Node.
2.	Node* next: This pointer will store the address to the next Node in the Linked List.


## Run command
`make test`

In order to test functions individually, you can use the following:
`make test try={functionName}`

For example, to try a function `printArray()` function, you can run:
`make test try=printArray` *(No spaces)*