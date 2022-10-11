class Solution {
public:
    int glo_t;
    double ret;
    int targ;
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {   
        if(n ==1 ){
            return 1.0;
        }
        vector<vector<int>> adjlst(n+1);
        
        glo_t = t;
        ret = 0.0;
        targ = target;
        
        for(vector<int>v: edges){
            adjlst[v[0]].push_back(v[1]);
            adjlst[v[1]].push_back(v[0]);
        }
        
        vector<int> visited(n+1);
        //visited[1] =1;
        
        dfs(1, visited, adjlst, 1.0, t);
        return ret;
    }
    
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adjlst, double p, int t){
        int count = adjlst[node].size();
        if((node != 1 && count == 1) || t == 0) {
            if (node == targ){
                ret = p;
            } 
            return;
        }
        visited[node] = 1;
        for(int ne : adjlst[node]){
            if(visited[ne] == 0){
                dfs(ne, visited, adjlst, p / (double)(count - ((node == 1) ? 0 : 1)), t-1);
            }
        }
    }
};