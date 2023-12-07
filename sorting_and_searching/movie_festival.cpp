#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int n; cin>>n;
  vector<pair<int, int>> ns(n);
  for(int i = 0; i < n; ++i) {
    cin>>ns[i].first>>ns[i].second;
  }
  sort(ns.begin(), ns.end(), [](pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second) return a.second < b.second;
    return a.first > b.first;
  });
  int cur = 0, ans = 0;
  for(int i = 0; i < n; ++i) {
    if(cur > ns[i].first) continue;
    ++ans, cur = ns[i].second;
  }
  cout<<ans<<'\n';
}
