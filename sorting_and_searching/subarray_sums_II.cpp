#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, x; cin>>n>>x;
  map<int64_t, int64_t> mp;
  int64_t ans = 0, sum = 0;
  mp[0] = 1;
  for(int i = 0; i < n; ++i) {
    int v; cin>>v;
    sum += v;
    ans += mp[sum - x];
    mp[sum]++;
  }
  cout<<ans<<'\n';
}
