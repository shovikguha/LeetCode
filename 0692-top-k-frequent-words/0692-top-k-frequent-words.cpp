#define psi pair<int, string>

class myComparator {
  public:
    bool operator() (const psi &p1, const psi &p2) {
      if(p1.first == p2.first) return p1.second < p2.second;
      return p1.first > p2.first;
    }
}; 

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        
        for(string s : words){
            mp[s] += 1;
        }
        
        priority_queue<psi, vector<psi>, myComparator> pq;
        
        for(auto& v : mp){
            pq.push(make_pair(v.second, v.first));
            if((int)pq.size() > k){
                pq.pop();
            }
        }
        
        vector<string> ret;
        
        while(!pq.empty()){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};