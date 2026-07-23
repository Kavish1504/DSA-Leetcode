class Solution {
public:
    double power(double x,int n){
        if(n==0){
            return 1;
        }
        double half=power(x,n/2);

        if(n%2==0){
            return half*half;
        }
        else{
            return half*half*x;
        }
    }
    double negative_power(double x,int n){
        if(n==0){
            return 1;
        }
        double half=power(x,n/2);

        if(n%2==0){
            return 1.0/(half*half);
        }
        else{
            return 1.0/(half*half*x);
        }
    }
    double myPow(double x, int n) {
        if(n>0)
        return power(x,n);
        return negative_power(x,n);
    }
};