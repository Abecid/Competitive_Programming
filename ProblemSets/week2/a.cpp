#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {

}

int t;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    string s;
    cin >> s;

    vector<int> prefix_sum;

    char prev = s[0];

    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        int equals = 0;
        
        if(i == s.length()-1) {
            prefix_sum.push_back(prefix_sum[i-1]);
            break;
        }
        if(c == s[i+1]) {
            equals = 1;
        }

        if(i == 0) {
            prefix_sum.push_back(equals);
            prev = c;
            continue;
        }

        prefix_sum.push_back(prefix_sum[i-1] + equals);
        prev = c;
    }

    // Read the number of queries m
    int m;
    cin >> m;

    // Read each query
    for(int i = 0; i < m; i++) {
        int li, ri;
        cin >> li >> ri;
        li--;
        ri--;

        if(li == 0)
            cout << prefix_sum[ri-1] << endl;
        else
            cout << (prefix_sum[ri-1] - prefix_sum[li-1]) << endl;
    }

	return 0;
}