//137. Single Number II
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0,b=0;
        for(int i=0; i<nums.size(); i++)
        {
            a = a ^ nums[i] & ~b; // appear one time
            b = b ^ nums[i] & ~a; //appear two times
        }
        return a;
    }
};