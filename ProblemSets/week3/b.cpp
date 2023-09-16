#include <iostream>
#include <vector>

using namespace std;

// Options
// 100, 20, 10, 5, 1

int main() {
    int n, k, q;
    cin >> n;

    for(int i=0; i<n; i++) {
        int num_monsters;
        cin >> num_monsters;

        int num_ones = 0;
        for(int j=0; j<num_monsters; j++) {
            int num;
            cin >> num;
            if(num == 1) {
                num_ones++;
            }
        }
        int num_moves = num_monsters - num_ones/2;
        cout << num_moves << endl;
    }
    
    return 0;
}
