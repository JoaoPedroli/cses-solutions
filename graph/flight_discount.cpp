#include <bits/stdc++.h>
#define int long long
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
 
const int MAX = 1e5+5, INF = 1LL<<60;
int n;
 
vector<vector<ii>> ns(MAX);
 
int djk(int s, int T = n) {
  vector<vector<int>> dist(n+2, vector<int>(2, INF)), vis(n+2, vector<int>(2));
  priority_queue<iii, vector<iii>, greater<iii>> pq;
  dist[s][0] = 0;
  pq.emplace(dist[s][0], s, 0);
 
  while(!pq.empty()) {
    auto[d, u, t] = pq.top(); pq.pop();
    if(d > dist[u][t]) continue;
 
    for(ii aux : ns[u]) {
      int v = aux.first, w = aux.second;
      if(dist[u][t] + w < dist[v][t]) {
        dist[v][t] = dist[u][t] + w;
        pq.emplace(dist[v][t], v, t);
      }
      if(t == 0) {
        w /= 2;
        if(dist[u][0] + w < dist[v][1]) {
          dist[v][1] = dist[u][0] + w;
          pq.emplace(dist[v][1], v, 1);
        }
      }
    }
  }
  return dist[T][1];
}
 
signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
 
  int m; cin>>n>>m;
  for(int i = 0; i < m; ++i) {
    int u, v, w; cin>>u>>v>>w;
    ns[u].emplace_back(v, w);
  }
  cout<<djk(1)<<'\n';
}
