#include <bits/stdc++.h> 
using namespace std;
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int node, bool graph[101][101], int n, int col, int color[]){
        for(int i = 0; i < n; i++){
            if(i != node && graph[node][i] == 1 && color[i] == col) return false;
        }
        return true;
    }
    bool solve(int node, bool graph[101][101], int n, int m, int color[]){
        if(node == n){
            return true;
        }
        
        for(int i = 1; i <= m; i++){
            if(isSafe(node, graph, n, i, color)){
                color[node] = i;
                if(solve(node + 1, graph, n, m, color)){
                    return true;
                }
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n] = {0};
        return solve(0, graph, n, m, color);
    }
};