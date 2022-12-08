class Solution {
public:
    double myPow(double x, long n) {
        if(x == 1 || n == 0){
            return 1;
        }
        if(n < 0){
            return 1 / myPow(x, abs(n));
        }
        else if(n == 1){
            return x;
        }
        else if(n%2 == 0){
            double ret = myPow(x, n/2);
            return ret*ret;
        }
        else{
            double ret = myPow(x, n/2);
            return ret*ret*x;
        }
    }
};