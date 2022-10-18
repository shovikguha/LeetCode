class Solution {
public:
    string countAndSay(int n) {
        
        string ret = "1";
        int i = 1;
        
        while(i < n){
            vector<char> st;
            vector<int> adj;
            
            int curr = 0;
            for(int i = 0; i < (int)ret.size(); i++){
                if(st.empty()){
                    st.push_back(ret[i]);
                    curr = 1;
                }
                else if(st.back() != ret[i]){
                    st.push_back(ret[i]);
                    adj.push_back(curr);
                    curr = 1;
                }
                else{
                    curr += 1;
                }
            }
            adj.push_back(curr);
            string news = "";
            for(int i = 0; i < (int)adj.size(); i++){
                news += to_string(adj[i]);
                news += st[i];
            }
            ret = news;
            i++;
        }
        
        return ret;
    }
};