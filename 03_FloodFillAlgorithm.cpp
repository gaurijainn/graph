// Leetcode 733
// Flood Fill
// TC -> O(N*N) SC -> O(N*N)

// can be done using bfs or dfs

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};

        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int initial = image[sr][sc];
        q.push({sr, sc});
        vis[sr][sc] = 1;
        image[sr][sc] = color;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;

            for(int i=0; i<4; i++){
                int nrow = r + row[i];
                int ncol = c + col[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initial && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    image[nrow][ncol] = color;
                }
            }
        }

        return image;
    }
};