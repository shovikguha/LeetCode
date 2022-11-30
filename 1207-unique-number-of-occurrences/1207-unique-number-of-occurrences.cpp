class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i : arr){
            mp[i]++;
        }
        
        unordered_map<int,int> occ_mp;
        for(auto[k,v] : mp){
            occ_mp[v]++;
            if(occ_mp[v] > 1){
                return false;
            }
        }
        
        return true;
    }
};