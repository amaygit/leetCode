class Solution {
public:
    int maxArea(vector<int>& height) {
       int st=0,end=height.size()-1,maxArea=0;
       while(st<end){
        int h=min(height[st],height[end]);
        int w=end-st;
        int area=h*w;
        maxArea=max(maxArea,area);
        if(height[end]>height[st])
        st++;
        else
        end--;
       }
       return maxArea;
    }
};