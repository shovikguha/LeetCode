class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        int sm = 0;
        
        for(int i : piles){
            q.push(i);
            sm += i;
        }
        
        for(int i = 0; i < k; i++){
            int fr = q.top();
            q.pop();
            sm -= (fr/2);
            q.push(fr - fr/2);
        }
        
        return sm;
    }
};