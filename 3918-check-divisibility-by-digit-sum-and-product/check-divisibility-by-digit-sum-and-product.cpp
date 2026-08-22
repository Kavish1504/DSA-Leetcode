class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int temp=n;
        while(temp>0){
            int digit=temp%10;
            sum+=digit;
            temp/=10;
        }
        int product=1;
        temp=n;
        while(temp>0){
            int digit=temp%10;
            product*=digit;
            temp/=10;
        }
        return n%(sum+product)==0;
    }
};