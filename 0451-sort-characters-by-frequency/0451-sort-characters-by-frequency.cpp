class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }
        
        set<pair<int,char>> ms;
        for(auto[k,v] : mp){
            ms.insert(make_pair(v, k));
        }
        
        string ret = "";
        for(auto[k,v] : ms){
            for(int i = 0; i < k; i++){
                ret += v;
            }
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};