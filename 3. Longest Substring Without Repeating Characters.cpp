//3. Longest Substring Without Repeating Characters
//时间复杂度O(n)&空间复杂度O(n)

int lengthOfLongestSubstring(string s) {
    int n = s.length(), ans = 0;
    int index[128]={0}; //记录字符的最新的位置(随识别过程动态变化)
    for (int j = 0, i = 0; j < n; j++) {  //窗口[i，j]
        i = max(index[s.at(j)], i); //字符重复重新开始
        ans = max(ans, j - i + 1);  //更新最大的窗口大小
        index[s.at(j)] = j + 1;     //更新记录数组
    }
    return ans;
}
//优化：可将固定的长度的数组换为散列表