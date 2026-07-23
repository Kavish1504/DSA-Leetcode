class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size()) return -1;
        int i=0,j=0,start=-1,prev=-1;
        while(i<needle.size() && j<haystack.size()){
            if(haystack[j]==needle[i]){
                if(start==-1){
                    start=j;
                    prev=j;
                }
                i++;
                j++;
            }
            else{
                start=-1;
                j=prev+1;
                prev=j;
                i=0;
            }
        }
        if(i == needle.size()) {
            return start;
        }

        return -1;
    }
};