class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjlst(n);
        
        for(auto& v : dislikes){
            adjlst[v[0]-1].push_back(v[1]-1);
            adjlst[v[1]-1].push_back(v[0]-1);
        }
        
        vector<int> colors(n);
        for(int i =0; i < n; i++){
            colors[i] = -1;
        }
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i < n; i++){
            if(colors[i] == -1){
               q.push(make_pair(i,1));
        
                while(!q.empty()){
                    auto p = q.front();
                    q.pop();
                    colors[p.first] = p.second;
                    for(int ne : adjlst[p.first]){
                        if(colors[ne] != (1 - p.second)){
                            if(colors[ne] == p.second){
                                return false;
                            }
                            else{
                                q.push(make_pair(ne, 1 - p.second));
                            }
                        }
                    }
                } 
            }
        }
        
        return true;
    }
};