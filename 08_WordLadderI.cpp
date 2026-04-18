// Leetcode 127
// Word Ladder

// we do level wise bfs here with characters, we start from begin word and for each word we change one char n check.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int cnt = 0;
        while(!q.empty()){
            int s = q.size();
            set<string> used;
            cnt++;

            while(s--){
                string curr = q.front();
                q.pop();
            
                if(curr == endWord){
                    return cnt;
                }

                for(int i=0; i<curr.size(); i++){
                    char letter = curr[i];
                    for(int j=0; j<26; j++){
                        curr[i] = 'a' + j;
                        if(st.find(curr) != st.end()){
                            used.insert(curr);
                            q.push(curr);
                        }
                    }
                    curr[i] = letter;
                }
            }

            for(auto it : used){
                st.erase(st.find(it));
            }
        }
        return  0;
    }
};