class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> mp;
        int nxt = 1;
        
        vector<vector<string>> ret;
        
        for(int i = 0; i < (int)strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(mp[temp] == 0){
                mp[temp] = nxt;
                nxt++;
                vector<string> ret1 = {strs[i]};
                ret.push_back(ret1);
            }
            else{
                ret[mp[temp] - 1].push_back(strs[i]);
            }
        }
        
        return ret;
    }
};