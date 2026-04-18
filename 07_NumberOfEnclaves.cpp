// Leetcode 130
// Surrounded Regions
// TC -> O(N*N) SC -> O(N*N)

// add boundary 1 to queue

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    cnt++;
                    if(i == 0 || i == n-1 || j == 0 || j == m-1) {q.push({i, j}); grid[i][j] = 0; cnt--;}
                }
            }
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
                if(row >=0 && row < n && col >= 0 && col < m && grid[row][col] == 1){
                    grid[row][col] = 0;
                    q.push({row, col});
                    cnt--;
                }
            }
        }
        return cnt;
    }
};