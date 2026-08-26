# Example: IEEE 14-Bus Voltage Solver

This directory contains a real-world electrical engineering application of the `GaussianSolver`. It calculates the complex bus voltages of the standard IEEE 14-bus power system by solving a 14x14 linear network equation.

## Overview

In power system analysis, the relationship between nodal current injections ($I_{bus}$), bus voltages ($V_{bus}$), and the network admittance ($Y_{bus}$) is defined by:
$$I_{bus} = Y_{bus} V_{bus}$$

This example demonstrates how to use the `GaussianSolver` to solve for $V_{bus}$. It integrates the solver backend with the matrix generation parser from [depuc8/Ybus](https://github.com/depuc8/Ybus).

## How It Works

1. **Parsing:** The program reads `ieee14_line_data.txt`, extracting branch impedances and transformer tap ratios.
2. **Modeling:** It constructs a 14x14 complex Admittance Matrix ($Y_{bus}$).
3. **Solving:** It applies a set of mock current injections ($I_{bus}$) and uses the `GaussianSolver` to solve the 14x14 complex system.
4. **Output:** The resulting voltages for all 14 buses are printed to the terminal in rectangular coordinates.

## Compilation & Execution

This example includes its own `Makefile`. To build and run the 14-bus simulation, use the following commands:

```bash
# Compile the example
make

# Run the simulation
./voltages

```
```bash
#Cleaning up
make clean
```

## Issues/Bugs

If you encounter a bug, unexpected behavior, incorrect results, or any other issue, please open an Issue in this repository.
