class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    height[j] += 1;
                } else {
                    height[j] = 0;
                }
            }

            ans = max(ans, largestRectangleArea(height));
        }

        return ans;
    }

private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxA = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int h = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? 0 : st.top() + 1;

                maxA = max(maxA, h * (right - left));
            }
            st.push(i);
        }

        return maxA;
    }
};