#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("be.txt");

int n, m;
int adjMat[100][100];
vector<int> adjList[100];
int color[100];

void dfs(int u) {
    color[u] = 1;
    cout << u << " ";
    for (int v : adjList[u]) {
        if(color[v] == 0) {
            dfs(v);
        }
    }
    color[u] = 2;
}

int main() {
    int x, y, c;
    fin >> n >> m;
    for (int i = 0; i < m; ++i) {
        fin >> x >> y >> c;
        adjMat[x][y] = adjMat[y][x] = c;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << i << ": ";
        for (auto it: adjList[i]) {
            cout << it << " -> ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    dfs(1);

    return 0;
}
