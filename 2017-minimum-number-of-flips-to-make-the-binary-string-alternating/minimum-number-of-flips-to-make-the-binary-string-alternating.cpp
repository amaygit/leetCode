#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string doubled = s + s;
        
        // Target patterns
        string p1 = "", p2 = "";
        for (int i = 0; i < doubled.length(); ++i) {
            p1 += (i % 2 == 0 ? '0' : '1');
            p2 += (i % 2 == 0 ? '1' : '0');
        }
        
        int diff1 = 0, diff2 = 0;
        int min_flips = doubled.length();
        
        for (int i = 0; i < doubled.length(); ++i) {
            // Add new character to window
            if (doubled[i] != p1[i]) diff1++;
            if (doubled[i] != p2[i]) diff2++;
            
            // If window size > n, remove the leftmost character
            if (i >= n) {
                if (doubled[i - n] != p1[i - n]) diff1--;
                if (doubled[i - n] != p2[i - n]) diff2--;
            }
            
            // If window size is exactly n, update answer
            if (i >= n - 1) {
                min_flips = min({min_flips, diff1, diff2});
            }
        }
        
        return min_flips;
    }
};