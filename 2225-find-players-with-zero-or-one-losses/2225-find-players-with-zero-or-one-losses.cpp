class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mp;
        
        for(auto& v : matches){
            if(mp.find(v[0]) == mp.end()){
                mp[v[0]] = 0;
            }
            mp[v[1]]++;
        }
        vector<vector<int>> ret(2);
        
        for(auto[k,v] : mp){
            if(v == 0){
                ret[0].push_back(k);
            }
            if(v == 1){
                ret[1].push_back(k);
            }
        }
        
        return ret;
    }
};