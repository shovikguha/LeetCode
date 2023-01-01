class Solution {
public:
    vector<vector<int>> ret;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> lst;
        
        dfs(0,nums,lst);
        
        return ret;
    }
    
    void dfs(int curr, vector<int>& nums, vector<int>& lst){
        if(curr == nums.size()){
            ret.push_back(lst);
        }
        else{
            lst.push_back(nums[curr]);
            dfs(curr + 1, nums, lst);
            lst.pop_back();
            dfs(curr + 1, nums, lst);
        }
    }
};