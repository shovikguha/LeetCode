class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2){
            return 0;
        }
        
        vector<int> nums(n);
        int cnt = 0;
        
        for(long i = 2; i < n; i++){
            if(nums[i] == 0){
                cnt++;
            }
            else{
                continue;
            }
            for(long j = i*i; j < n; j+=i){
                nums[j] = 1;
            }
        }
        
        return cnt;
    }
};