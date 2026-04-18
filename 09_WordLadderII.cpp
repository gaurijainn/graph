// Leetcode 127
// Word Ladder
/*
N = number of words in wordList
L = length of each word
K = number of shortest paths (output size)
cnt = length of each part

TC -> O(N*L*26*log(N) + K*cnt) SC -> O(N + parent_map + recursion_stack)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(string word, string& beginWord, unordered_map<string, vector<string>>& parent, vector<string>& path, vector<vector<string>>& ans){
        if(word == beginWord){
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        for(auto it : parent[word]){
            path.push_back(it);
            dfs(it, beginWord, parent, path, ans);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int cnt = 0;
        bool f = 0;
        unordered_map<string, vector<string>> parent;
        while(!q.empty() && !f){
            int s = q.size();
            unordered_set<string> used;
            if(!f) cnt++;

            while(s--){
                string original = q.front();
                string curr = original;
                q.pop();
            
                if(curr == endWord){
                    f = 1;
                    continue;
                }

                for(int i=0; i<curr.size(); i++){
                    char letter = curr[i];
                    for(int j=0; j<26; j++){
                        char ch = 'a' + j;
                        if(ch == letter) continue;
                        curr[i] = ch;
                        if(st.count(curr)){
                            if(!used.count(curr)){
                                q.push(curr);
                                used.insert(curr);
                            }
                            parent[curr].push_back(original);
                        }
                    }
                    curr[i] = letter;
                }
            }  

            for(auto &w : used){
                st.erase(w);
            }
        }
        vector<vector<string>> ans;
        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, parent, path, ans);
        return ans;
    }
};