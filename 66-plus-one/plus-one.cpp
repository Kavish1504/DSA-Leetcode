class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        digits[n]+=1;
        int carry=digits[n]/10;
        digits[n]=digits[n]%10;
        for(int i=n-1;i>=0;i--){
            digits[i]=digits[i]+carry;
            carry=digits[i]/10;
            digits[i]=digits[i]%10;
        }
        if(carry){
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};