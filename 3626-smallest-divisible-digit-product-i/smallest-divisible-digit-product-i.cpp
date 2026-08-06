class Solution {
public:
    int product(int n){
        int prod=1;
        while(n>0){
            int digit=n%10;
            prod=prod*digit;
            n=n/10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        while(n){
            int temp=n;
            if(product(temp)%t==0){
                return temp;
            }
            n++;
        }
        return 0;
    }
};