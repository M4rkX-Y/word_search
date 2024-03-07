# Word Search

## Description

The application uses different sorting algorithm to sort a lists of words. Then the program load word grids and search through the grid to find matching words using binary search.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)

## Installation

Run the following code inside each part's folder

```
make
```

## Usage

Run the program by

```
./main
```

To clean up the object files, run

```
make clean
```

For Part B, to change the sorting algorithms change the integer parameter of the "search()" function in main.

```
search(0) // selection sort
search(1) // quick sort
search(2) // heap sort
```
