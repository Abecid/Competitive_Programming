#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    
    vector<int> temp(200001, 0);
    
    for (int i = 0; i < n; ++i) {
        int li, ri;
        cin >> li >> ri;
        temp[li]++;
        if (ri + 1 < 200001) temp[ri + 1]--;
    }
    
    // Compute the cumulative sum.
    for (int i = 1; i < 200001; ++i) {
        temp[i] += temp[i - 1];
    }
    
    // Convert the temp array as per the k condition.
    for (int i = 0; i < 200001; ++i) {
        if (temp[i] >= k) temp[i] = 1;
        else temp[i] = 0;
    }
    
    // Compute the cumulative sum again.
    for (int i = 1; i < 200001; ++i) {
        temp[i] += temp[i - 1];
    }
    
    // Answer the queries.
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << temp[b] - (a == 1 ? 0 : temp[a - 1]) << endl;
    }
    
    return 0;
}
