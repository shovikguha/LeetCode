class Solution {
public:
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        vector<int> ways(n);
        
        ways[n-1] = 1;
        ways[n-2] = 2;
        
        for(int i = n-3; i >= 0; i--){
            ways[i] = ways[i+1] + ways[i+2];
        }
        
        return ways[0];
    }
};