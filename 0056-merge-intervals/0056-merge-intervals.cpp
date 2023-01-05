class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        multiset<pair<int,int>> st;
        
        for(vector<int> v : intervals){
            st.insert(make_pair(v[0], -1));
            st.insert(make_pair(v[1], 1));
        }
        
        int cnt = 0;
        int first = 0;
        vector<vector<int>> ret;
        for(auto it = st.begin(); it != st.end(); it++){
            if(it -> second < 0){
                if(cnt == 0){
                    first = it -> first;
                }
                cnt++;
            }
            else if(it -> second > 0){
                cnt--;
                if(cnt == 0){
                    ret.push_back({first, it->first});
                }
            }
        }
        
        return ret;
    }
};