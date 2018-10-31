//5. Longest Palindromic Substring 
//时间复杂度O(n2)
string longestPalindrome(string s) {
    int start = 0, end = 0; //存储最长回文子串[start, end]
    for (int i = 0; i < s.length(); i++) {//遍历整个字符串
        int l,r;
        for(l=i,r=i;l >= 0 && r < s.length() && s[l] == s[r];l--,r++); //奇数长回文序列
        int len1 = r - l - 1;
        for(l=i,r=i+1;l >= 0 && r < s.length() && s[l] == s[r];l--,r++); //偶数长回文序列
        int len2 = r - l - 1;
        int len = len1>len2?len1:len2;
        if (len > end - start + 1) { //更新最长回文子串
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end-start+1);
}