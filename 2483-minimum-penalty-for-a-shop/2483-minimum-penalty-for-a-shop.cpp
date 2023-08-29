class Solution {
public:
    int bestClosingTime(string customers) {
        int mn = 0;
        int idx = 0;
        for(auto it = customers.begin(); it != customers.end(); ++it){
            if(*it == 'Y'){
                mn++;
            }
        }
        
        int curr = mn;
        for(auto it = customers.begin(); it != customers.end(); ++it){
            if(*it == 'Y'){
                curr--;
            }
            else{
                curr++;
            }
            //cout << curr << endl;;
            if(curr < mn){
                mn = curr;
                idx = (it - customers.begin()) + 1;
            }
        }
        
        
        return idx;
    }
};