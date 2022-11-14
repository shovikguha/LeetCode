class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        int n = digits.size();
        int c = 0;
        int num = 0;
        for(int i = n-1; i >= 0; i--){
            num = (digits[i] + c + (i == n-1 ? 1 : 0)) % 10;
            c = (digits[i] + c + (i == n-1 ? 1 : 0)) / 10;      
            ret.push_back(num);
        }
        if(c == 1){
            ret.push_back(1);
        }
        
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};