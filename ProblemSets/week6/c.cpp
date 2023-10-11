#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> Edge;

int traverse(vector<vector<Edge>> graph, vector<bool> visited, int cur_node) {
    if(visited[cur_node]) return 0;
    visited[cur_node] = true;

    int total_cost = 0;
    for(Edge edge : graph[cur_node]) {
        
    }
    return total_cost;
}

int main() {
    int n;
    cin >> n;

    
    vector<vector<Edge>> graph(n);

    for (int i = 0; i < n; ++i) {
        int src, dest, cost;
        cin >> src >> dest >> cost;

        src--;
        dest--;

        // Add the edge
        graph[src].push_back({dest, cost});
    }

    vector<bool> visited(n, false);

    
    return 0;
}
