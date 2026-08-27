class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0;
        int j=k-1;
        int sum=0;
        int count=0;
        for(int k=i;k<=j;k++){
            sum+=arr[k];
        }
        int avg=sum/k;
        if(avg>=threshold) count++;
        while(j+1<arr.size()){
            sum-=arr[i];
            i++;
            j++;
            sum+=arr[j];
            int avg=sum/k;
            if(avg>=threshold) count++;
        }
        return count;
    }
};