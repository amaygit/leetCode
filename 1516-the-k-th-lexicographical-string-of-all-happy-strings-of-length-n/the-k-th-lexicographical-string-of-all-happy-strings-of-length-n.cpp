class Solution {
public:
    vector<string> ans;

    void solve(string curr, int n) {

        if(curr.length() == n){
            ans.push_back(curr);
            return;
        }

        for(char c : {'a','b','c'}){

            if(curr.empty() || curr.back() != c){
                solve(curr + c, n);
            }
        }
    }

    string getHappyString(int n, int k) {

        solve("", n);

        if(k > ans.size()) return "";

        return ans[k-1];
    }
};