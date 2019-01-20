//55. Jump Game
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<=1) return true;
        int n=1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]>=n)
            {
                n=1;
            }
            else
            {
                n++;
            }
        }
        if(n>1) return false;
        else return true;
    }
};