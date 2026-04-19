// Leetcode 802
// Find Eventual Safe States
// TC -> O(N + E) SC -> O(2N)

// Reverse the edges and do topo sort

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
        map<char, vector<char>> adj;
        map<char, int> indegree;
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].size(); j++) indegree[words[i][j]] = 0;
        }
        for(int i=0; i<words.size()-1; i++){
            int n1 = words[i].size();
            int n2 = words[i+1].size();
            int mini = min(n1, n2);
            bool f = 0;
            for(int j=0; j<mini; j++){
                if(words[i][j] != words[i+1][j]) {
                    adj[words[i][j]].push_back(words[i+1][j]);
                    indegree[words[i+1][j]]++;
                    f = 1;
                    break;
                }
            }
            if(!f && n1 > n2) return "";
        }
        queue<char> q;
        for(auto it : indegree) if(it.second == 0) q.push(it.first);
        
        string topo = "";
        while(!q.empty()){
            char node = q.front();
            q.pop();
            topo += node;
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        if(topo.length() == indegree.size()) return topo;
        return "";
    }
};