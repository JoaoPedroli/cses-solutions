#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5+10;

int ns[MAX], vis[MAX]={0};
set<pair<int, int>> s;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int n, m; cin>>n>>m;
  for(int i = 0; i < n; ++i) {
    cin>>ns[i];
    s.insert({ ns[i], i });
  }
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    if(vis[i]) continue;
    const auto pos = s.lower_bound({ ns[i], i });
    s.erase(pos);
    ++ans;
    auto aux = s.lower_bound({ m - ns[i], -1 });
    if(aux == s.end()) {
      if(int(s.size())) {
        auto aux1_ = aux;
        const auto aux1 = (--aux1_);
        if((*aux1).first + ns[i] <= m) {
          vis[(*aux1).second] = 1;
          s.erase(aux1);
        }
      }
    } else if((*aux).first + ns[i] <= m) {
      vis[(*aux).second] = 1;
      s.erase(aux);
    } else if(aux != s.begin()) {
      auto aux1_ = aux;
      const auto aux1 = (--aux1_);
      if((*aux1).first + ns[i] <= m) {
        vis[(*aux1).second] = 1;
        s.erase(aux1);
      }
    }
  }
  cout<<ans<<'\n';
}
