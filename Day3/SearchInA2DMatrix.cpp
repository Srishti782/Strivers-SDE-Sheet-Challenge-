#include<bits/stdc++.h>
using namespace std;
bool search(vector<vector<int>>& matrix, int si, int ei,int n, int m, int k){
        if(si > ei){
            return false;
        }
        int mid = (si + ei)/ 2;
        int i = mid / m;
        int j = mid % m;
        if(k == matrix[i][j]){
            return true;
        }
        else if(k < matrix[i][j]){
            return search(matrix, si, mid - 1, n, m, k);
        }
        else{
            return search(matrix, mid + 1, ei, n, m, k);
        }
    }
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    return search(matrix, 0, (m*n - 1), n, m, target);
        
}