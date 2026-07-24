class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        stack<int> greater;
        for(int i=0;i<nums2.size();i++){
            st.push(nums2[i]);
        }
        while(!st.empty()){
            int top=st.top();
            st.pop();
            if(greater.empty()){
                mp[top]=-1;
            }
            else{
                if(greater.top()>top){
                    mp[top]=greater.top();
                }
                else{
                    bool found=false;
                    while(!greater.empty()){
                        if(greater.top()>top){
                            mp[top]=greater.top();
                            found=true;
                            break;
                        }
                        else{
                            greater.pop();
                        }
                    }
                    if(!found){
                        mp[top]=-1;
                    }
                }
            }
            greater.push(top);
        }
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i]=mp[nums1[i]];
        }
        return ans;
    }
};