#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// Returns number of operations needed to make the median of vec equal to target
long long opsNeeded(vector<int> &vec, long long target) {
    long long sum = 0;
    for(int i = vec.size() / 2; i < vec.size(); i++) {
        if(vec[i] < target) {
            sum += target - vec[i];
        }
    }
    return sum;
}
 
int main() {
    int n;
    long long k;
    cin >> n >> k;
 
    vector<int> vec(n);
 
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }
 
    std::sort(vec.begin(), vec.end());
 
    long long l = vec[n/2];
    long long r = vec[n/2] + k + 1;
    long long answer = l;
 
    while(l < r) {
        long long mid = l + (r - l) / 2;
        if(opsNeeded(vec, mid) <= k) {
            answer = mid;
            l = mid + 1;
        } else {
            r = mid;
        }
    }
 
    cout << answer << endl;
    return 0;
}