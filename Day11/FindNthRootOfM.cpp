#include <bits/stdc++.h>
using namespace std;
int NthRoot(int n, int m) {
  // Write your code here.
  if(n == 1){
    return m;
  }
  if(n == 2){
    return sqrt(m);
  }
  int i = 1;
  while(i <= sqrt(m)){
    if(pow(i, n) == m){
      return i;
    }
    i++;
  }
  return -1;
}