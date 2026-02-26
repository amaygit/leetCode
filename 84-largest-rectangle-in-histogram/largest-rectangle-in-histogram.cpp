class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0); // Trick: Add a 0 to process all remaining bars

        for (int i = 0; i < heights.size(); i++) {
            // While current bar is shorter than the bar at stack top
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                
                // Width is current index - new top index - 1
                // If stack is empty, it means this was the shortest bar seen so far
                int w = st.empty() ? i : i - st.top() - 1;
                
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};