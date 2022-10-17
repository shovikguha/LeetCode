class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjlst(n);
        
        for(vector v : edges){
            adjlst[v[0]].push_back(v[1]);
            adjlst[v[1]].push_back(v[0]);
        }
        
        vector<int> visited(n);
        
        long long ret = 0;

        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                long long sz = dfs(i, adjlst, visited);
                ret += (sz)*(n-sz);
            }
        }
        
        return ret/2;
        
    }
    
    int dfs(int node, vector<vector<int>>& adjlst, vector<int>& visited){
        visited[node] = 1;
        int ret = 1;
        
        for(int ne: adjlst[node]){
            if(visited[ne] == 0){
                ret += dfs(ne, adjlst, visited);
            }
        }
        
        return ret;
    }
};