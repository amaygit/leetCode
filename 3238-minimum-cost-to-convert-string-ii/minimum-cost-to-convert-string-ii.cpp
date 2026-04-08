#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = source.length();
        unordered_map<string, int> strToId;
        int idCounter = 0;

        // 1. Map all unique strings to IDs
        for (const string& s : original) if (strToId.find(s) == strToId.end()) strToId[s] = idCounter++;
        for (const string& s : changed) if (strToId.find(s) == strToId.end()) strToId[s] = idCounter++;

        // 2. Floyd-Warshall for all-pairs shortest path between substring IDs
        int numNodes = idCounter;
        const long long INF = 1e16;
        vector<vector<long long>> dist(numNodes, vector<long long>(numNodes, INF));

        for (int i = 0; i < numNodes; ++i) dist[i][i] = 0;
        for (int i = 0; i < original.size(); ++i) {
            int u = strToId[original[i]];
            int v = strToId[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < numNodes; ++k) {
            for (int i = 0; i < numNodes; ++i) {
                for (int j = 0; j < numNodes; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // 3. DP to find the minimum cost to convert the whole string
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        // Optimization: Store lengths of original strings to check only those lengths
        vector<int> lengths;
        for (auto const& [str, id] : strToId) {
            lengths.push_back(str.length());
        }
        sort(lengths.begin(), lengths.end());
        lengths.erase(unique(lengths.begin(), lengths.end()), lengths.end());

        for (int i = 0; i < n; ++i) {
            if (dp[i] == INF) continue;

            // Option 1: Characters are already equal, no cost to skip
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // Option 2: Try all possible substring transformations starting at index i
            for (int len : lengths) {
                if (i + len > n) break;
                
                string subS = source.substr(i, len);
                string subT = target.substr(i, len);
                
                if (strToId.count(subS) && strToId.count(subT)) {
                    int u = strToId[subS];
                    int v = strToId[subT];
                    if (dist[u][v] < INF) {
                        dp[i + len] = min(dp[i + len], dp[i] + dist[u][v]);
                    }
                }
            }
        }

        return dp[n] >= INF ? -1 : dp[n];
    }
};