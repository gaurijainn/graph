// Leetcode 733
// Flood Fill
// TC -> O(N*N) SC -> O(N*N)

// can be done using bfs or dfs

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool bfs(int start, vector<int>& vis, vector<vector<int>>& adj){
        queue<pair<int, int>> q;
        q.push({start, -1});
        vis[start] = 1;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it : adj[node]){
                if(!vis[it]) {
                    q.push({it, node});
                    vis[it] = 1;
                }
                else if(it != parent) return true;
            }
        }
        return false;
    }

    bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, node, vis, adj) ==  true) return true;
            } else if(it != parent) return true;
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> vis(V, 0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0; i<V; i++){
            if(!vis[i]) {
                if(dfs(i, -1, vis, adj) == true) return true;
            }
        }
        
        return false;
    }
};