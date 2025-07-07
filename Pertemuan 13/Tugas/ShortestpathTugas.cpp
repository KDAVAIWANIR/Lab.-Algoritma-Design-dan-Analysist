#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;
const int MAX = 20;

vector<string> siswa;
map<string, int> indeks;
int graph[MAX][MAX], dist[MAX], nextNode[MAX];
bool visited[MAX];
int n = 0;

void initSiswa() {
    siswa.push_back("Kyanka");
    siswa.push_back("Dava");
    siswa.push_back("Doni");
    siswa.push_back("Wildan");
    siswa.push_back("Haikal");
    siswa.push_back("Agus");
    siswa.push_back("Rofii");
    siswa.push_back("Jonathan");
    siswa.push_back("Annisa");
    siswa.push_back("Azizah");
    siswa.push_back("Abrar");
    siswa.push_back("Steven");
    siswa.push_back("Yunita");
    siswa.push_back("Nanda");
    siswa.push_back("Martin");
    siswa.push_back("Sudrajat");
    siswa.push_back("Ale");
    siswa.push_back("Agung");

    n = siswa.size();
    for (int i = 0; i < n; ++i)
        indeks[siswa[i]] = i;
}

void addEdge(string u, string v, int w) {
    int a = indeks[u];
    int b = indeks[v];
    graph[a][b] = w;
    graph[b][a] = w;
}

void initGraph() {
    for (int i = 0; i < MAX; ++i)
        for (int j = 0; j < MAX; ++j)
            graph[i][j] = (i == j) ? 0 : INF;

    addEdge("Kyanka", "Dava", 1);
    addEdge("Kyanka", "Abrar", 3);
    addEdge("Abrar", "Azizah", 1);
    addEdge("Abrar", "Steven", 2);
    addEdge("Azizah", "Steven", 1);
    addEdge("Dava", "Azizah", 2);
    addEdge("Dava", "Doni", 1);
    addEdge("Azizah", "Annisa", 1);
    addEdge("Doni", "Annisa", 4);
    addEdge("Doni", "Wildan", 2);
    addEdge("Annisa", "Jonathan", 1);
    addEdge("Annisa", "Yunita", 2);
    addEdge("Wildan", "Jonathan", 1);
    addEdge("Wildan", "Haikal", 4);
    addEdge("Haikal", "Agus", 4);
    addEdge("Jonathan", "Rofii", 2);
    addEdge("Rofii", "Agus", 2);
    addEdge("Rofii", "Agung", 2);
    addEdge("Yunita", "Nanda", 2);
    addEdge("Nanda", "Martin", 1);
    addEdge("Martin", "Sudrajat", 3);
    addEdge("Sudrajat", "Nanda", 4);
    addEdge("Nanda", "Ale", 2);
    addEdge("Ale", "Agung", 1);
}

void dijkstra(int start, int end) {
    for (int i = 0; i < n; ++i) {
        dist[i] = INF;
        visited[i] = false;
        nextNode[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        int minDist = INF;

        for (int j = 0; j < n; ++j) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                nextNode[v] = u;
            }
        }
    }

    if (dist[end] == INF) {
        cout << "Tidak ada jalur yang tersedia.\n";
        return;
    }

    vector<int> path;
    int at = end;
    while (at != -1) {
        path.push_back(at);
        at = nextNode[at];
    }

    reverse(path.begin(), path.end());

    cout << "\nJalur tercepat:\n";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << siswa[path[i]];
        if (i != path.size() - 1) cout << " -> ";
    }
    cout << "\nTotal waktu: " << dist[end] << endl;
}

void floydWarshall() {
    int distFW[MAX][MAX];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            distFW[i][j] = graph[i][j];

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (distFW[i][k] != INF && distFW[k][j] != INF)
                    if (distFW[i][j] > distFW[i][k] + distFW[k][j])
                        distFW[i][j] = distFW[i][k] + distFW[k][j];

    cout << "\nMatriks Jarak Terpendek (Floyd-Warshall):\n\n";

    cout << "\t";
    for (int j = 0; j < n; ++j) cout << siswa[j] << "\t";
    cout << "\n";

    for (int i = 0; i < n; ++i) {
        cout << siswa[i] << "\t";
        for (int j = 0; j < n; ++j) {
            if (distFW[i][j] == INF)
                cout << "-\t";
            else
                cout << distFW[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    initSiswa();
    initGraph();

    cout << "Jalur Tercepat\n";
    string asal, tujuan;
    cout << "Masukkan siswa asal: ";
    cin >> asal;
    cout << "Masukkan siswa tujuan: ";
    cin >> tujuan;

    if (indeks.find(asal) == indeks.end() || indeks.find(tujuan) == indeks.end()) {
        cout << "Nama siswa tidak ditemukan!\n";
        return 0;
    }

    dijkstra(indeks[asal], indeks[tujuan]);

    char pilihan;
    cout << "\nCetak Matriks Jarak Terpendek (Y/T)? ";
    cin >> pilihan;
    if (pilihan == 'Y' || pilihan == 'y') {
        floydWarshall();
    }

    return 0;
}

