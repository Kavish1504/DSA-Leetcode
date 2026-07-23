class Solution {
public:
    int lengthOfLastWord(string s) {
        int j=s.size()-1;
        while(j>=0){
            if(s[j]!=' '){
                break;
            }
            j--;
        }
        int length=0;
        while(j>=0 && s[j]!=' '){
            length++;
            j--;
        }
        return length;
    }
};