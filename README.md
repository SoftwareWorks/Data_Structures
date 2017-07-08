# Data Structures
## Purpose
This is a sandbox repository for playing with more or less exotic versions of data structures. Every data structure in here should be subject to the modern C++ standards (for now, excluding C++17) and correct by construction. Algorithmic elements and notations used in this document are based on the 3rd edition of [Introduction to Algorithms](https://www.amazon.com/Introduction-Algorithms-3rd-MIT-Press/dp/0262033844).

## License & Warranty
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Code is released under MIT License. It can be freely used as long as the original creator is attributed. Software provided comes with no warranty.

## Table of Contents
 - [Linked Lists](#linked-lists)
   - [Doubly Linked List](#doubly-linked-list)

## <a name="linked-lists" />Linked Lists
Linked lists are basic, node-based structures in which nodes are connected directly to one another in a linear order using links created by some kind of object-pointing mechanism (e.g. pointers or references). Considering a linked list with n elements, three basic operations can be distinguished:
 - `search` - finding the desired element in the linked list takes O(n) time;
 - `insert` - inserting an element into a certain position in the linked list takes O(1) time, provided a handle to that position is in possession (otherwise `search` needs to be performed first);
 - `delete` - deleting an element from the linked list takes O(1) time, provided a handle to the object to be deleted is in possession (otherwise `search` needs to be performed first);

Insertions and deletions are particularly fast, because they are performed basically by exchanging links. Searching runs in linear time since there is no way to randomly access list elements. At worst case, whole list may be traversed.

Because of its nodal nature, linked lists in general do not occupy a contiguous sequence of memory. The C++ Standard Library provides linked lists in the [`<list>`](http://en.cppreference.com/w/cpp/header/list) header.

### <a name="doubly-linked-list" />Doubly Linked List
Doubly linked list is probably the most widely used version of all linked lists (at least in the structural sense). The name comes from the fact, that each element of the list contains two links: `next`, linking to the next element, and `prev`, linking to the previous element. Elements also contain a field called `key` which represents some actual data being stored in the element (either directly in or as an [`unique_ptr`](http://en.cppreference.com/w/cpp/memory/unique_ptr) to some outside location). Pointer to the first element called `head` is stored in the list object itself. In other versions last element (pointer `tail`) may also be tracked.

<p align="center">
  <img src="https://github.com/ignmiz/Images/blob/master/Data_Structures/doubly_linked_list.png">
</p>

Doubly linked list can be correct by construction by using [`unique_ptr`](http://en.cppreference.com/w/cpp/memory/unique_ptr) in one link direction, and raw pointer `*` in the another direction. In this implementation [`unique_ptr`](http://en.cppreference.com/w/cpp/memory/unique_ptr) points forward and also constitutes a `head` of the list. Such arrangement guarantees a proper resource deallocation when the list goes out of scope or some link is broken.

The templatized source code for the doubly linked list is provided in [`list.h`](https://github.com/ignmiz/Data_Structures/blob/master/Lists/Doubly_Linked_List/list.h) and contains some I/O instructions in constructors and destructors that help to verify that. Bear in mind that when using them, the template type must be ostreamable (must contain `operator<<` for [`std::ostream`](http://en.cppreference.com/w/cpp/io/basic_ostream)). [`main.cpp`](https://github.com/ignmiz/Data_Structures/blob/master/Lists/Doubly_Linked_List/main.cpp) then tests the list allocation and the basic operations printing the results along the way.
