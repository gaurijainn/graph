// Leetcode 207 
// Course Schedule I
// TC -> O(N + E) SC -> O(2N) (Topological Sort)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(int i=0; i<p.size(); i++){
            adj[p[i][1]].push_back(p[i][0]);
            indegree[p[i][0]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++) if(indegree[i] == 0) q.push(i);
        
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
        return topo.size() == n;
    }
};