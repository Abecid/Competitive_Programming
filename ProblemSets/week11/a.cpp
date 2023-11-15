#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct segment_tree {
    int size;
    vector<bool> tree;

    void init(int n) {
        size = n;
        tree.assign(4 * size, true); // Proper initialization
    }

    void update(int i, int index, bool v, int lx, int rx) {
        if (rx - lx == 1) {
            tree[i] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (index < m) {
            update(2 * i + 1, index, v, lx, m);
        } else {
            update(2 * i + 2, index, v, m, rx);
        }
        tree[i] = tree[2 * i + 1] && tree[2 * i + 2];
    }

    bool query(int i, int l, int r, int lx, int rx) {
        if (l >= rx || r <= lx) return true;
        if (lx >= l && rx <= r) return tree[i];
        int m = (lx + rx) / 2;
        bool left = query(2 * i + 1, l, r, lx, m);
        bool right = query(2 * i + 2, l, r, m, rx);
        return left && right;
    }

    void update(int index, bool v) {
        update(0, index, v, 0, size);
    }

    bool query(int l, int r) {
        if (l <= r) {
            bool route1 = query(0, l, r + 1, 0, size); // Inclusive query
            bool route2 = query(0, 0, l+1, 0, size) && query(0, r, size, 0, size);
            return route1 || route2;
        } else {
            bool route1 = query(0, l, size, 0, size) && query(0, 0, r + 1, 0, size);
            bool route2 = query(0, r, l+1, 0, size);
            return route1 || route2;
            // return query(0, l, size, 0, size) && query(0, 0, r + 1, 0, size); // Handle cyclic nature
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    segment_tree st;
    st.init(n);

    for (int i = 0; i < q; i++) {
        char operation;
        cin >> operation;

        if (operation == '-') {
            int a;
            cin >> a;
            st.update(a - 1, false); // Adjust index to 0-based
        } else if (operation == '+') {
            int a;
            cin >> a;
            st.update(a - 1, true); // Adjust index to 0-based
        } else if (operation == '?') {
            int a, b;
            cin >> a >> b;
            a--; b--; // Adjust indices to 0-based
            cout << (st.query(a, b) ? "possible" : "impossible") << endl;
        }
    }
    return 0;
}
