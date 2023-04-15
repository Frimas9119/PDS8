#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

const int MAXN = 100;

int n, m;
int graph[MAXN][MAXN];
int dfs_num[MAXN]; // номер вершини у порядку DFS-обходу
bool visited[MAXN]; // масив відвіданих вершин

void DFS(int start) {
    stack<int> S; // стек вершин, які потрібно відвідати
    S.push(start); // додаємо початкову вершину до стеку

    int num = 0; // лічильник вершин у порядку DFS-обходу

    while (!S.empty()) {
        int v = S.top(); // беремо вершину з вершини стеку
        S.pop(); // видаляємо вершину з вершини стеку

        if (!visited[v]) {
            visited[v] = true; // позначаємо вершину як відвідану
            dfs_num[v] = ++num; // присвоюємо номер у порядку DFS-обходу

            cout << "Visiting vertex " << v << " (DFS number " << dfs_num[v] << ")" << endl;

            // додаємо до стеку всіх сусідів вершини v, які ще не відвідані
            for (int i = n - 1; i >= 0; i--) {
                if (graph[v][i] == 1 && !visited[i]) {
                    S.push(i);
                }
            }
        }
    }
}

int main() {
    ifstream fin("input.txt");
    fin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // заповнення матриці суміжності
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        graph[u - 1][v - 1] = 1;
        graph[v - 1][u - 1] = 1;
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;
    DFS(start);

    return 0;
}
