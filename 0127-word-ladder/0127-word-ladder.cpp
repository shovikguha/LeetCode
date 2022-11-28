class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord){
            return 1;
        }
        
        int n = wordList.size();
        int m = beginWord.length();
        vector<vector<int>> adjlst(n);
        
        for(int i = 0; i < n; i++){
            string s1 = wordList[i];
            for(int j = i + 1; j < n; j++){
                string s2 = wordList[j];
                
                int cnt = 0;
                for(int k = 0; k < m; k++){
                    if(s1[k] != s2[k]){
                        cnt++;
                    }
                }
                
                if(cnt == 1){
                    adjlst[i].push_back(j);
                    adjlst[j].push_back(i);
                }
            }
        }
        
        queue<pair<int,int>> q;
        unordered_map<int,int> seen;
        
        for(int i = 0; i < n; i++){
            string s1 = wordList[i];
            
            int cnt = 0;
            for(int k = 0; k < m; k++){
                if(s1[k] != beginWord[k]){
                    cnt++;
                }
            }

            if(cnt == 1){
                q.push(make_pair(i,2));
                seen[i] = 1;
            }
        }
        
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(wordList[p.first] == endWord){
                return p.second;
            }
            for(int ne: adjlst[p.first]){
                if(seen[ne] == 0){
                    seen[ne] = 1;
                    q.push(make_pair(ne, p.second+1));
                }
            }
        }
        
        return 0;
        
    }
};