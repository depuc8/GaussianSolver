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

## Power-System Application

The `example/` directory contains a demonstration of GaussianSolver being used with a complex **Y-bus matrix** for an IEEE 14-bus power system.

## Issues/Bugs

If you encounter a bug, unexpected behavior, incorrect results, or any other issue, please open an Issue in this repository.
