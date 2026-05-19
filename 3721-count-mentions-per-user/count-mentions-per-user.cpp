class Solution {
public:

    static bool cmp(vector<string>& a, vector<string>& b) {

        int t1 = stoi(a[1]);
        int t2 = stoi(b[1]);

        if (t1 == t2) {

            // OFFLINE first
            if (a[0] == b[0]) return false;

            return a[0] == "OFFLINE";
        }

        return t1 < t2;
    }

    vector<int> countMentions(
        int numberOfUsers,
        vector<vector<string>>& events) {

        sort(events.begin(), events.end(), cmp);

        vector<int> ans(numberOfUsers, 0);

        vector<int> offlineUntil(numberOfUsers, 0);

        for (auto &e : events) {

            int time = stoi(e[1]);

            if (e[0] == "OFFLINE") {

                int id = stoi(e[2]);

                offlineUntil[id] = time + 60;
            }
            else {

                string s = e[2];

                if (s == "ALL") {

                    for (int i = 0; i < numberOfUsers; i++)
                        ans[i]++;
                }
                else if (s == "HERE") {

                    for (int i = 0; i < numberOfUsers; i++) {

                        if (offlineUntil[i] <= time)
                            ans[i]++;
                    }
                }
                else {

                    stringstream ss(s);
                    string token;

                    while (ss >> token) {

                        int id = stoi(token.substr(2));
                        ans[id]++;
                    }
                }
            }
        }

        return ans;
    }
};