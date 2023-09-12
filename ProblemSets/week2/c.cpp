#include<bits/stdc++.h>
using namespace std;
#include <vector>

int t;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a;
    vector<int> prefix_sum;

    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        a.push_back(num);
    }

    int sum = 0;
    int rest_sum = 0;

    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        if(num == 0) {
            sum += a[i];
        } else if (num == 1) {
            rest_sum += a[i];
        }
        prefix_sum.push_back(sum);
    }

    int max = 0;

    for(int i=0; i<n-k+1; i++) {
        int right = prefix_sum[i+k-1];
        int left = 0;

        if(i > 0)
            left = prefix_sum[i-1];

        int sum = right - left;
        if(sum > max) {
            max = sum;
        }
    }

    cout << max+rest_sum << endl;

	return 0;
}