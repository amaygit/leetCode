class Solution {
public:
    
    unordered_map<string, vector<string>> memo;

    vector<string> dfs(string s, unordered_set<string>& dict) {

        if(memo.count(s))
            return memo[s];

        vector<string> result;

        if(s.empty()) {
            result.push_back("");
            return result;
        }

        for(int i = 1; i <= s.size(); i++) {

            string prefix = s.substr(0, i);

            if(dict.count(prefix)) {

                vector<string> suffixWays = dfs(s.substr(i), dict);

                for(string way : suffixWays) {

                    result.push_back(prefix + (way.empty() ? "" : " " + way));
                }
            }
        }

        return memo[s] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        return dfs(s, dict);
    }
};