class SegmentTree {
private:
    vector<int> cnt;
    vector<long long> len;
    vector<long long> xs;
    int n;

    void pushUp(int u, int l, int r) {
        if (cnt[u] > 0) {
            len[u] = xs[r + 1] - xs[l];
        } else if (l == r) {
            len[u] = 0;
        } else {
            len[u] = len[u << 1] + len[u << 1 | 1];
        }
    }

    void update(int u, int l, int r,
                int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            cnt[u] += val;
            pushUp(u, l, r);
            return;
        }

        int mid = (l + r) >> 1;

        if (ql <= mid)
            update(u << 1, l, mid, ql, qr, val);

        if (qr > mid)
            update(u << 1 | 1, mid + 1, r, ql, qr, val);

        pushUp(u, l, r);
    }

public:
    SegmentTree(vector<long long>& coords) {
        xs = coords;
        n = xs.size() - 1;
        cnt.assign(n * 4, 0);
        len.assign(n * 4, 0);
    }

    void update(int l, int r, int val) {
        if (l > r) return;
        update(1, 0, n - 1, l, r, val);
    }

    long long query() {
        return len[1];
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {

        struct Event {
            long long y;
            long long x1;
            long long x2;
            int type;
        };

        vector<Event> events;
        vector<long long> xs;

        for (auto& s : squares) {
            long long x = s[0];
            long long y = s[1];
            long long l = s[2];

            events.push_back({y, x, x + l, 1});
            events.push_back({y + l, x, x + l, -1});

            xs.push_back(x);
            xs.push_back(x + l);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        sort(events.begin(), events.end(),
             [](const Event& a, const Event& b) {
                 return a.y < b.y;
             });

        unordered_map<long long, int> mp;
        for (int i = 0; i < xs.size(); i++)
            mp[xs[i]] = i;

        SegmentTree seg(xs);

        // ---------- First sweep ----------
        long double totalArea = 0;
        long long prevY = events[0].y;

        for (auto& e : events) {
            totalArea +=
                (long double)(e.y - prevY) * seg.query();

            seg.update(
                mp[e.x1],
                mp[e.x2] - 1,
                e.type
            );

            prevY = e.y;
        }

        long double target = totalArea / 2.0;

        // ---------- Second sweep ----------
        SegmentTree seg2(xs);

        long double area = 0;
        prevY = events[0].y;

        for (auto& e : events) {

            long long width = seg2.query();

            long double strip =
                (long double)(e.y - prevY) * width;

            if (area + strip >= target) {
                return (double)(
                    prevY +
                    (target - area) / width
                );
            }

            area += strip;

            seg2.update(
                mp[e.x1],
                mp[e.x2] - 1,
                e.type
            );

            prevY = e.y;
        }

        return 0.0;
    }
};