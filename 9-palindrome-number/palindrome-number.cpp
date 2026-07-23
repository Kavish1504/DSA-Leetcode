class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int num=x;
        long sum=0;
        while(num>0){
            int digit=num%10;
            sum=(sum*10)+digit;
            num=num/10;
        }
        return sum==x;
    }
};