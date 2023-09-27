// Maximum Median

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(vector<int> vec, long long k, long long target) {
    long long  sum = 0;
    for(int i=vec.size()/2; i<vec.size(); i++) {
        if(vec[i] >= target) break;
        sum += target - vec[i];
    }

    if(sum > k) {
        // target needs to be smaller
        return -1;
    } else if(sum < k) {
        // target needs to be bigger
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<int> vec(n);


    for(int i=0; i<n; i++) {
        cin >> vec[i];
    }

    std::sort(vec.begin(), vec.end());

    long long l = vec[vec.size()/2];
    long long r = l + k + 1;
    long long mid;
    long long max_median = l;
    while(l < r) {
        mid = l + (r - l) / 2;
        int result = check(vec, k, mid);
        if(result == -1) {
            r = mid;
        } else {
            max_median = mid;
            l = mid+1;
        }
    }

    cout << max_median << endl;
    
    return 0;
}