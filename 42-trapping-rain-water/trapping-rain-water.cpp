class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftmax(n,INT_MIN),rightmax(n,INT_MIN);
        leftmax[0]=height[0];
        for(int i=1;i<n;i++){
            leftmax[i]=max(leftmax[i-1],height[i]);
        }
        rightmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],height[i]);
        }
        int total=0;
        for(int i=0;i<n;i++){
            int left_max=leftmax[i],right_max=rightmax[i];
            if(height[i]<left_max && height[i]<right_max){
                total+=min(left_max,right_max)-height[i];
            }
        }
        return total;
    }
};