//44. Wildcard Matching
class Solution {
public:
    bool isMatch(string s, string p) {
        int ss=0,ps=0,spos=-1,ppos=-1;
        while(ss<s.size())
        {
            if(s[ss]==p[ps] || p[ps]=='?')//字符匹配
            {
                ss++;
                ps++;
            }
            else if(p[ps]=='*')//任一字符
            {
                spos=ss;
                ppos=ps++;
            }
            else
            {
                if(ppos>-1)
                {
                    ss=++spos;
                    ps=ppos+1;
                }
                else
                 return false;
            }
        }
        while(p[ps]=='*') ps++;
        return ps==p.size();
    }
};