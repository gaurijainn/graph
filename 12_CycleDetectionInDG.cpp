// Cycle Detection in Directed Graph
// TC -> O(N + E) SC -> O(N) [DFS] (using vis & pathVis)
// TC -> O(N + E) SC -> O(2N) [BFS - Kahn Algorithm]

#include<bits/stdc++.h>
using namespace std;

class Solution1 {
  public:
    bool dfs(int node, vector<int>& vis, vector<int>& pVis, vector<vector<int>>& adj) {
        vis[node] = 1;
        pVis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, pVis, adj) == true) return true;
            } else if(pVis[it]) return true;
        }
        pVis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        vector<int> vis(V, 0), pVis(V, 0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0; i<V; i++){
            if(!vis[i]) {
                if(dfs(i, vis, pVis, adj) ==  true) return true;
            }
        }
        return false;
    }
};

class Solution2 {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        queue<int> q;
        for(int i=0; i<V; i++) if(indegree[i] == 0) q.push(i);
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        return topo.size() != V;
    } 
};