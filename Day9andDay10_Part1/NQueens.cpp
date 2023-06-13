#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool isSafe(int r, int c, vector<string> &board, int n){
        for(int i = 0; i < r; i++){
            if(board[i][c] == 'Q') return false;
        }

        int i = r - 1, j = c - 1;

        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }

        i = r - 1, j = c + 1;
        while(i >= 0 && j < n){
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }

        return true;
    }

    void solve(int row, vector<string> &board, int n, vector<vector<string>> & ans){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int j = 0; j < n; j++){
            if (isSafe(row, j, board, n)) {
                board[row][j] = 'Q';
                solve(row + 1, board, n, ans);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string row(n, '.');
        for(int i = 0; i < n; i++){
            board[i] = row;
        }
        vector<vector<string>> ans;
        solve(0, board, n, ans);
        return ans;
    }
};