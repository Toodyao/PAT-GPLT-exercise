#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, k;
int edge[510][510];
int visit[510];

void dfs(int v) {
  visit[v] = 1;
  for (int i = 0; i < n; i++) {
    if (visit[i] == 0 && edge[v][i] == 1)
      dfs(i);
  }
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int fi, se;
    cin >> fi >> se;
    edge[fi][se] = edge[se][fi] = 1;
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (visit[i] == 0) {
      dfs(i);
      count++;
    }
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int city;
    cin >> city;
    for (int j = 0; j < n; j++)
      if (edge[city][j] == 1)
        edge[city][j] = edge[j][city] = 0;
    int tempcount = 0;
    fill(visit, visit+510, 0);
    for (int ii = 0; ii < n; ii++) {
      if (visit[ii] == 0) {
        dfs(ii);
        tempcount++;
      }
    }
    if (tempcount > count + 1)
      printf("Red Alert: City %d is lost!\n", city);
    else
      printf("City %d is lost.\n", city);
    if (i == n-1)
      printf("Game Over.\n");
    count = tempcount;
  }


  return 0;
}