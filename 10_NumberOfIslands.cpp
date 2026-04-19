// Leetcode 200
// Number Of Islands
// TC -> O(N*L*26*log(N) + K*cnt) SC -> O(N + parent_map + recursion_stack)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[r][c] = 1;
        for(int i=0; i<4; i++){
            int row = r + dr[i];
            int col = c + dc[i];
            if(row >=0 && row < grid.size() && col >=0 && col < grid[0].size() && grid[row][col] == '1' && !vis[row][col]){
                dfs(row, col, vis, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    dfs(i, j, vis, grid);
                } 
            }
        }

        return cnt;
    }
};