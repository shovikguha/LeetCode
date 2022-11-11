class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        multiset<pair<int,int>> st;
        vector<vector<int>> ret;
        
        for(auto& v : intervals){
            st.insert(make_pair(v[0], -1));
            st.insert(make_pair(v[1], 1));
        }
        
        int cnt = 0;
        int frst = 0;
        for(auto it = st.begin(); it != st.end(); it++){
            if(cnt == 0 && it -> second == -1){
                frst = it -> first;
                cnt++;
            }
            else if(it -> second == -1){
                cnt++;
            }
            else{
                cnt--;
                if(cnt == 0){
                    ret.push_back({frst, it -> first});
                }
            }
        }
        
        return ret;
    }
};