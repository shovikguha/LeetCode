class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string curr = "";
        dfs(n,n,curr,ret);
        
        return ret;
    }
    
    void dfs(int right, int left, string curr, vector<string>& ret){
        if(right > left){
            return;
        }
        else if(left == 0 && right == 0){
            ret.push_back(curr);
        }
        else{
            if(right > 0){
                dfs(right -1, left, curr + "(", ret);
            }
            if(left > 0){
                dfs(right, left-1, curr + ")", ret);
            }
        }
    }
};