#include <iostream>
#include "GaussianSolver.h"
#include "Ybus.h"

int main() {
    ComplexMatrix Y = Ybus("ieee14_line_data.txt", 0);
    
    // Mock Current Injections (I_bus) for the IEEE 14-Bus System
// Mock Current Injections (I_bus) for the IEEE 14-Bus System
    ComplexVector I_bus = {
        { 1.50, -0.20},  // Bus 1 (Generator)
        { 0.40, -0.10},  // Bus 2 (Generator/Load)
        {-0.80, -0.20},  // Bus 3 (Load)
        {-0.40, -0.10},  // Bus 4 (Load)
        {-0.05, -0.02},  // Bus 5 (Load)
        { 0.20,  0.05},  // Bus 6 (Generator)
        { 0.00,  0.00},  // Bus 7 (Transit)
        { 0.10,  0.05},  // Bus 8 (Generator)
        {-0.25, -0.10},  // Bus 9 (Load)
        {-0.08, -0.04},  // Bus 10 (Load)
        {-0.03, -0.01},  // Bus 11 (Load)
        {-0.05, -0.01},  // Bus 12 (Load)
        {-0.12, -0.05},  // Bus 13 (Load)
        {-0.14, -0.06}   // Bus 14 (Load)
    };

// Assuming you have built your Y_bus ComplexMatrix...
// ComplexVector V_bus = GaussianSolver(Y_bus, I_bus);
    // 3. Solve for the exact system voltages
    ComplexVector V_bus = GaussianSolver(Y, I_bus);
    
    // 4. Print results
    for(size_t i = 0; i < V_bus.size(); i++){
        std::cout << "Bus " << i+1 << " Voltage = " 
                  << V_bus[i].real() << " + " << V_bus[i].imag() << "j\n";
    }

    return 0;
}
