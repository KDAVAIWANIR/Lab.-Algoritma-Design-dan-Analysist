#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

typedef pair<int, int> pii;

void dijkstra(int src, int dest, vector<vector<pii>>& graph, int n) {
    vector<int> dist(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (curDist > dist[u]) continue;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[dest] == INF)
        cout << "Tidak ada jalur dari node " << src << " ke node " << dest << endl;
    else
        cout << "Jarak terpendek dari node " << src << " ke node " << dest << " adalah " << dist[dest] << endl;
}

int main() {
    int n = 6; // Jumlah node

    vector<vector<pii>> graph(n + 1);

    // Tambahkan edge sesuai gambar
    graph[1].push_back({2, 7});
    graph[1].push_back({3, 10});
    graph[1].push_back({6, 14});

    graph[2].push_back({1, 7});
    graph[2].push_back({3, 9});
    graph[2].push_back({4, 15});

    graph[3].push_back({1, 10});
    graph[3].push_back({2, 9});
    graph[3].push_back({4, 11});
    graph[3].push_back({6, 2});

    graph[4].push_back({2, 15});
    graph[4].push_back({3, 11});
    graph[4].push_back({5, 6});

    graph[5].push_back({4, 6});
    graph[5].push_back({6, 9});

    graph[6].push_back({1, 14});
    graph[6].push_back({3, 2});
    graph[6].push_back({5, 9});

    dijkstra(1, 5, graph, n);

    return 0;
}

