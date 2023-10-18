/*
Cut Ribbon
*/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  // Set size to k
  vector<int> ribbons;
  vector<int> nums;

  // int a, b, c;
  // cin >> n >> a >> b >> c;
  int k = 3;
  unordered_map<int, int> myMap;

  for (int i = 0; i < k; i++) {
    int num;
    cin >> num;
    ribbons.push_back(num);
  }

  sort(ribbons.begin(), ribbons.end());

  // nums.push_back(ribbons[0]);

  for (int i = 0; i < ribbons.size(); i++) {
    if (ribbons[i] == n) {
      cout << 1 << endl;
      return 0;
    }
    if (myMap.find(ribbons[i]) == myMap.end()) {
      myMap[ribbons[i]] = 1;
      nums.push_back(ribbons[i]);
    }
    int t = nums.size();
    for (int j = 0; j < t - 1; j++) {
      int sum = nums[j] + ribbons[i];
      if (sum <= n) {
        if (myMap.find(sum) == myMap.end()) {
          myMap[sum] = myMap[nums[j]] + 1;
          nums.push_back(sum);
        }
        myMap[sum] = max(myMap[sum], myMap[nums[j]] + 1);
        if (sum == n) {
          cout << myMap[sum] << endl;
          return 0;
        }
      }
    }
  }

  cout << n << endl;

  return 0;
}