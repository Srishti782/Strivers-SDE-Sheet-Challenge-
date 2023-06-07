#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r){
        int res = 1;
        for(int i = 0; i < r; i++){
            res *= (n-i);
            res /= (i+1);
        }
        return res;
    }
vector<vector<int>> pairSum(vector<int> &a, int target){
   // Write your code here.
   vector<vector<int>> output;
   vector<int> row;
   sort(a.begin(), a.end());
   int i = 0, j = a.size() - 1;
        
   while(i < j){
      if((a[i] + a[j]) < target){
          i++;
      }
      else if((a[i] + a[j]) > target){
         j--;
      }
      else{
         row.push_back(a[i]);
         row.push_back(a[j]);
         if(a[i]*2 == target){
            int p = (j - i + 1);
            int k = nCr(p, 2);
            while(k--){
               output.push_back(row);
            }
            break;
         }
         else if(a[i] == a[i + 1] || a[j] == a[j - 1]){
            int m = 1;
            while(a[i] == a[i + 1]){
               m++;
               i++;
            }
            int n = 1;
            while(a[j] == a[j - 1]){
               n++;
               j--;
            }
            int c = m*n;
            while(c--){
               output.push_back(row);
            }
         }
         else{
            output.push_back(row);
         }
         
         row.clear();
         i++;
         j--;
      }
   }
   return output;
}