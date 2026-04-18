// Leetcode 130
// Surrounded Regions
// TC -> O(N*N) SC -> O(N*N)

// add boundary O to queue

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O') {q.push({i, 0}); board[i][0] = '$';}
            if(board[i][m-1] == 'O') {q.push({i, m-1}); board[i][m-1] = '$';}
        }
        for(int j=1; j<m-1; j++){
            if(board[0][j] == 'O') {q.push({0, j}); board[0][j] = '$';}
            if(board[n-1][j] == 'O') {q.push({n-1, j}); board[n-1][j] = '$';}
        }
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            
            for(int i=0; i<4; i++){
                int row = r + dr[i];
                int col = c + dc[i];
                if(row >= 0 && row < n && col >=0 && col < m && board[row][col] == 'O'){
                    board[row][col] = '$';
                    q.push({row, col});
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '$') board[i][j] = 'O';
            }
        }
        return;
    }
};