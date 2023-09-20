#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int max_r = 0;

    vector<int> cities;
    vector<int> towers;


    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        cities.push_back(x);
    }

    for(int i=0; i<m; i++) {
        int x;
        cin >> x;
        towers.push_back(x);
    }

    int l = 0;
    int r = 1;
    if(m == 1) r = 0;

    for(int i=0; i<n; i++) {
        int city = cities[i];
        int tower_l = towers[l];
        int tower_r = towers[r];

        int diff_1 = abs(city - tower_l);
        int diff_2 = abs(city - tower_r);

        while(diff_2 <= diff_1 && l != r && r < m-1) {
            l++;
            r++;
            tower_l = towers[l];
            tower_r = towers[r];
            diff_1 = abs(city - tower_l);
            diff_2 = abs(city - tower_r);
        }

        if(min(diff_1, diff_2) > max_r) {
            max_r = min(diff_1, diff_2);
        }

        // if(diff_2 < diff_1 & l != r) {
        //     l++;
        //     r++;
        // }
    }

    cout << max_r << endl;
    
    return 0;
}
