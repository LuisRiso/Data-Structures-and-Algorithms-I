# Data-Structures-and-Algorithms-I

This repository contains class materials, exercises, assignments, practical implementations, and study projects developed during the **Algorithms and Data Structures** course at the **Federal University of Itajubá (UNIFEI)**.

The course focuses on classic data structures stored in main memory, their implementations, applications, and basic algorithmic complexity analysis. The implementations were mainly developed in the C programming language, with emphasis on modular programming, recursion, abstract data types, linear data structures, non-linear data structures, and problem-solving techniques.

## 📚 About the Course

Algorithms and Data Structures is a foundational course in computer science and software development.

The repository documents the learning process through theoretical materials, programming exercises, practical examples, and larger assignments. The topics progress from introductory algorithmic analysis and recursion to linked lists, queues, stacks, priority queues, binary trees, binary search trees, backtracking, and Huffman coding.

The main purpose of this repository is to organize the practical applications developed throughout the discipline and demonstrate the use of data structures to solve computational problems efficiently.

## 🎯 Learning Objectives

The main objectives of this repository are to:

* Practice algorithmic problem-solving using C.
* Understand recursion and recursive problem decomposition.
* Implement abstract data types using modular programming.
* Work with static and dynamic linear data structures.
* Implement and manipulate linked lists.
* Understand queues, circular queues, and priority queues.
* Implement stacks and apply them to computational problems.
* Explore backtracking through the N-Queens problem.
* Understand binary trees and binary search trees.
* Practice tree traversal algorithms.
* Apply data structures to real problems such as maze solving, friendship distance, decision trees, matrix multiplication, and Huffman coding.
* Perform basic analysis of algorithmic complexity.
* Organize code into `.c` and `.h` files.

## 🧠 Topics Covered

| Module          | Topic                                                                       |
| --------------- | --------------------------------------------------------------------------- |
| Introduction    | Basic review, pointers, memory, and algorithmic reasoning                   |
| Recursion       | Recursive functions, stopping conditions, binary search, and Tower of Hanoi |
| Linked Lists    | Dynamic memory, nodes, insertion, removal, and traversal                    |
| Queues          | Static queues, circular queues, dynamic queues, and applications            |
| Stacks          | Stack operations, expression validation, maze solving, and backtracking     |
| N-Queens        | Recursive and stack-based solutions for combinatorial problems              |
| Binary Trees    | Tree representation, traversal, decision trees, and search trees            |
| Priority Queues | Priority-based data organization and processing                             |
| Huffman Coding  | Tree-based encoding and compression logic                                   |
| Assignments     | Matrix multiplication, N-Queens, and Huffman coding projects                |

## 🗂️ Repository Structure

```text
.
├── Algortimos Apostilas
├── Aula 01 - Introdução
├── Aula 02 - Recursividade
├── Aula 03 - Lista Ligada
├── Aula 04 - Fila
├── Aula 05 - Pilhas
├── Aula 06 - N Queens
├── Aula 07 - Arvore Binaria
├── Aula 08 - Fila Prioridade
├── Exercicios Extras
├── Trabalho01
├── Trabalho02
├── Trabalho03
└── Trabalhos Entregues
```

## 📁 Main Folders

### `Algortimos Apostilas`

Contains course modules, exercise lists, review materials, complementary materials, and assignment descriptions used throughout the discipline.

### `Aula 01 - Introdução`

Contains introductory C exercises and initial examples focused on reviewing basic programming concepts and preparing for the study of algorithms and data structures.

### `Aula 02 - Recursividade`

Contains recursive implementations, including recursion examples, Tower of Hanoi, vector search, and binary search.

### `Aula 03 - Lista Ligada`

Contains exercises involving linked lists and dynamic data organization.

### `Aula 04 - Fila`

Contains queue implementations, including standard queues, circular queues, and an application involving friendship distance calculation.

### `Aula 05 - Pilhas`

Contains stack implementations and applications, including parenthesis validation and maze-solving exercises.

### `Aula 06 - N Queens`

Contains implementations of the N-Queens problem, exploring backtracking and problem-solving strategies.

### `Aula 07 - Arvore Binaria`

Contains binary tree examples, binary search trees, a decision tree inspired by Akinator, and Huffman coding examples.

### `Aula 08 - Fila Prioridade`

Contains priority queue implementations.

### `Exercicios Extras`

Contains additional exercises and support materials related to pointers, dynamic allocation, asymptotic complexity, and abstract data types.

### `Trabalho01`

Contains the first assignment, focused on matrix multiplication and test cases.

### `Trabalho02`

Contains the second assignment, related to the N-Queens problem and stack-based implementations.

### `Trabalho03`

Contains the third assignment, focused on Huffman coding, input/output test cases, and different implementation versions.

### `Trabalhos Entregues`

Contains final submitted versions of assignments, including reports, source code, test files, and supporting materials.

## 🛠️ Technologies Used

* C Programming Language
* GCC Compiler
* Modular programming with `.c` and `.h` files
* Git and GitHub
* Visual Studio Code
* Linux terminal / command-line environment

## ▶️ How to Compile and Run

For a single C file, use:

```bash
gcc filename.c -o output
./output
```

Example:

```bash
gcc main.c -o exec
./exec
```

For projects with multiple source files, compile all required `.c` files together.

Example:

```bash
gcc main.c fila.c filaCircular.c -o exec
./exec
```

For stack-based projects:

```bash
gcc main.c pilha.c -o exec
./exec
```

Some folders include input files such as `.in`, `.out`, `.csv`, or `.txt`. These files may be used as test cases for specific exercises and assignments.

## 🧩 Example Concepts Practiced

Some of the concepts practiced in this repository include:

* Recursive functions
* Stopping conditions in recursion
* Tower of Hanoi
* Sequential and binary search
* Abstract data types
* Linked lists
* Static and dynamic queues
* Circular queues
* Stacks
* Parenthesis validation using stacks
* Maze solving
* Backtracking
* N-Queens problem
* Binary trees
* Binary search trees
* Tree traversal
* Decision trees
* Priority queues
* Huffman coding
* Matrix multiplication
* Asymptotic complexity
* Modular programming in C

## 🧮 Algorithms and Data Structures Concepts

This repository explores how data can be organized and manipulated efficiently in memory.

The main concepts include:

* **Recursion:** solving problems by breaking them into smaller instances of the same problem.
* **Abstract Data Types:** separating the logical behavior of a structure from its implementation.
* **Linked Lists:** storing elements dynamically using nodes and pointers.
* **Queues:** processing elements in first-in, first-out order.
* **Stacks:** processing elements in last-in, first-out order.
* **Priority Queues:** processing elements according to priority instead of insertion order.
* **Trees:** representing hierarchical relationships between data.
* **Binary Search Trees:** organizing data to support efficient search, insertion, and removal.
* **Backtracking:** exploring possible solutions and undoing choices when necessary.
* **Huffman Coding:** using binary trees to build variable-length encodings.

## 📌 Notes

This repository is intended for academic study and personal learning documentation. Some folders contain isolated exercises, while others contain complete projects with multiple source files, headers, test cases, and reports.

The main source files are the `.c` and `.h` files. Compiled binaries and object files are generated during local execution and do not need to be stored in the repository.

## 👨‍💻 Author

Developed by **Luis Gustavo Riso** as part of the Algorithms and Data Structures course at UNIFEI.

GitHub: [LuisRiso](https://github.com/LuisRiso)
