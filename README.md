# Push Swap

Push Swap is a sorting algorithm project developed as part of the 42 École curriculum. The objective of the project is to sort a stack of integers using a limited set of operations.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Algorithm](#algorithm)
- [Performance](#performance)
- [Visualizer](#visualizer)
- [Contact](#contact)

## Introduction

The Push Swap project challenges students to implement an efficient sorting algorithm for arranging a stack of integers in ascending order using two stacks (A and B) and a limited set of operations. The goal is to minimize the number of operations required to sort the stack.

## Features

- Sort a stack of integers using limited operations.
- Visualizer to observe the sorting process.

## Installation

To build and run the Push Swap project, follow these steps:

1. **Clone the repository**
   ```
   git clone https://github.com/your_username/push_swap.git
   cd push_swap

    Build the project

    sh

    make

Usage

To sort a stack of integers, run the compiled executable with integer arguments:

    ./push_swap 5 3 1 4 2

Algorithm

The Push Swap algorithm consists of a series of steps to manipulate the stacks (A and B) to achieve a sorted arrangement. The algorithm involves various operations such as swapping elements, rotating elements, and pushing elements between stacks.
Example Operations

    sa: Swap the first two elements of stack A.
    sb: Swap the first two elements of stack B.
    ra: Rotate stack A (shift all elements up by one).
    rb: Rotate stack B (shift all elements up by one).
    pa: Push the top element of stack B onto stack A.
    pb: Push the top element of stack A onto stack B.

Performance

The efficiency of the Push Swap algorithm depends on the input size and the chosen sorting strategy. Various strategies can be implemented, such as insertion sort, selection sort, or advanced algorithms like quicksort or mergesort.
Visualizer

The Push Swap project includes a visualizer to observe the sorting process in real-time. To use the visualizer, follow these steps:

    Build the visualizer

    make bonus

Run the visualizer with integer arguments

    ./push_swap 5 3 1 4 2 | ./checker 5 3 1 4 2

Erik Grigoryan - ergrigor@student.42yerevan.am
