class Solution {
public:
    struct SegTree {
        int n;
        vector<int> tree;

        SegTree(vector<int> &arr) {
            n = arr.size();
            if (n == 0) return;
            tree.assign(4 * n, 0);
            build(1, 0, n - 1, arr);
        }

        void build(int node, int l, int r, vector<int> &arr) {
            if (l == r) {
                tree[node] = arr[l];
                return;
            }

            int mid = (l + r) / 2;

            build(node * 2, l, mid, arr);
            build(node * 2 + 1, mid + 1, r, arr);

            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }

        int query(int node, int l, int r, int ql, int qr) {
            if (ql > r || qr < l) return 0;

            if (ql <= l && r <= qr)
                return tree[node];

            int mid = (l + r) / 2;

            return max(
                query(node * 2, l, mid, ql, qr),
                query(node * 2 + 1, mid + 1, r, ql, qr)
            );
        }

        int query(int l, int r) {
            if (n == 0 || l > r) return 0;
            l = max(l, 0);
            r = min(r, n - 1);
            if (l > r) return 0;
            return query(1, 0, n - 1, l, r);
        }
    };

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {

        int n = s.size();

        vector<int> start, end, len;

        int i = 0;

        while (i < n) {
            if (s[i] == '0') {
                start.push_back(i);

                while (i < n && s[i] == '0')
                    i++;

                end.push_back(i - 1);
                len.push_back(i - start.back());
            } else {
                i++;
            }
        }

        int ini = 0;
        for (char c : s)
            if (c == '1')
                ini++;

        vector<int> pairGain;

        for (int i = 0; i + 1 < len.size(); i++)
            pairGain.push_back(len[i] + len[i + 1]);

        SegTree seg(pairGain);

        vector<int> ans;

        for (auto &it : queries) {

            int l = it[0];
            int r = it[1];

            int low = lower_bound(end.begin(), end.end(), l) - end.begin();
            int high = upper_bound(start.begin(), start.end(), r) - start.begin() - 1;

            if (low >= high) {
                ans.push_back(ini);
                continue;
            }

            int a = end[low] - max(l, start[low]) + 1;
            int b = min(end[high], r) - start[high] + 1;

            int cnt = seg.query(low + 1, high - 2);

            if (low + 1 == high) {
                ans.push_back(a + b + ini);
            } else {

                int pair1 = a + len[low + 1];
                int pair2 = b + len[high - 1];

                cnt = max(cnt, max(pair1, pair2));

                ans.push_back(cnt + ini);
            }
        }

        return ans;
    }
};