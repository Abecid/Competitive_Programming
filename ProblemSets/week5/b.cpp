#include <iostream>
#include <vector>

using namespace std;

bool canCover(vector<int> cities, vector<int> towers, int r) {
    int j = 0;
    for(int i=0;i<cities.size();i++) {
        while(j < towers.size() && abs(cities[i] - towers[j]) > r) {
            j++;
        }
        if(j == towers.size()) return false;
    }
    return true;
}

int main() {
    long long n, m;
    cin >> n >> m;

    vector<int> cities(n);
    vector<int> towers(m);

    for (int& city : cities) cin >> city;
    for (int& tower : towers) cin >> tower;

    int l = 0;
    int r = max(cities[cities.size()-1] - towers[0], towers[m-1]-cities[0]);

    while(l < r) {
        int mid = l + (r - l) / 2;
        if(canCover(cities, towers, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    
    cout << l << endl;
    
    return 0;
}
