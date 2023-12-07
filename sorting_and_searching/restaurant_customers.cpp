#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  map<int, int> mp;
  int n; cin>>n;
  for(int i = 0; i < n; ++i) {
    int a, b; cin>>a>>b;
    mp[a]++, mp[b]--;
  }
  int cur = 0, ans = 0;
  for(pair<int, int> v : mp) {
    cur += v.second;
    ans = max(ans, cur);
  }
  cout<<ans<<'\n';
}
