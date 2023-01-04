class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ret = 1;
        
        for(int i = 0; i< n; i++){
            unordered_map<double,int> mp;
            int count = 0;
            int vert = 1;
            for(int j =i+1; j < n; j++){
                if(points[i][0] != points[j][0]){
                    double slope = (double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                    mp[slope]++;
                    count = max(count, mp[slope]);
                }
                else{
                    vert++;
                }
            }
            ret = max(ret, count+1);
            ret = max(ret, vert);
            cout << ret << " " << i <<endl;
        }
        
        return ret;
    }
    
};