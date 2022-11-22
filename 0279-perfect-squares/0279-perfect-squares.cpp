class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i = 1; i * i <= n; i++){
            squares.push_back(i*i);
        }
        
        vector<int> dp(n+1);
        dp[1] = 1; 
        for(int i = 2; i < n+1; i++){
            int mn = INT_MAX;
            for(int j = 0; j < squares.size(); j++){
                if(squares[j] <= i){
                    mn = min(mn, 1 + dp[i - squares[j]]);
                }
                else{
                    break;
                }
            }
            dp[i] = mn;
        }
        
        return dp.back();
    }
};