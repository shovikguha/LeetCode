class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        
        int Acount = 0;
        int Bcount = 0;
        
        for(int i = 1; i < n-1; i++){
            if(colors.at(i-1) == colors.at(i) && colors.at(i) == colors.at(i+1)){
                if(colors[i] == 'A'){
                    Acount++;
                }
                else{
                    Bcount++;
                }
            }
        }
        
        return Acount > Bcount;
    }
};