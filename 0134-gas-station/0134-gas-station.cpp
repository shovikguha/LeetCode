class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(n);
        
        for(int i = 0; i < n; i++){
            diff[i] = gas[i] - cost[i];
        }
        
        if(accumulate(diff.begin(), diff.end(), 0) < 0){
            return -1;
        }
        
        for(int i = 0; i < n; i++){
            diff.push_back(diff[i]);
        }
        
        int glo = 0;
        int curr = 0;
        int idx = 0;
        for(int i = diff.size()-1; i >= 0; i--){
            curr = max(diff[i], curr + diff[i]);
            if(curr > glo){
                glo = curr;
                idx = i;
            }
        }
        return idx%n;
    }
};