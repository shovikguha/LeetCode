class Solution {
public:
    int glo_n;
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> edgeLst(n);
        glo_n = n;
        
        for(vector<int> v : edges){
            edgeLst[v[0]].push_back(v[1]);
            edgeLst[v[1]].push_back(v[0]);
        }
        
        vector<int> ret(n);
        vector<int> count(26, 1);
        
        dfs(0, -1, edgeLst, labels, ret, count);
            
        return ret;
    }
    
    void dfs(int curr, int par,vector<vector<int>>& edgeLst, string& labels, vector<int>& ret, vector<int>& count){
        int prev = count[labels[curr] - 'a'];
        
        count[labels[curr] - 'a']++;
        
        for(int ne : edgeLst[curr]){
            if(ne != par){
                dfs(ne, curr, edgeLst, labels, ret, count);
            }
        }
        
        ret[curr] = count[labels[curr] - 'a'] - prev;
    }
};