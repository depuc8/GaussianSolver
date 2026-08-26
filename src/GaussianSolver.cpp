#include<algorithm>
#include<cmath>
#include"../include/GaussianSolver.h"

ComplexMatrix make_augmented(const ComplexMatrix &A, const ComplexVector &B){
    size_t rows = A.size();
    ComplexMatrix aug = A;
    for(size_t i = 0; i < rows; i++){
        aug[i].push_back(B[i]);
    }
    return aug;

}

ComplexVector solve_system(ComplexMatrix aug){
    
    int N = aug.size();

    //Forward Elmination
    for(int k = 0; k <= N-1; k++){
        int maxRow = k;
        //Partial Pivoting
        for(int i = k+1;i < N; i++){
            maxRow = (std::abs(aug[i][k]) > std::abs(aug[maxRow][k])) ? i : maxRow;
        }

        if(maxRow != k){
            std::swap(aug[maxRow],aug[k]);
        } 
        
        for(int i = k + 1; i < N; i++){
            ComplexDouble factor = aug[i][k]/aug[k][k];
            for(int j = k; j <= N; j++){
                aug[i][j] = aug[i][j] - factor*aug[k][j];
            }
        }
    }
    
    //Backward Substitution
    ComplexVector solution(N,ComplexDouble(0.0,0.0));
    for(int i = N-1; i >= 0; i--){
        ComplexDouble sum(0.0,0.0);
        for(int j = i+1; j < N; j++){
            sum += aug[i][j]*solution[j];
        }
        solution[i] = (aug[i][N] - sum )/ aug[i][i];
    }
    
    return solution;

}



ComplexVector GaussianSolver(const ComplexMatrix &A, const ComplexVector &B){
    if(!GaussianCompatible(A,B)){
        return {};
    }

    ComplexMatrix augmented = make_augmented(A,B);
    return solve_system(augmented);
}

ComplexVector GaussianSolver(const ComplexMatrix &aug){
    if(!CheckAugmented(aug)){
        return {};
    }
    return solve_system(aug);
}
