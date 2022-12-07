class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int curr = 0;
        int ret = 0;
        int n = costs.size();
        for(int i =0; i < n; i++){
            if(curr + costs[i] <= coins){
                curr += costs[i];
                ret++;
            }
            else{
                break;
            }
        }
        return ret;
    }
};