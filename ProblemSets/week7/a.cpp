/*
Complete Town
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
 
using namespace std;

double distance(const vector<int> a, const vector<int> b) {
    return sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
}

void traverse(vector<vector<int>> towns, vector<double>& total_length, int cur_node=-1, double total_length_so_far = 0) {
    if(cur_node == -1) {
        for(int i=0; i<towns.size(); i++) {
            traverse(towns, total_length, i, 0);
        }
    } else {
        vector<int> prev_node = towns[cur_node];
        int x = prev_node[0];
        int y = prev_node[1];
        towns.erase(towns.begin() + cur_node);
        if(towns.size() == 0) {
            total_length.push_back(total_length_so_far);
            return;
        }
        for(int i=0; i<towns.size(); i++) {
            double distance_so_far = distance(prev_node, towns[i]) + total_length_so_far;
            traverse(towns, total_length, i, distance_so_far);
        }
    }
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> towns;
    vector<double> total_lengths;
    
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        // towns.push_back(vector<int>{a-1, b-1}); 
        towns.emplace_back(vector<int>{a, b});
    }

    traverse(towns, total_lengths);

    double total = 0;
    for(double length : total_lengths) {
        total += length;
    }
    int length = total_lengths.size();
    double average = total / length;
    // cout << average << endl;
    cout << fixed << setprecision(9) << average << endl;
    
    return 0;
}