// Leetcode 785
// Is Graph Bipartite?
// TC -> O(N + E) SC -> O(N)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int node, int clr, vector<int>& vis, vector<vector<int>>& graph){
        vis[node] = clr;
        for(auto it : graph[node]){
            if(vis[it] ==  -1){
                if(dfs(it, !clr, vis, graph) ==  false) return false;
            } else if(vis[it] == clr) return false;
        }
        return true;
    }
    bool bfs(int start, vector<int>& vis, vector<vector<int>>& graph){
        queue<int> q;
        q.push(start);
        vis[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : graph[node]){
                if(vis[it] == -1){
                    vis[it] = !vis[node];
                    q.push(it);
                } else if(vis[it] == vis[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for(int i=0; i<n; i++){
            if(vis[i] ==  -1){
                if(dfs(i, 0, vis, graph) == false) return false;
            }
        }
        return true;
    }
};