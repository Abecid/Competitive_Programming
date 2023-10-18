#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
    // Initialize dp array with -1
    vector<int> dp(n+1, -1);
    dp[0] = 0;

    for(int i=1; i<=n; i++) {
        // Check for a
        if(i-a >= 0 && dp[i-a] != -1) {
            dp[i] = max(dp[i], dp[i-a] + 1);
        }
        
        // Check for b
        if(i-b >= 0 && dp[i-b] != -1) {
            dp[i] = max(dp[i], dp[i-b] + 1);
        }
        
        // Check for c
        if(i-c >= 0 && dp[i-c] != -1) {
            dp[i] = max(dp[i], dp[i-c] + 1);
        }
    }

    // Print the result
    cout << dp[n] << endl;
    
    return 0;
}
