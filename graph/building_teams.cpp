#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1e5+5;
vector<int> ns[MAX], vis(MAX);
 
void dfs(int u, int c) {
  if(vis[u] && vis[u] != c) {
    cout<<"IMPOSSIBLE\n";
    exit(0);
  }
  if(vis[u]) return;
  vis[u] = c;
  for(int v : ns[u]) {
    dfs(v, c^3);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
 
  int n, m; cin>>n>>m;
  for(int i = 0; i < m; ++i) {
    int u, v;
    cin>>u>>v;
    ns[u].emplace_back(v);
    ns[v].emplace_back(u);
  }
  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) dfs(i, 1);
  }
  for(int i = 1; i <= n; ++i) cout<<vis[i]<<" \n"[i==n];
}