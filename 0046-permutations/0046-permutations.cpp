class Solution {
public:
    vector<vector<int>>ret;
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> seen(n);
        vector<int> curr;
        dfs(0,n, nums, seen, curr);
        
        return ret;
    }
    
    void dfs(int lvl, int tot, vector<int>& nums, vector<int>& seen, vector<int>& curr){
        if(lvl == tot){
            vector<int> ret1;
            for(int i = 0; i  < curr.size(); i++){
                ret1.push_back(nums[curr[i]]);
            }
            ret.push_back(ret1);
        }
        else{
            for(int i = 0; i < tot; i++){
                if(seen[i] == 0){
                    seen[i] = 1;
                    curr.push_back(i);
                    dfs(lvl+1, tot, nums, seen, curr);
                    curr.pop_back();
                    seen[i] = 0;
                }
            }
        }
    }
};