class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        queue<int> q;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                count++;
                q.push(nums[i]);
            }
        }
        int index=0;
        while(!q.empty()){
            nums[index++]=q.front();
            q.pop();
        }
        while(index<nums.size()){
            nums[index++]='_';
        }
        return count;
    }
};