#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int INF = 1<<30;
 
signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
 
  int n, m;
  cin>>n>>m;
  string ns[n];
  queue<pair<int, int>> ms;
  int vis[n][m], distm[n][m];
  pair<int, int> start;
  for(int i = 0; i < n; ++i) {
    cin>>ns[i];
    for(int j = 0; j < m; ++j) {
      if(ns[i][j] == 'M') ms.emplace(i, j);
      else if(ns[i][j] == 'A') start = {i, j};
      distm[i][j] = INF;
    }
  }
 
  queue<tuple<int, int, int>> q;
  while(ms.size()) {
    q.emplace(ms.front().first, ms.front().second, 0);
    ms.pop();
  }
 
  const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
  memset(vis, 0, sizeof(vis));
  while(q.size()) {
    const auto [i, j, d] = q.front(); q.pop();
    
    vis[i][j] = 1;
    distm[i][j] = min(distm[i][j], d);
    for(int I = 0; I < 4; ++I) {
      const int ii = di[I] + i, jj = dj[I] + j;
      if(ii < 0 || ii >= n || jj < 0 || jj >= m || vis[ii][jj] || ns[ii][jj] == '#') continue;
      vis[ii][jj] = 1;
      q.emplace(ii, jj, d+1);
    }
  }
  
  memset(vis, 0, sizeof(vis));
  q.emplace(start.first, start.second, 0);
  vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(m, {-1, -1}));
  while(q.size()) {
    const auto [i, j, d] = q.front(); q.pop();
    
    if(i == n-1 || i == 0 || j == m-1 || j == 0) {
      string ans = "";
      pair<int, int> cur = {i, j};
      while(p[cur.first][cur.second].first != -1) {
        const pair<int, int> P = p[cur.first][cur.second];
        if(cur.first < P.first) ans += 'U';
        else if(cur.first > P.first) ans += 'D';
        else if(cur.second < P.second) ans += 'L';
        else ans += 'R';
        cur = p[cur.first][cur.second];
      }
      reverse(ans.begin(), ans.end());
      cout<<"YES\n"<<ans.size()<<'\n';
      cout<<ans<<'\n';
      exit(0);
    }
    vis[i][j] = 1;
    for(int I = 0; I < 4; ++I) {
      const int ii = di[I] + i, jj = dj[I] + j;
      if(ii < 0 || ii >= n || jj < 0 || jj >= m || vis[ii][jj] || ns[ii][jj] == '#' || distm[ii][jj] <= d+1) continue;
      vis[ii][jj] = 1;
      p[ii][jj] = {i, j};
      q.emplace(ii, jj, d+1);
    }
  }
  
  cout<<"NO\n";
}