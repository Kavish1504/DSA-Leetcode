class Solution {
public:
    bool negative=false;
    int solve(string s,int index,long long num,bool negative){
        if(index>s.size() || !isdigit(s[index])){
            if(negative){
                return -num;
            }
            return num;
        }
        int digit=s[index]-'0';
        if((num*10 + digit)>INT_MAX){
            return negative?INT_MIN:INT_MAX;
        }
        num=num*10+digit;
        return solve(s,index+1,num,negative);
    }
    int myAtoi(string s) {
        int i=0;
        while(i<s.size()){
            if(s[i]!=' '){
                break;
            }
            i++;
        }
        if(i<s.size() && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-'){
                negative=true;
            }
            i++;
        }
        return solve(s,i,0,negative);
    }
};