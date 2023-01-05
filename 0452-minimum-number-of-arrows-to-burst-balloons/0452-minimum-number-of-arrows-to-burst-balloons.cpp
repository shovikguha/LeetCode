class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int ret = 1;
        int end = points[0][1];
        
        int n = points.size();
        
        for(int i = 1; i < n; i++){
            if(points[i][0] > end){
                ret++;
                end = points[i][1];
            }
            else{
                end = min(end, points[i][1]);
            }
        }
        
        return ret;
    }
};