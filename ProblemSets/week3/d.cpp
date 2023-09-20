#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num, k, q;
    cin >> num;

    for(int i=0; i<num; i++) {
        int n;
        cin >> n;

        vector<int> sheep;

        for(int j=0; j<n; j++) {
            char c;
            cin >> c;
            if(c == '*') {
                sheep.push_back(j);
            }
        }

        int mid = sheep.size()/2;

        long long total = 0;

        for(int j=0; j<sheep.size(); j++) {
            total += abs(sheep[j] - sheep[mid]) - abs(j - mid) ;
        }

        cout << total << endl;
    }
    
    return 0;
}
