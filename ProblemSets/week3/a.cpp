#include <iostream>
#include <vector>

using namespace std;

// Options
// 100, 20, 10, 5, 1

int main() {
    int n, k, q;
    cin >> n;
    
    vector<int> bills = {100, 20, 10, 5, 1};

    int total = 0;

    for (int i = 0; i < bills.size(); ++i) {
        total += n / bills[i];
        n %= bills[i];
    }

    cout << total << endl;
    
    return 0;
}
