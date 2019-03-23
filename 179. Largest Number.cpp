//179. Largest Number
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });
        string str="";
        for(int i=0; i<nums.size(); i++)
        {
            str += to_string(nums[i]);
        }
        return str[0] == '0'? "0":str;
    }
};