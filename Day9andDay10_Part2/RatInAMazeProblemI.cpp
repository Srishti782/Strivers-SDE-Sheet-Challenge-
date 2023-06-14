#include <bits/stdc++.h> 
using namespace std;
class Solution{
    public:
    void helper(int i, int j, vector<vector<int>> &m, int n, string path, vector<string> &ans, vector<vector<int>> &visited){
        if(i == n - 1 && j == n - 1){
            ans.push_back(path);
            return;
        }
        
        // Downward
        if(i + 1 < n && m[i + 1][j] == 1 && visited[i + 1][j] == 0){
            visited[i][j] = 1;
            helper(i + 1, j, m, n, path + 'D', ans, visited);
            visited[i][j] = 0;
        }
        
        // Left
        if(j - 1 >= 0 && m[i][j - 1] == 1 && visited[i][j - 1] == 0){
            visited[i][j] = 1;
            helper(i, j - 1, m, n, path + 'L', ans, visited);
            visited[i][j] = 0;
        }
        
        // Right
        if(j + 1 < n && m[i][j + 1] == 1 && visited[i][j + 1] == 0){
            visited[i][j] = 1;
            helper(i, j + 1, m, n, path + 'R', ans, visited);
            visited[i][j] = 0;
        }
        
        // Upwards
        if(i - 1 >= 0 && m[i - 1][j] == 1 && visited[i - 1][j] == 0){
            visited[i][j] = 1;
            helper(i - 1, j, m, n, path + 'U', ans, visited);
            visited[i][j] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector <int>> visited(n, vector<int>(n, 0));
        vector<string> ans;
        if(m[0][0] == 1){
            helper(0, 0, m, n, "", ans, visited);
        }
        return ans;
    }
};
