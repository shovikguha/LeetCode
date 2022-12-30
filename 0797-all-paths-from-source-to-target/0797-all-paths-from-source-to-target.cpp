class Solution {
public:
    vector<vector<int>> ret;
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int targ = graph.size() - 1;
        vector<int> path = {0};
        dfs(0,targ, path, graph);
        
        return ret;
    }
    
    void dfs(int curr, int targ, vector<int>& path, vector<vector<int>>& graph){
        if(curr == targ){
            ret.push_back(path);        
        }
        else{
            for(int ne : graph[curr]){
                path.push_back(ne);
                dfs(ne, targ, path, graph);
                path.pop_back();
            }
        }
    }
};