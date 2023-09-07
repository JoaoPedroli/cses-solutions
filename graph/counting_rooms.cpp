#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1010;
 
int n, m;
vector<vector<int>> vis(MAX, vector<int>(MAX, 0));
string adj[MAX];
 
void dfs(int i, int j) {
  if(i<0||i==n||j<0||j==m||vis[i][j]||adj[i][j] == '#') return;
  vis[i][j] = 1;
  dfs(i+1, j), dfs(i-1, j), dfs(i, j+1), dfs(i, j-1);
}
 
int main() {
  cin>>n>>m;
  for(int i = 0; i < n; ++i) cin>>adj[i];
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if(adj[i][j] == '.' && !vis[i][j]) ++ans, dfs(i, j);
    }
  }
  cout<<ans<<'\n';
}
