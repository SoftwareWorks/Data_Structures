# Data Structures
## Purpose
This is a sandbox repository for playing with more or less exotic versions of data structures. Every data structure in here should be subject to the modern C++ standards (for now, excluding C++17) and correct by construction. Algorithmic elements and notations used in this document are based on the 3rd edition of [Introduction to Algorithms](https://www.amazon.com/Introduction-Algorithms-3rd-MIT-Press/dp/0262033844).

## License & Warranty
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Code is released under MIT License. It can be freely used as long as the original creator is attributed. Software provided comes with no warranty.

## Table of Contents
 - [Linked Lists](#linked-lists)
   - [Doubly Linked List](#doubly-linked-list)

## <a name = "linked-lists" />Lists
Linked lists are basic, node-based structures in which nodes are connected directly to one another in a linear order using links created by some kind of object-pointing mechanism (e.g. pointers or references). Considering a linked list with n elements, three basic operations can be distinguished:
 - `search` - finding the desired element in the linked list takes O(n) time;
 - `insert` - inserting an element into a certain position in the linked list takes O(1) time, provided a handle to that position (otherwise `search` needs to be performed first);
 - `delete` - deleting an element from the linked list takes O(1) time, provided a handle to the object to be deleted (otherwise `search` needs to be performed first);

Linked lists in general do not occupy a contiguous sequence of memory. The C++ Standard Library provides linked lists in the [`<list>`](http://en.cppreference.com/w/cpp/container/list) header.

### <a name = "doubly-linked-list" />Doubly Linked List
