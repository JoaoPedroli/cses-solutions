#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = 1e5+5;
vector<int> ns[MAX], vis(MAX), p(MAX);
 
void dfs(int u, int pai) {
  if(vis[u]) {
    int cur = pai;
    vector<int> ans;
    ans.emplace_back(u);
    while(cur != u) {
      ans.emplace_back(cur);
      cur = p[cur];
    }
    ans.emplace_back(u);
    cout<<ans.size()<<'\n';
    for(int v : ans) cout<<v<<' ';
    cout<<'\n';
    exit(0);
  }
  vis[u] = 1;
  p[u] = pai;
  for(int v : ns[u]) {
    if(v == pai) continue;
    dfs(v, u);
  }
}
 
signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
 
  int n, m; cin>>n>>m;
  for(int i = 0; i < m; ++i) {
    int u, v; cin>>u>>v;
    ns[u].push_back(v);
    ns[v].push_back(u);
  }
  for(int i = 1; i <= n; ++i) {
    if(!vis[i]) dfs(i, i);
  }
  cout<<"IMPOSSIBLE\n";
}