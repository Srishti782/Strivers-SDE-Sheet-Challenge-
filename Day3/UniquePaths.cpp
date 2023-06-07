#include <bits/stdc++.h> 
using namespace std;
int uniquePaths(int m, int n) {
	// Write your code here.
	int** mat = new int*[m];
        for(int i = 0 ; i < m; i++){
            mat[i] = new int[n];
        }
        for(int i = 0; i < m; i++){
            mat[i][n - 1] = 1;
        }
        for(int j = 0; j < n; j++){
            mat[m - 1][j] = 1;
        }
        for(int i = m - 2; i >= 0; i--){
            for(int j = n - 2; j >= 0; j--){
                mat[i][j] = mat[i + 1][j] + mat[i][j + 1];
            }
        }
        return mat[0][0];
}