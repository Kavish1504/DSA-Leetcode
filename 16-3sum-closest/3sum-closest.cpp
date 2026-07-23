class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size=nums.size();
        int closest=INT_MAX;
        sort(nums.begin(),nums.end());
        int prev_dist=INT_MAX;
        for(int i=0;i<size;i++){
            int j=i+1;
            int k=size-1;
            while(j<k){
               int sum=nums[i]+nums[j]+nums[k];
               int dist=abs(target-sum);
               if(dist<prev_dist){
                closest=sum;
                prev_dist=dist;
               }
               if(sum>target){
                    k--;
               }
               else{
                    j++;
               }
            }
        }
        return closest;
    }
};