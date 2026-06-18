class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total = 0;
        double low = 1e18, high = 0;

        for (auto &s : squares) {
            double y = s[1];
            double l = s[2];

            total += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double target = total / 2.0;

        auto areaBelow = [&](double h) {
            double area = 0;

            for (auto &s : squares) {
                double y = s[1];
                double l = s[2];

                if (h <= y) {
                    continue;
                } else if (h >= y + l) {
                    area += l * l;
                } else {
                    area += l * (h - y);
                }
            }

            return area;
        };

        for (int i = 0; i < 70; i++) {
            double mid = (low + high) / 2.0;

            if (areaBelow(mid) < target)
                low = mid;
            else
                high = mid;
        }

        return high;
    }
};