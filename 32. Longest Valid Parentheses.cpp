//32. Longest Valid Parentheses
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> k;
        k.push(-1);
        int maxl=0;
        for(int i=0;i<s.size();i++)
        {
            int t=k.top();
            if(t!=-1&&s[t]=='('&&s[i]==')')
            {
                k.pop();
                maxl=max(maxl,i-k.top());
            }
            else
            {
                k.push(i);
            }
        }
        return maxl;
    }
};