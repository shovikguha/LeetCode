class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<int> parent(n);
        vector<bool> ret;
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        
        for(vector<int>& req : requests){
            int x = find(req[0], parent);
            int y = find(req[1], parent);
            bool flg = true;
            
            if(x != y){
                for(vector<int>& res: restrictions){
                    int p = find(res[0], parent);
                    int q = find(res[1], parent);
                
                    if((x == p && y == q) || (x == q && y == p)){
                        flg = false;
                        ret.push_back(false);
                        break;
                    }
                }
                if(flg == true){
                    ret.push_back(true);
                    uni(x,y,parent);
                }
            }
            else{
                ret.push_back(true);
            }
        }
        
        return ret;
    }
    
    int find(int i, vector<int>& parent){
        int ret = i;
        while(parent[ret] != ret){
            ret = parent[ret];
        }
        
        while (parent[i] != i) {
            int next = parent[i];
            parent[i] = ret;
            i = next;
        }
        return ret;
    }
    
    void uni(int i, int j, vector<int>& parent){
        int p1 = find(i, parent);
        int p2 = find(j, parent);
        parent[p2] = p1;
    }
};