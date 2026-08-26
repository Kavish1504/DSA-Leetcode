class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        queue<int> q;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                q.push(i);
                if(q.size()>k){
                    q.pop();
                }
                if(q.size()==k){
                    string curr=s.substr(q.front(),i-q.front()+1);
                    if (ans == "" ||
                        curr.size() < ans.size() ||
                        (curr.size() == ans.size() && curr < ans)) {

                        ans = curr;
                    }
                }
                
            }
        }
        return ans;
    }
};