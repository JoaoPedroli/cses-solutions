#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1e5+5;
 
int n, m;
vector<vector<int>> ns(MAX), nst(MAX);
vector<int> T;
int vis[MAX];
 
void dfs(int u, int pass) {
  vis[u] = 1;
  for(int v : (pass ? ns[u] : nst[u]))
    if(!vis[v]) dfs(v, pass);
  T.emplace_back(u);
}
 
int t;
void dfs(int u) {
  vis[u] = 1;
  for(int v : ns[u]) {
    if(v == t) {
      t = -1;
      return;
    }

    if(!vis[v]) dfs(v);
  }
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(nullptr);
 
  cin>>n>>m;

  for(int i = 0; i < m; ++i) {
    int u, v; cin>>u>>v;
    ns[u].emplace_back(v);
    nst[v].emplace_back(u);
  }
  
  for(int i = 1; i <= n; ++i)
    if(!vis[i]) dfs(i, 1);

  memset(vis, 0, sizeof(vis));

  int scc = 0, a = 0, b = 0;
  for(int i = n-1; i >= 0; --i) {
    if(!vis[T[i]]) {
      if(!scc) a = T[i];
      else b = T[i];
      ++scc;
      dfs(T[i], 0);
    }
  }

  if(scc == 1) {
    cout<<"YES\n";
  } else {
    cout<<"NO\n";
    memset(vis, 0, sizeof(vis));
    t = b;
    dfs(a);
    if(t == -1) cout<<b<<' '<<a<<'\n';
    else cout<<a<<' '<<b<<'\n';
  }
}
