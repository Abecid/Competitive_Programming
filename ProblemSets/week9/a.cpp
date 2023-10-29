/*
Vitamins
*/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int INF = 1e9+7;

int main() {
  int n;
  cin >> n;

  // a, b, c, ab, bc, ac, abc
  int arr[7] = {};
  int arr2[3] = {};

  for(int i=0; i<n; i++) {
    string s;
    int cost;
    cin >> cost >> s;
    sort(s.begin(), s.end());
    if(s == "A") {
        if(arr[0] == 0 || arr[0] > cost)
            arr[0] = cost;
    } else if(s == "B") {
        if(arr[1] == 0 || arr[1] > cost)
            arr[1] = cost;
    } else if(s == "C") {
        if(arr[2] == 0 || arr[2] > cost)
            arr[2] = cost;
    } else if(s == "AB" || s == "BA") {
        if(arr[3] == 0 || arr[3] > cost)
            arr[3] = cost;
        if(arr2[0] == 0 || arr2[0] > cost)
            arr2[0] = cost;
    } else if(s == "BC" || s == "CB") {
        if(arr[4] == 0 || arr[4] > cost)
            arr[4] = cost;
        if(arr2[1] == 0 || arr2[1] > cost)
            arr2[1] = cost;
    } else if(s == "AC" || s == "CA") {
        if(arr[5] == 0 || arr[5] > cost)
            arr[5] = cost;
        if(arr2[2] == 0 || arr2[2] > cost)
            arr2[2] = cost;
    } else {
        if(arr[6] == 0 || arr[6] > cost)
            arr[6] = cost;
    }
  }

  int min_cost = -1;

  int num_vitamins = 3;
  for(int i=0; i<num_vitamins; i++) {
    if(arr[i] == 0 || arr[(i+1)%num_vitamins] == 0) continue;
    int sum = arr[i] + arr[(i+1)%num_vitamins];
    if(arr2[i] == 0 || arr2[i] > sum) arr2[i] = sum;
  }

  int individual_sum = 0;
  for(int i=0; i<num_vitamins; i++) {
        if(arr[i] == 0) {
            individual_sum = 0;
            break;
        }
        individual_sum += arr[i];
  }

    if(individual_sum != 0) {
        if(arr[6] == 0 || arr[6] > individual_sum) arr[6] = individual_sum;
    }

    for(int i=0; i<num_vitamins; i++) {
        int sum = 0;
        if(arr2[i] != 0 && arr[(i+2)%num_vitamins] != 0) {
            sum = arr2[i] + arr[(i+2)%num_vitamins];
        }
        if(arr2[i] != 0 && arr2[(i+1)%num_vitamins] != 0) {
            int sum2 = arr2[i] + arr2[(i+1)%num_vitamins];
            if(sum == 0 || sum2 < sum) sum = sum2;
        }
        if(sum == 0) continue;
        if(arr[6] == 0 || arr[6] > sum) arr[6] = sum;
    }

    if(arr[6] != 0)
        cout << arr[6] << endl;
    else cout << -1 << endl;

  return 0;
}