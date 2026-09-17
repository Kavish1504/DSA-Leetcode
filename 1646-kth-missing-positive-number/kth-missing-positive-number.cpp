class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int> st(arr.begin(),arr.end());
        int num1=1;

        while(true){
            if(!st.count(num1)){
                k--;
                if(k==0){
                    return num1;
                }
            }
            num1++;
        }
        return -1;
    }
};