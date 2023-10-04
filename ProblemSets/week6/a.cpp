/*
Kefa and Park
*/

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

bool isLeaf(vector<vector<int> > &adjacencyList, int node) {
    return adjacencyList[node].size() == 0;
}

bool isCat(vector<int> &cats, int node) {
    return cats[node] == 1;
}

int checkNode(vector<vector<int> > &adjacencyList, vector<int> &cats, int index, int m, int consecutiveCats = 0) {
    if(isCat(cats, index)) {
        consecutiveCats++;
    } else {
        consecutiveCats = 0;
    }

    if(consecutiveCats > m) {
        return 0;
    }

    if(isLeaf(adjacencyList, index)) {
        return 1;
    }

    int total = 0;
    

    for(int i=0; i<adjacencyList[index].size(); i++) {
        total += checkNode(adjacencyList, cats, adjacencyList[index][i], m, consecutiveCats);
    }

    return total;
}
 
int main() {
    long long n;
    long long m;
    cin >> n >> m;
 
    vector<int> cats(n);

    vector<vector<int> > adjacencyList (n);
 
    for(int i = 0; i < n; i++) {
        cin >> cats[i];
    }

    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adjacencyList[a-1].push_back(b-1);
        // adjacencyList[b-1].push_back(a-1);
    }

    int answer = checkNode(adjacencyList, cats, 0, m);
    
    cout << answer << endl;
    
    return 0;
}