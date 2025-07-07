#include <bits/stdc++.h>
#define MAX 100005
#define INF INT_MAX

using namespace std;

vector<pair<int, int> > adj[MAX];
bool vis[MAX];
int dist[MAX];

void dijkstra(int start)
{
	memset(vis, false, sizeof vis);
	for (int i = 0; i < MAX; i++)
		dist[i] = INF;
	dist[start] = 0;
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({0, start});
	
	while (!pq.empty())
	{
		pair<int, int> p = pq.top();
		pq.pop();
		
		int x = p.second;
		if (vis[x])
			continue;
		vis[x] = true;
		
		for (int i = 0; i < adj[x].size(); i++)
		{
			int e = adj[x][i].first;
			int w = adj[x][i].second;
			if (dist[x] + w < dist[e])
			{
				dist[e] = dist[x] + w;
				pq.push({dist[e], e});
			}
		}
	}
}

int main() {
    int n = 6; 

	adj[1].push_back({1, 14});
	adj[6].push_back({6, 14});
	adj[1].push_back({1, 7});
	adj[2].push_back({2, 7});
	adj[1].push_back({1, 9});
	adj[3].push_back({3, 9});
	adj[2].push_back({2, 10});
	adj[3].push_back({3, 10});
	adj[3].push_back({3, 11});
	adj[4].push_back({4, 11});
	adj[4].push_back({4, 15});
	adj[2].push_back({2, 15});
	adj[4].push_back({4, 6});
	adj[5].push_back({5, 6});
	adj[5].push_back({5, 9});
	adj[6].push_back({6, 9});
	
	dijkstra(1);
	cout << "Jarak terpendek dari node 1 ke node 5 adalah " << dist[5] << endl;
	
	
	return 0;
}
