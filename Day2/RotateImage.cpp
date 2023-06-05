#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(i != j){
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp; 
                }
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n =  matrix.size();
        transpose(matrix);
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};