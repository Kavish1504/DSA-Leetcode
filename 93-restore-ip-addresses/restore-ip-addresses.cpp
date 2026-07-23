class Solution {
public:
    void solve(string s,vector<string>& vec,string temp,int index,int dots){
        if(dots==0){
            if(index>=s.size()) return;
            string part=s.substr(index);
            if(part.size()>1 && part[0]=='0' || part.size()>3) return;
            int num=stoi(part);
            if(num<=255){
                vec.push_back(temp+part);
            }
            return;
        }
        int num=0;
        for(int i=index;i<s.size();i++){
            num=num*10+(s[i]-'0');
            if(num>255){
                break;
            }
            solve(s,vec,temp+s.substr(index,i-index+1)+".",i+1,dots-1);
            if(s[index]=='0'){
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> vec;
        solve(s,vec,"",0,3);
        return vec;
    }
};