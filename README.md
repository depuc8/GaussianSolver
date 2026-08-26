# GaussianSolver

A flexible, memory-safe, and optimized linear system solver written in modern **C++17**.

GaussianSolver solves linear systems of the form:

$$
Ax = B
$$

using **Gaussian Elimination with partial pivoting**. It supports both real and complex numbers, making it suitable for standard linear algebra as well as electrical engineering applications such as power-system analysis and power-flow calculations.


## Project Structure

```text
GaussianSolver/
├── example/
│   └── ...
├── GaussianSolver.h
├── Makefile
├── main.cpp
└── README.md
```

## Compilation

This project uses a standard `Makefile` and `g++` with the **C++17** standard.

No external dependencies are required.

### Build

```bash
make
```

### Run

The compiled executable does not require command-line arguments:

```bash
./solution
```

### Clean and Rebuild

To remove generated files and perform a fresh build:

```bash
make clean
make rebuild
```

## API Usage

Include the solver header:

```cpp
#include "GaussianSolver.h"
```

GaussianSolver provides several interfaces depending on the format of your input matrices.

### 1. Real-valued matrices

```cpp
std::vector<double> ans = GaussianSolver(A_real, B_real);
```

### 2. Complex-valued matrices

```cpp
ComplexVector ans = GaussianSolver(A_complex, B_complex);
```

### 3. Real augmented matrix

```cpp
std::vector<double> ans = GaussianSolver(Augmented_real);
```

### 4. Complex augmented matrix

```cpp
ComplexVector ans = GaussianSolver(Augmented_complex);
```

## Mathematical Overview

For a system of linear equations

$$
Ax = B
$$

Gaussian elimination transforms the system into an upper triangular form, after which **back substitution** is used to obtain the solution vector.

Partial pivoting is used during elimination by selecting an appropriate pivot element at each step. This improves numerical stability, particularly when working with floating-point values.

This makes the solver particularly useful for applications involving complex-valued electrical quantities.

## Power-System Application

The `example/` directory contains a demonstration of GaussianSolver being used with a complex **Y-bus matrix** for an IEEE 14-bus power system.

The example demonstrates a practical workflow involving:

1. Reading transmission-line data.
2. Generating the Y-bus admittance matrix.
3. Constructing a complex linear system.
4. Solving the system using Gaussian elimination.
5. Calculating complex bus voltages.

## Issues/Bugs

If you encounter a bug, unexpected behavior, incorrect results, or any other issue, please open an Issue in this repository.
