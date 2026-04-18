// Leetcode 542
// 01 Marix
// TC -> O(N*N) SC -> O(N*N)

// add 0s to the queue and find 1s via bfs

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        queue<pair<int, pair<int, int>>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({0, {i, j}});
                }
            }
        }
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int i=0; i<4; i++){
                int row = r + dr[i];
                int col = c + dc[i];
                if(row >= 0 && row < n && col >= 0 && col < m && mat[row][col] == 1 && ans[row][col] > dis + 1){
                    ans[row][col] = dis + 1;
                    q.push({dis + 1, {row, col}});
                }
            }
        }
        return ans;
    }
};