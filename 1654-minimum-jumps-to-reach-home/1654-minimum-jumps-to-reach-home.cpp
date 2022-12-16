class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {

        queue<vector<int>> q;
        q.push({0,0,0});
        bool back = false;
        vector<unordered_map<int,int>> seen(2);
        
        for(int i : forbidden){
            seen[0][i] = 1;
            seen[1][i] = 1;
        }
        
        while(!q.empty()){
            vector<int> curr = q.front();
            q.pop();
            
            if(curr[0] == x){
                return curr[1];
            }
            
            if(curr[0] + a <= 6000){
                if(seen[0].find(curr[0] + a) == seen[0].end()){
                    seen[0][curr[0] + a] =1;
                    q.push({curr[0]+a, curr[1]+1,0});
                }
            }
            if(!curr[2] && curr[0] - b >= 0){
                if(seen[1].find(curr[0] - b) == seen[1].end()){
                    seen[1][curr[0] - b] = 1;
                    q.push({curr[0]-b, curr[1]+1, 1});
                }
            }
        }
        
        return -1;
    }
};