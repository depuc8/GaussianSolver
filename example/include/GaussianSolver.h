#ifndef GAUSSIANSOLVER_H
#define GAUSSIANSOLVER_H

#include<iostream>
#include<vector>
#include<complex>

using ComplexDouble = std::complex<double>;
using ComplexVector = std::vector<ComplexDouble>;
using ComplexMatrix = std::vector<ComplexVector>;

ComplexMatrix make_augmented(const ComplexMatrix &A, const ComplexVector &B);
ComplexVector solve_system(ComplexMatrix aug);
ComplexVector GaussianSolver(const ComplexMatrix &A, const ComplexVector &B);
ComplexVector GaussianSolver(const ComplexMatrix &aug);

template <typename T>
ComplexMatrix to_ComplexMatrix(const std::vector<std::vector<T>>& inputMatrix){
    size_t rows = inputMatrix.size();
    size_t columns = inputMatrix[0].size();

    ComplexMatrix result(rows,ComplexVector(columns));
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < columns; j++){
            result[i][j] = ComplexDouble(static_cast<double>(inputMatrix[i][j]),0.0);
        }
    }
    return result;
}

template <typename T>
ComplexVector to_ComplexVector(const std::vector<T> &inputVector){
    size_t size = inputVector.size();
    ComplexVector result(size);
    for(size_t i = 0; i < size; i++){
        result[i] = ComplexDouble(static_cast<double>(inputVector[i]),0.0);
    }
    return result;
}

template <typename T> 
bool GaussianCompatible(const std::vector<std::vector<T>> &A,const std::vector<T> &B){
    //Matrix A has to be a square matrix 
    size_t size = A.size();
    for(auto &x : A){
        if(x.size() != size){
            std::cerr<<"Error: Provide valid number of coefficients\n";
            return false;
        }
    }
    if(B.size() != size){
        std::cerr<<"Error: Provide valid number of constants\n";
        return false;
    }
    return true;

}

template <typename T>
std::vector<double> GaussianSolver(const std::vector<std::vector<T>> &A,const std::vector<T> &B){
    if(!GaussianCompatible(A,B)){
        std::cerr<<"Error: Invalid input matrices\n";
        return {};
    } 

    ComplexMatrix A_comp = to_ComplexMatrix(A);
    ComplexVector B_comp = to_ComplexVector(B);
    
    ComplexMatrix augmented = make_augmented(A_comp,B_comp);
    ComplexVector solution_comp = solve_system(augmented);

    std::vector<double> real_solution(solution_comp.size());
    for(size_t i = 0; i < solution_comp.size(); i++){
        real_solution[i] = solution_comp[i].real();
    }
    return real_solution;
}

template<typename T>
bool CheckAugmented(const std::vector<std::vector<T>>& aug){
    
    size_t rows = aug.size();
    if(rows == 0) return false;
    
    size_t expected_cols = rows+1;
    for(const auto& x: aug){
        if(x.size() != expected_cols){
            std::cerr<<"Error: Augmented matrix must be N x (N+1)\n";
            return false;
        }
    }
    return true;
}

template <typename T>
std::vector<double> GaussianSolver(const std::vector<std::vector<T>>& aug){
    if(!CheckAugmented(aug)){
        return {};
    }

    ComplexMatrix aug_comp = to_ComplexMatrix(aug);
    ComplexVector solution_comp = solve_system(aug_comp);

    std::vector<double> solution(solution_comp.size());
    for(size_t i = 0; i < solution_comp.size(); i++){
        solution[i] = solution_comp[i].real();
    }
    return solution;
}
#endif 
