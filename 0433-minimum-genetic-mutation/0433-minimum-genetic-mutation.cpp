class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        map<string, vector<string>> mp;
        
        for(int i = 0; i < (int)bank.size(); i++){
            for(int j = i + 1; j < (int)bank.size(); j++){
                int cnt = 0;
                for(int k = 0; k < 8; k++){
                    if(bank[i][k] != bank[j][k]){
                        cnt++;
                    }
                }
                if(cnt < 2){
                    mp[bank[i]].push_back(bank[j]);
                    mp[bank[j]].push_back(bank[i]);
                }
            }
        }
        
        for(int i = 0; i < (int)bank.size(); i++){
            int cnt = 0;
            for(int k = 0; k < 8; k++){
                if(bank[i][k] != start[k]){
                    cnt++;
                }
            }
            if(cnt < 2){
                mp[bank[i]].push_back(start);
                mp[start].push_back(bank[i]);
            }
        }
        
        map<string, int> seen;
        queue<pair<string,int>> q;
        q.push(make_pair(start,0));
        
        while(!q.empty()){
            pair<string,int>p = q.front();
            q.pop();
            
            if(p.first == end){
                return p.second;
            }
            
            seen[p.first] = 1;
            for(string ne: mp[p.first]){
                if(seen[ne] == 0){
                    q.push(make_pair(ne, p.second + 1));
                }
            }
        }
        
        return -1;
        
    }
};