class Solution {
public:
    bool solve(vector<int>& nums,int start,int end,int alice_score,int bob_score,bool alice_turn){
        if(start>end){
            return alice_score>=bob_score;
        }
        if(alice_turn){
            bool pick=solve(nums,start+1,end,alice_score+nums[start],bob_score,false);
            bool skip=solve(nums,start,end-1,alice_score+nums[end],bob_score,false);
            return pick||skip;
        }
        else{
            bool pick=solve(nums,start+1,end,alice_score,bob_score+nums[start],true);
            bool skip=solve(nums,start,end-1,alice_score,bob_score+nums[end],true);
            return pick&&skip;
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int alice_score=0,bob_score=0;
        return solve(nums,0,nums.size()-1,alice_score,bob_score,true);
        // return alice_score>=bob_score;
    }
};