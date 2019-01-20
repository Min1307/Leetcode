//59. Spiral Matrix II
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> ret(n,vector<int>(n));
        int x=0,y=0;
        int a=n,b=n;
        int i=0,j=0;
        int k=0; int num=1;
        while(i>=0&&i<a&&j>=0&&j<b){
            ret[i][j]=num++;
            i+=dir[k][0];
            j+=dir[k][1];
            if(j>=b){k++;j--;i++;x++;}
            if(i>=a){k++;i--;j--;b--;}
            if(j<y){k++;j++;i--;a--;}
            if(i<x){k=0;i++;j++;y++;}
        }
        return ret;
    }
};