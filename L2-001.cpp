#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define INF 0x3F3F3F3F

int cost[510][510]; // edge weight
int v_weight[510];  // per vertax weight
int v_weight_sum[510];
int dis[510];
bool used[510];
int path[510];
int path_count[510];
int n, m, s, d;

void dijkstra(int s)
{
	fill(dis, dis + n, INF);
	fill(used, used + n, false);
	fill(path, path + n, -1);
	dis[s] = 0;
	path_count[s] = 1;
	v_weight_sum[s] = v_weight[s];

	while (1)
	{
		int v = -1; // current vertex
		for (int u = 0; u < n; u++)
			if (!used[u] && (v == -1 || dis[u] < dis[v]))
				v = u;

		if (v == -1)
			break;

		used[v] = true;

		for (int u = 0; u < n; u++)
		{
			if (dis[u] > dis[v] + cost[v][u])
			{
				dis[u] = dis[v] + cost[v][u];
				path[u] = v;
				path_count[u] = path_count[v];
				v_weight_sum[u] = v_weight_sum[v] + v_weight[u];
			}
			else if(dis[u] == dis[v] + cost[v][u])
			{
				//add previous path count
				path_count[u] += path_count[v];
				if(v_weight_sum[u] < v_weight_sum[v] + v_weight[u])
				{
					v_weight_sum[u] = v_weight_sum[v] + v_weight[u];
					path[u] = v;
				}

			}
		}
	}
}

void print_path(int a)
{
	if (a == s)
	{
		printf("%d", a);
		return;
	}

	print_path(path[a]);
	printf(" %d", a);
}

int main()
{
	// freopen("input.txt", "r", stdin);
	cin >> n >> m >> s >> d;
	for (int i = 0; i < n; i++)
		cin >> v_weight[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cost[i][j] = INF;
	for (int i = 0; i < m; i++)
	{
		int v, u, temp;
		cin >> v >> u;
		cin >> temp;
		cost[v][u] = cost[u][v] = temp;
	}

	dijkstra(s);

	printf("%d %d\n", path_count[d], v_weight_sum[d]);
	print_path(d);

	return 0;
}