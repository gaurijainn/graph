// Leetcode 802
// Find Eventual Safe States
// TC -> O(N + E) SC -> O(2N)

// Reverse the edges and do topo sort

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
                adj[graph[i][j]].push_back(i);
                indeg[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++) if(indeg[i] == 0) q.push(i);

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        sort(topo.begin(), topo.end());
        return topo;
    }
};