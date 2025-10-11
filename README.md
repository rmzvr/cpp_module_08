# C++ Module 08 – Templated Containers, Iterators, Algorithms (42 Cursus)

## Overview

This repository contains the solutions for **Module 08** of the 42 School C++ curriculum. The exercises in this module introduce the Standard Template Library (STL) and focus on templated containers, iterators, and algorithms. This module marks the first time STL containers and algorithms are allowed and encouraged. All code follows the educational guidelines and coding conventions specified for the course.

## Learning Outcomes

- **Master STL containers** (vector, list, map, etc.) and understand their appropriate use cases.
- **Understand iterators and algorithms** from the `<algorithm>` header for efficient data manipulation.
- **Practice template programming** with containers and custom template implementations.
- **Develop efficient search algorithms** using STL containers and iterators.
- **Implement custom container classes** that integrate seamlessly with STL patterns.
- **Enhance problem-solving skills** by leveraging STL features for complex data operations.

## Educational Purpose

The main objectives of this module are:

- **Introduce the Standard Template Library (STL)** with emphasis on containers and algorithms.
- **Enable efficient data manipulation** using iterators and STL algorithms.
- **Practice creating STL-compatible custom containers** with proper iterator support.
- **Gain experience with exception handling** in container operations.
- **Strengthen understanding of template programming** through practical STL usage.
- **Prepare for advanced C++ programming** using modern STL features and patterns.

## Module Content and Implementation

### Exercise 00: Easy Find

**Directory:** `ex00/`  
**Main Files:** `easyfind.hpp`, optional `easyfind.tpp`

- Implements a function template:
  - `easyfind(T container, int value)`: Finds the first occurrence of an integer value in a container.
- Works with any STL container of integers (vector, list, deque, etc.).
- Returns an iterator to the found element or throws an exception if not found.
- Demonstrates basic use of STL containers and iterators for search operations.
- Tested in `main.cpp` with various container types to ensure template flexibility.

### Exercise 01: Span

**Directory:** `ex01/`  
**Main Files:** `Span.hpp`, `Span.cpp`

- Implements the `Span` class:
  - Constructor with maximum size parameter (unsigned int).
  - `addNumber()`: Adds a single number, throws exception if container is full.
  - `shortestSpan()`: Returns the shortest distance between any two stored numbers.
  - `longestSpan()`: Returns the longest distance between any two stored numbers.
  - Range-based addition using iterators for efficient bulk insertion.
- Uses STL containers internally for efficient storage and algorithms for span calculations.
- Throws exceptions for invalid operations (empty container, single element, overflow).
- Tested with large datasets (10,000+ numbers) to demonstrate performance and correctness.

### Exercise 02: Mutated Abomination

**Directory:** `ex02/`  
**Main Files:** `MutantStack.hpp`, optional `MutantStack.tpp`

- Implements the `MutantStack` class template:
  - Inherits from or contains `std::stack` to provide all standard stack operations.
  - Adds iterator support to make `std::stack` iterable.
  - Provides `begin()` and `end()` methods returning appropriate iterators.
  - Maintains all original stack functionality (push, pop, top, size, empty).
- Demonstrates how to extend STL containers with additional functionality.
- Compatible with STL algorithms that require iterators.
- Tested to ensure behavior matches equivalent STL containers (like `std::list`) when iterated.

## Module-Specific Rules

- **STL Usage Required**: This module specifically requires the use of STL containers and algorithms.
- **Template Implementation**: Templates can be implemented in header files or split between `.hpp` and `.tpp` files.
- **Iterator Support**: Custom containers should provide proper iterator interfaces when applicable.
- **Exception Safety**: All container operations should handle exceptions appropriately.
- **Performance Considerations**: Solutions should demonstrate efficient use of STL features.

## How to Build and Run

Each exercise folder contains a `Makefile` for easy compilation.  
To build and run an exercise, for example `ex00`:

```bash
cd ex00
make
./ex00
```

Repeat for `ex01` and `ex02` with their respective executables.
