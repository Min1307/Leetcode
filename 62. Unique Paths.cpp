//62. Unique Paths
//递归算法
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1) return 1;
        if(n==1) return 1;
        return uniquePaths(m-1,n) + uniquePaths(m,n-1);
    }
};

//非递归算法
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++)
            for (int i = 1; i < m; i++)
                cur[i] += cur[i - 1]; 
        return cur[m - 1];
    }
};