class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> edges(n);
        
        for(vector<int> v : dislikes){
            edges[v[0]-1].push_back(v[1]-1);
            edges[v[1]-1].push_back(v[0]-1);            
        }
                  
        queue<pair<int,int>> q;
        unordered_map<int,int> seen;
                  
        for(int i = 0; i < n; i++){
            if(seen.find(i) == seen.end()){
                seen[i] = 0;
                if(!bfs(i, seen, edges)){
                    return false;
                }
            }
        }
                  
        return true;
    }
                  
    bool bfs(int i,  unordered_map<int,int>& seen, vector<vector<int>>& edges){
        queue<pair<int,int>> q;
        q.push(make_pair(i, 0));
        
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            
            for(int ne : edges[p.first]){
                if(seen.find(ne) == seen.end()){
                    seen[ne] = (1 - p.second);
                    q.push(make_pair(ne, 1 - p.second));
                }
                else{
                    if(seen[ne] != 1 - p.second){
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};