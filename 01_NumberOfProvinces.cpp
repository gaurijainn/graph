// Leetcode 547
// Number Of Provinces
// TC -> O(N*N) SC -> O(N)

// we can use bfs/dfs traversal OR DSU

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, vis, adj);
        }
    }
    void bfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        queue<int> q;
        vis[node] = 1;
        q.push(node);

        while(!q.empty()){
            node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        
        int provinces = 0;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                provinces++;
                bfs(i, vis, adj);
            }
        }

        return provinces;
    }
};

class Solution1 {
public:
    class Disjoint_Set{
    public:
        vector<int> parent, size;
        int components;

        Disjoint_Set(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);
            components = n;
            for(int i=0; i<=n; i++){
                parent[i] = i;
            }
        }

        int find(int node){
            if(parent[node] == node) return node;
            return parent[node] = find(parent[node]);
        }

        bool unionBySize(int u, int v){
            int pu = find(u);
            int pv = find(v);
            if(pu == pv) return false;

            if(size[pu] < size[pv]) swap(pu, pv);
            parent[pv] = pu;
            size[pu] += size[pv];
            components--;
            return true;
        }
    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        Disjoint_Set dsu(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]) dsu.unionBySize(i, j);
            }
        }

        return dsu.components;     
    }
};