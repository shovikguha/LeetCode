class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> edgeLst(n);
        
        for(vector<int> v : edges){
            edgeLst[v[0]].push_back(v[1]);
            edgeLst[v[1]].push_back(v[0]);
        }
        
        vector<int> visited(n);
        visited[source] = 1;
        return dfs(source, destination, visited, edgeLst);
    }
    
    bool dfs(int curr, int dest, vector<int>& visited, vector<vector<int>>& edgeLst){
        if(curr == dest){
            return true;
        }
        else{
            bool ret = false;
            for(int ne : edgeLst[curr]){
                if(visited[ne] == 0){
                    visited[ne] = 1;
                    ret = ret || dfs(ne, dest, visited, edgeLst);
                }
            }
            return ret;
        }
    }
};