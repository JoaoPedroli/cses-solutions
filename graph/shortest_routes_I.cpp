#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, int>;
 
const int MAX = 1e5+5;
const ll INF = 1LL<<60;
 
int n, m;
vector<vector<ii>> ns(MAX);
 
void djk(int s, int t = n) {
  vector<ll> dist(n+2, INF);
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  dist[s] = 0;
  pq.emplace(dist[s], s);
 
  while(!pq.empty()) {
    ll d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if(d > dist[u]) continue;
 
    for(ii aux : ns[u]) {
      const int v = aux.first, w = aux.second;
      if(dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.emplace(dist[v], v);
      }
    }
  }
  for(int i = 1; i <= n; ++i) {
    cout<<dist[i]<<" \n"[i==n];
  }
}
 
int main() {
  cin>>n>>m;
  int u, v, w;
  while(m--) {
    cin>>u>>v>>w;
    ns[u].emplace_back(v, w);
  }
  djk(1);
}
