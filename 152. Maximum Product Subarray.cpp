//152. Maximum Product Subarray
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = nums[0], curMax = product, curMin = product;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0)
                swap(curMax, curMin);
            curMax = max(nums[i], curMax * nums[i]);
            curMin = min(nums[i], curMin * nums[i]);
            product = max(product, curMax);
        }
        return product;
    }
};