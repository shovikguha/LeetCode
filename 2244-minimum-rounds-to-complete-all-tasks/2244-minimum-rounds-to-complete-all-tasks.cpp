class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        vector<int> round(max(n+1,5));
        
        round[1] = INT_MAX;
        round[2] = 1;
        round[3] = 1;
        round[4] = 2;
        
        for(int i = 5; i < n+1; i++){
            round[i] = 1 + min(round[i-2], round[i-3]);
        }
        
        unordered_map<int,int> mp;
        
        for(int i : tasks){
            mp[i]++;
        }
        
        int ret = 0;
        for(auto[k,v] : mp){
            if(v == 1){
                return -1;
            }
            else{
                ret += round[v];
            }
        }
            
        return ret;
    }
};