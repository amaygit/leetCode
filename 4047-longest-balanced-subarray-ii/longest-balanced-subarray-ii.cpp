class SegmentTree {
public:
    struct Node {
        int l, r;
        int mn, mx;
        int lazy;
    };

    vector<Node> tr;

    SegmentTree(int n) {
        tr.resize((n + 1) * 4);
        build(1, 0, n);
    }

    void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        tr[u].mn = tr[u].mx = tr[u].lazy = 0;

        if (l == r) return;

        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    void apply(int u, int v) {
        tr[u].mn += v;
        tr[u].mx += v;
        tr[u].lazy += v;
    }

    void pushDown(int u) {
        if (tr[u].lazy) {
            apply(u << 1, tr[u].lazy);
            apply(u << 1 | 1, tr[u].lazy);
            tr[u].lazy = 0;
        }
    }

    void pushUp(int u) {
        tr[u].mn = min(tr[u << 1].mn, tr[u << 1 | 1].mn);
        tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
    }

    void modify(int u, int l, int r, int val) {
        if (l <= tr[u].l && tr[u].r <= r) {
            apply(u, val);
            return;
        }

        pushDown(u);

        int mid = (tr[u].l + tr[u].r) >> 1;

        if (l <= mid)
            modify(u << 1, l, r, val);

        if (r > mid)
            modify(u << 1 | 1, l, r, val);

        pushUp(u);
    }

    int query(int u, int target) {
        if (tr[u].l == tr[u].r)
            return tr[u].l;

        pushDown(u);

        if (tr[u << 1].mn <= target &&
            target <= tr[u << 1].mx)
            return query(u << 1, target);

        return query(u << 1 | 1, target);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        SegmentTree st(n);

        unordered_map<int, int> last;

        int balance = 0;
        int ans = 0;

        for (int i = 1; i <= n; i++) {

            int x = nums[i - 1];
            int delta = (x & 1) ? 1 : -1;

            if (last.count(x)) {
                st.modify(1, last[x], n, -delta);
                balance -= delta;
            }

            last[x] = i;

            st.modify(1, i, n, delta);
            balance += delta;

            int pos = st.query(1, balance);

            ans = max(ans, i - pos);
        }
        return ans;
    }
};