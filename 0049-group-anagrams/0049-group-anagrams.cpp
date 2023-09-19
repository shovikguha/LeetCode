class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<string,vector<string>> mp;
        
        for(auto s : strs){
            string tmp = s;
            sort(s.begin(),s.end());
            mp[s].push_back(tmp);
        }
        
        for ( const auto &myPair : mp ) {
            ret.push_back(myPair.second);
        }
        
        return ret;
    }
};