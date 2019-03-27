//201. Bitwise AND of Numbers Range
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n) return m;
        int count = 0;
        for(; m<n; )
        {
            n = n/2;
            m = m/2;
            count++;
        }
        return m<<count;
    }
};