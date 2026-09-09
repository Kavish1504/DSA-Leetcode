class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]==']'){
                string repeat="";
                while(!st.empty() && st.top()!='['){
                    repeat+=st.top();
                    st.pop();
                }
                st.pop();
                reverse(repeat.begin(),repeat.end());
                string number="";
                while(!st.empty() && isdigit(st.top())){
                    number +=st.top();
                    st.pop();
                }
                reverse(number.begin(),number.end());
                int n=stoi(number);
                string str="";
                while(n--){
                    str+=repeat;
                }
                for (char c : str) {
                    st.push(c);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};