#include <bits/stdc++.h>
using namespace std;
long long nCr(int n, int r){
        long long res = 1;
        for(int i = 0; i < r; i++){
            res *= (n-i);
            res /= (i+1);
        }
        return res;
    }
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>> output;
  vector<long long int> row;
        for(int i = 0; i < n; i++){
            row.clear();
            for(int j = 0; j <= i; j++){
                long long a = nCr(i, j);
                row.push_back(a);
            }
            output.push_back(row);
        }
        return output;
}
