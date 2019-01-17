//41. First Missing Positive
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]!=i+1)
            {
                if(nums[i]<=0||nums[i]>nums.size())
                    break;
                if(nums[i]==nums[nums[i]-1])
                    break;
                
                int rap=nums[i];
                nums[i]=nums[rap-1];
                nums[rap-1]=rap;
                    
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1)
                return i+1;
        }
        return nums.size()+1;
    }
};