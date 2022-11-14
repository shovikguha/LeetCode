class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adjlst(n);
        
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if((stones[i][0] == stones[j][0]) || (stones[i][1] == stones[j][1])){
                    adjlst[i].push_back(j);
                    adjlst[j].push_back(i);
                }
            }
        }
        
        vector<int> seen(n);
        int comps = 0;
        for(int i = 0; i < n; i++){
            if(seen[i] == 0){
                dfs(i, seen, adjlst);
                comps++;
            }
        }
        
        return n - comps;
    }
    
    void dfs(int i, vector<int>& seen, vector<vector<int>>& adjlst){
        seen[i] = 1;
        
        for(int ne : adjlst[i]){
            if(seen[ne] == 0){
                dfs(ne, seen, adjlst);
            }
        }
    }
    
};