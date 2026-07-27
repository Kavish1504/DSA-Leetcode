class Solution {
public:
    void merge(int left,int mid,int right,vector<pair<int,int>>& nums,vector<int>& count){
        int i=left,j=mid+1,k=0;
        vector<pair<int,int>> temp(right-left+1);
        while(i<=mid && j<=right){
            if(nums[i].first<=nums[j].first){
                temp[k++]=nums[j++];
            }
            else{
                count[nums[i].second]+=(right-j+1);
                temp[k++]=nums[i++];
            }
        }
        while(i<=mid){
            temp[k++]=nums[i++];
        }
        while(j<=right){
            temp[k++]=nums[j++];
        }
        for(int i=left;i<=right;i++){
            nums[i]=temp[i-left];
        }
    }
    void mergeSort(int left,int right,vector<pair<int,int>>& nums,vector<int>& count){
        if(left>=right) return;
        int mid=left+(right-left)/2;
        mergeSort(left,mid,nums,count);
        mergeSort(mid+1,right,nums,count);
        merge(left,mid,right,nums,count);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        vector<int> count(nums.size(),0);
        mergeSort(0,nums.size()-1,v,count);
        return count;
    }
};