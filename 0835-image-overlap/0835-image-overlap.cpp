class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> v1;
        vector<pair<int,int>> v2;
        
        int n = img1.size();
        
        map<pair<int,int>, int> mp;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1){
                    v1.push_back(make_pair(i,j));
                }
                if(img2[i][j] == 1){
                    v2.push_back(make_pair(i,j));
                }
            }
        }
        
        int ret = 0;
        
        for(pair<int,int> p1 : v1){
            for(pair<int,int> p2: v2){
                pair<int,int> p3 = make_pair(p1.first - p2.first, p1.second - p2.second);
                mp[p3]++;
                ret = max(ret, mp[p3]);
            }
        }
                
        return ret;
    }
};