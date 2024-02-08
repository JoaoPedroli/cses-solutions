#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int n, m; cin>>n>>m;
  multiset<int> ns;
  for(int i = 0; i < n; ++i) {
    int x; cin>>x;
    ns.insert(x);
  }
  for(int i = 0; i < m; ++i) {
    int x; cin>>x;
    if(ns.empty()) {
      cout<<"-1\n";
      continue;
    }
    auto it = ns.lower_bound(x+1);
    if(it == ns.begin()) cout<<"-1\n";
    else {
      --it;
      if(*it > x) cout<<"-1\n";
      else {
        cout<<*it<<'\n';
        ns.erase(it);
      }
    }
  }
}
