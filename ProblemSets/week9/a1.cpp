#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

int main() {
    int n;
    cin >> n;
    
    vector<int> dp(8, INF);
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) {
        int cost;
        string vitamins;
        cin >> cost >> vitamins;

        // Compute the bitmask for this juice
        int mask = 0;
        for (char v : vitamins) {
            if (v == 'A') mask |= 1;
            else if (v == 'B') mask |= 2;
            else if (v == 'C') mask |= 4;
        }

        // Update the dp table
        for (int j = 0; j < 8; j++) {
            dp[j | mask] = min(dp[j | mask], dp[j] + cost);
        }
    }

    if (dp[7] == INF) {
        cout << -1 << endl;
    } else {
        cout << dp[7] << endl;
    }

    return 0;
}
