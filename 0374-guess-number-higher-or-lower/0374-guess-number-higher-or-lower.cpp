/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long lo = 1;
        long hi = n;
        long pick = (lo + hi) / 2;
        while(guess(pick) != 0){
            if(guess(pick) == 1){
                lo = pick + 1;
            }
            else{
                hi=  pick -1;
            }
            pick = (lo + hi) / 2;
        }
        
        return pick;
    }
};