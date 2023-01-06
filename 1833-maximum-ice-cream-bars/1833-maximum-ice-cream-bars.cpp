class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        
        int ret = 0;
        for(int i : costs){
            if(coins >= i){
                coins -= i;
                ret++;
            }
        }
        
        return ret;
    }
};