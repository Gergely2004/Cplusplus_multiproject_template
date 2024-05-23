#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("be.txt");
ifstream fin1("hazi.txt");

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

int pathlength[15]={0};
void dfsX(int u) {
    color[u] = 1;
    cout << u << " ";
    for (int i = 0; i < adjList[u].size(); ++i) {
        int v = adjList[u][i];
        if (color[v] == 0) {
            pathlength[v] = pathlength[u]+1;
            dfsX(v);
        }
    }
    color[u] =2;
}


int main() {
    int feladatszam;
    cout << "ORAI ANYAG / HAZI FELADAT [1 / 2]" << endl;
    cin >> feladatszam;
    switch (feladatszam) {
        case 1: {
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
        }
        case 2: {
            int x, y, c;
            fin1 >> n >> m;
            int X;  //a megadott informacio a nagyfonokhoz valo eljutasi ideje - X ora
            cout << "Add meg az orak szamat: ";
            cin >> X;
            stack <int> track;
            cout << "DFS Traversal: " << endl;
            dfsX(1);
            cout << endl;
            cout << "Alkalmazottak akiknek eler a jelentese: " << endl;
            for (int i = 0; i < n; ++i) {
                if(pathlength[i] <= X && color[i] != 0){
                    cout << i << " ";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
