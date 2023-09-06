#include<bits/stdc++.h>
using namespace std;
#include <vector>

int t;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a;
    vector<int> prefix_sum;

    int sum = 0;

	while(n--) {
		int num;
		cin >> num;
        a.push_back(num);
        sum += num;
        prefix_sum.push_back(sum);
	}

    vector<int> next_k_sum;

    int min = -1;
    int min_index = -1;
    for(int i=0; i<n-(k-1); i++) {
        int sum;

        if(i == 0) {
            sum = prefix_sum[i+k-1];
        } else {
            sum = prefix_sum[i+k-1] - prefix_sum[i-1];
        }

        next_k_sum.push_back(sum);
        if(sum < min || min == -1){
            min = sum;
            min_index = i;
        }
    }

    cout << min_index+1 << endl;

	return 0;
}