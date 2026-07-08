class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int mx=0;
        unordered_set<int>st;
        for(int right=0;right<s.length();right++){
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            mx=max(mx,right-left+1);
        }
        return mx;
    }
};