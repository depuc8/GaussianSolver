#include <iostream>
#include <vector>
#include <complex>
#include "../include/GaussianSolver.h"

// Helper function to print Real results
void print_result(const std::string& test_name, const std::vector<double>& ans) {
    std::cout << "=== " << test_name << " ===\n";
    if (ans.empty()) {
        std::cout << "Solver returned no solution (Error handled safely).\n\n";
        return;
    }
    for (size_t i = 0; i < ans.size(); i++) {
        std::cout << "x[" << i << "] = " << ans[i] << "\n";
    }
    std::cout << "\n";
}

// Helper function to print Complex results
void print_result(const std::string& test_name, const ComplexVector& ans) {
    std::cout << "=== " << test_name << " ===\n";
    if (ans.empty()) {
        std::cout << "Solver returned no solution (Error handled safely).\n\n";
        return;
    }
    for (size_t i = 0; i < ans.size(); i++) {
        std::cout << "x[" << i << "] = " << ans[i].real() 
                  << (ans[i].imag() >= 0 ? " + " : " - ") 
                  << std::abs(ans[i].imag()) << "j\n";
    }
    std::cout << "\n";
}

int main() {
    // ---------------------------------------------------------
    // TEST 1: Real Numbers (Separate A and B)
    // System:  2x + y = 8
    //         -3x - y = -11
    // Expected: x = 3, y = 2
    // ---------------------------------------------------------
    std::vector<std::vector<double>> A_real = {{2.0, 1.0}, {-3.0, -1.0}};
    std::vector<double> B_real = {8.0, -11.0};
    
    std::vector<double> ans1 = GaussianSolver(A_real, B_real);
    print_result("TEST 1: Real A & B", ans1);

    // ---------------------------------------------------------
    // TEST 2: Complex Numbers (Separate A and B)
    // System: (0+1j)x + (2)y = (4+1j)
    //         (1)x    + (1)y = (3)
    // ---------------------------------------------------------
    ComplexMatrix A_comp = {
        { {0.0, 1.0}, {2.0, 0.0} },
        { {1.0, 0.0}, {1.0, 0.0} }
    };
    ComplexVector B_comp = { {4.0, 1.0}, {3.0, 0.0} };
    
    ComplexVector ans2 = GaussianSolver(A_comp, B_comp);
    print_result("TEST 2: Complex A & B", ans2);

    // ---------------------------------------------------------
    // TEST 3: Real Numbers (Augmented Matrix)
    // System: x + y + 2z = 9
    //         2x + 4y - 3z = 1
    //         3x + 6y - 5z = 0
    // Expected: x = 1, y = 2, z = 3
    // ---------------------------------------------------------
    std::vector<std::vector<double>> Aug_real = {
        {1.0, 1.0,  2.0, 9.0},
        {2.0, 4.0, -3.0, 1.0},
        {3.0, 6.0, -5.0, 0.0}
    };
    
    std::vector<double> ans3 = GaussianSolver(Aug_real);
    print_result("TEST 3: Real Augmented", ans3);

    // ---------------------------------------------------------
    // TEST 4: Complex Numbers (Augmented Matrix)
    // (Using the same system as Test 1, but complex formatted)
    // ---------------------------------------------------------
    ComplexMatrix Aug_comp = {
        { {2.0, 0.0},  {1.0, 0.0},  {8.0, 0.0} },
        { {-3.0, 0.0}, {-1.0, 0.0}, {-11.0, 0.0} }
    };
    
    ComplexVector ans4 = GaussianSolver(Aug_comp);
    print_result("TEST 4: Complex Augmented", ans4);

    // ---------------------------------------------------------
    // TEST 5: Error Handling (Invalid Matrix Dimensions)
    // Passing a 2x2 matrix instead of an expected 2x3 augmented
    // ---------------------------------------------------------
    std::vector<std::vector<double>> Aug_bad = {
        {1.0, 2.0}, 
        {3.0, 4.0}
    };
    
    std::cout << "--- The next line should print an expected error message ---\n";
    std::vector<double> ans5 = GaussianSolver(Aug_bad);
    print_result("TEST 5: Invalid Dimensions Check", ans5);

    return 0;
}
