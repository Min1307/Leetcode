//53. Maximum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()<=1) return nums[0];
        int n = nums.size();
        int sum = 0;
        int max= nums[0];
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            if(max<sum) max=sum;
            if(sum<0) sum=0;
        }
        return max;
    }
};