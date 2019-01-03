//11. Container With Most Water
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxsize=0, i=0,j=height.size()-1;
        while(i<j)
        {
            int min=height[i]>height[j]?height[j]:height[i];
            int max=min*(j-i);
            if(max>maxsize) maxsize = max;
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxsize;
    }
};