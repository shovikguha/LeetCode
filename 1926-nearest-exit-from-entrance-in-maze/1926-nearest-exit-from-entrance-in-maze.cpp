class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<vector<int>> q;
        vector<vector<int>> visited(n, vector<int>(m));
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
        
        q.push({entrance[0],entrance[1],0});
        visited[entrance[0]][entrance[1]] = 1; 
        
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            
            if(!(v[0] == entrance[0] && v[1] == entrance[1])){
                if(v[0] == 0 || v[0] == n-1 || v[1] == 0 || v[1] == m-1){
                    return v[2];
                }
            }
            
            for(int i = 0; i < 4; i++){
                int x = v[0] + dx[i];
                int y = v[1] + dy[i];
                
                if(0 <= x && x < n && 0 <= y && y < m && maze[x][y] == '.' &&visited[x][y] == 0){
                    visited[x][y] = 1;
                    q.push({x,y,v[2]+1});
                }
            }
        }
        
        return -1;
    }
};