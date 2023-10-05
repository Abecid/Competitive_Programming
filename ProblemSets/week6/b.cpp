#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs_exit(int start_x, int start_y, vector<vector<char>>& maze, vector<vector<bool>>& visited) {
    int n = maze.size(), m = maze[0].size();
    
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;

    int total_gs = 0;

    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if(maze[x][y] == 'B') return -1;
        if(maze[x][y] == 'G') total_gs++;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && maze[nx][ny] != '#') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return total_gs;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        int gs = 0;
        int num_gs;
        cin >> n >> m;
        vector<vector<char>> maze(n, vector<char>(m));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> maze[i][j];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(maze[i][j] == 'B') {
                    int dx[] = {0, 0, 1, -1};
                    int dy[] = {1, -1, 0, 0};
                    for(int k = 0; k < 4; k++) {
                        int nx = i + dx[k], ny = j + dy[k];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                            if(maze[nx][ny] == 'G') {
                                cout << "No" << endl;
                                goto next_testcase;
                            } else if(maze[nx][ny] == '.') {
                                maze[nx][ny] = '#';
                            }
                        }
                    }
                }
                if(maze[i][j] == 'G') gs++;
            }
        }

        if(gs == 0) {
            cout << "Yes" << endl;
            goto next_testcase;
        }

        if(maze[n-1][m-1] == '#') {
            cout << "No" << endl;
            goto next_testcase;
        }

        num_gs = bfs_exit(n-1, m-1, maze, visited);
        
        if(num_gs == -1)
            cout << "No" << endl;
        else if(num_gs == gs)
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;

        next_testcase: ;
    }
    return 0;
}
