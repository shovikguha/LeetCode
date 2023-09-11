class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size() + 1;
        vector<vector<int>> tmp(n);
        
        for(int i = 0; i < n-1; i++){
            tmp[groupSizes[i]].push_back(i);
        }
        
        vector<vector<int>> ret;
        for(int i = 1; i< n; i++){
            if(tmp[i].size() != 0){
                for(int j = 0; j < tmp[i].size(); j+=i){
                    vector<int> curr;
                    for(int k =j; k < j + i; k++){
                        curr.push_back(tmp[i][k]);
                    }
                    ret.push_back(curr);
                }
            }
        }
        
        return ret;
    }
};