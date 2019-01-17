//45. Jump Game II
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), step = 0, start = 0, end = 0;//[start,end]为当前步可以到达的位置范围
        while (end < n - 1) { //是否达到终点
            step++; //步长+1
			int maxend = end + 1; //当前所能走到的最远的位置
			for (int i = start; i <= end; i++) {
                if (i + nums[i] >= n - 1) return step; //该步可以达到最终位置
				maxend = max(maxend, i + nums[i]); //下一步可以达到的最远位置
			}
            start = end + 1;
            end = maxend;
        }
		return step;
    }
};