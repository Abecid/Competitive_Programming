#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(int start_x, int start_y, vector<vector<char>>& maze) {
    int n = maze.size(), m = maze[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;

    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if(x == n-1 && y == m-1) return true;

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
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> maze(n, vector<char>(m));
        
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
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(maze[i][j] == 'G') {
                    if(!bfs(i, j, maze)) {
                        cout << "No" << endl;
                        goto next_testcase;
                    }
                }
            }
        }
        cout << "Yes" << endl;

        next_testcase: ; // empty label
    }
    return 0;
}
