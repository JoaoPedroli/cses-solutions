#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  int n; cin>>n;
  int ns[n];
  for(int i = 0; i < n; ++i) {
    cin>>ns[i];
  }
  int i = 0, j = 0;
  set<int> st;
  map<int, int> frq;
  st.insert(ns[0]);
  frq[ns[0]]++;
  int ans = 1;
  while(j < n) {
    if((j-i+1) > (int)st.size()) {
      --frq[ns[i]];
      if(!frq[ns[i]]) st.erase(ns[i]);
      ++i;
      if(i > j) {
        ++j;
        if(j < n) st.insert(ns[j]), ++frq[ns[j]];
      }
    } else {
      ans = max(ans, (j-i+1));
      ++j;
      if(j < n) st.insert(ns[j]), ++frq[ns[j]];
    }
  }
  cout<<ans<<'\n';
}
