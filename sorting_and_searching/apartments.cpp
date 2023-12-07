#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = (1LL<<60), MAX = 2e5+10;
int ns[MAX];
multiset<int> st;
multiset<int>::iterator it;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int n, m, k; cin>>n>>m>>k;
  for(int i = 0; i < n; ++i) {
    cin>>ns[i];
  }
  sort(ns, ns+n);
  for(int i = 0 ; i < m; ++i) {
    int x; cin>>x;
    st.insert(x);
  }
  int ans = 0;
  for(int i = 0; !st.empty() && i < n; ++i) {
    it = st.lower_bound(ns[i] - k);
    if(it != st.end() && abs((*it) - ns[i]) <= k) {
      ++ans, st.erase(it);
    }
  }
  cout<<ans<<'\n';
}
