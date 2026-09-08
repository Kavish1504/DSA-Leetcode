class Solution {
public:
    int countCommas(int n) {
        int digits=0;
        int temp=n;
        while(temp>0){
            int digit=temp%10;
            digits++;
            temp/=10;
        }
        if(digits<4) return 0;
        int commas=0;
        if(digits==4){
            commas=(n-1000)+1;
        }
        else if(digits>=5){
            commas=(n-10000)+1+9000;
        }
        return commas;
    }
};