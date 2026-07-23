class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry=0;
        int i=num1.size()-1,j=num2.size()-1;
        string ans="";
        while(i>=0 && j>=0){
            int digit1=num1[i]-'0';
            int digit2=num2[j]-'0';
            int sum=digit1+digit2+carry;
            int num=sum%10;
            ans+=num+'0';
            carry=sum/10;
            i--;
            j--;
        }
        while(i>=0){
            int digit1=num1[i]-'0';
            int sum=digit1+carry;
            int num=sum%10;
            ans+=num+'0';
            carry=sum/10;
            i--;
        }
        while(j>=0){
            int digit2=num2[j]-'0';
            int sum=digit2+carry;
            int num=sum%10;
            ans+=num+'0';
            carry=sum/10;
            j--;
        }
        if(carry) ans+=carry+'0';
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        vector<string> ans;
        int i=num1.size()-1,j=num2.size()-1;
        while(j>=0){
            string temp="";
            int d1=num2[j]-'0';
            int carry=0;
            i=num1.size()-1;
            while(i>=0){
                int d2=num1[i]-'0';
                int mul=(d1*d2)+carry;
                int digit=mul%10;
                temp+=digit+'0';
                carry=mul/10;
                i--;
            }
            if(carry)                  
                temp += carry + '0';
            reverse(temp.begin(),temp.end());
            int zeros=num2.size()-j-1;
            while(zeros){
                temp+='0';
                zeros--;
            }
            ans.push_back(temp);
            j--;
        }
        string result = "0";

        for(int i = 0; i < ans.size(); i++) {
            result = addStrings(result, ans[i]);
        }

        return result;
    }
};