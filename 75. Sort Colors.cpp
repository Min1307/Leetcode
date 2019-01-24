//75. Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        for(int i=0,j=0,k=nums.size();j<k;)
        {
            if(nums[j]==0)
            {
                nums[j++]=nums[i];
                nums[i++]=0;
                
            }
            else if(nums[j]==1)
            {
                j++;
            }
            else
            {
                k--;
                nums[j]=nums[k];
                nums[k]=2;
            }
        }
    }
};