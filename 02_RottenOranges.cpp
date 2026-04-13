// Leetcode 994
// Rotten Oranges
// TC -> O(N*N) SC -> O(N*N)

// do BFS cause we need minimum time, have to push <<row, col>, time> in queue

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int fresh = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2) q.push({{i, j}, 0});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        int ans = 0, now_rotten = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int time = it.second;
            if(ans < time) ans = time;

            for(int i=0; i<4; i++){
                int row = r + dr[i];
                int col = c + dc[i];
                if(row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 1){
                    now_rotten++;
                    grid[row][col] = 2;
                    q.push({{row, col}, time + 1});
                }
            }
        }
        if(now_rotten != fresh) return -1;
        return ans;
    }
};