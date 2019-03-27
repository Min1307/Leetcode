//198. House Robber
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        auto n=nums.size();
        int pre2=0,pre1=nums[0],cur=pre1;
        for(int i=1;i<n;++i){
            cur=max(pre1,pre2+nums[i]);
            pre2=pre1;
            pre1=cur;
        }  
        return cur;
    }
};