# Recursion

## What is Recursion?

Recursion is a powerful programming technique, and its popularity stems from its elegance and ability to solve certain problems in a concise and clear manner.

Recursion is a function that calls itself. Inside this function, there must be a condition that stops the recursive function from calling itself which we call the "base case" and ensures the recursive functions STOPS/TERMINATES.

Without this base case, the recursive function may run forever or exceed the call stack leading to errors.

## Tracing Recursion

"Tracing" refers to the process of following the execution of a recursive function as its calls itself and eventually resolves to a base case. Tracing helps you understand how the recursive calls are happening and how the function works step by step.

When you trace a recursive function, you are essentially examining the sequence of function calls, their arguments, and the values returned at each step. This can be a helpful technique for understanding the flow of execution and identifying any patterns or issues in the recursive algorithm.

## Stack Used in Recursion

When you start a new process, the process will create a space in memory for the code, the stack, and the heap. A stack is commonly used in recursion to keep track of function calls and their local variables.

When a function is called, a new set of local variables and parameters is created for that function. These variales need to be stored somewhere so that when the function finishes its execution, it can return control to the point in the code where it was called. This is where the stack comes in.

Each time a function is called, a new frame (activation record) is added to the top of the stack. This frame contains the local variables, function parameters, return address, and other information needed for the function call's execution. When the function completes its execution, its frame is removed from the stack, and control returns to the calling function.

In the case of recursion, where the function calls itself, each recursive call adds a new frame to the stack. The stack keeps track of the state of each recursive call, allowing the program to eventually return to the initial call when the base case is reached.

For more information about how each process contains code, a stack, and heap memory, visit this course series: // TODO: Add course

## Time Complexity

## Types of Problems to Use with Recursion

### Divide and Conquer

Many problems can be naturally divided into smaller, similar subproblems. Recursion is an excellent fit for such scenarios. Algorithms like quicksort, mergesort, and binary search follow a dive-and-conquer approach and are often implemented using recursion.

### Tree and Graph Traversal

Recursive algorithms are often used for traversing tree and graph structures. For example, depth-first search (DFS) and tree traversal (in-order, pre-order, post-order) are natural cnadidates for recursive implementations.

### mathematical and Inductive problems

Recursive solutions are often elegant for problems that can be defined inductively. Mathematical problems like computing factorials, Fibonacci numbers, or solving the Tower of Hanoi puzzle lend themselves well to recursive solutions.

### Code Readability

Recursion can lead to mroe readable and intuitive code, especially when dealing with inherently recursive problems. The code oftens mirrors the mathematical or logical structure of the problem.

### Dynamic Programming

Recursion is a fundamental concept in dynamic programming, a technique used to solve problems by breaking them down into overlapping subproblems and caching or memoizing their solutions. Recursive solutions often naturally lead to dynamic programming solutions.

## Problems with Recursion
