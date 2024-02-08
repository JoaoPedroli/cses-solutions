#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n; cin>>n;
  int ns[n];
  for(int i = 0 ;i <n; ++i) {
    cin>>ns[i];
  }
  sort(ns, ns+n);
  long long ans = 0;
  for(int i = 0 ;i < n; ++i) {
    ans += abs(ns[n/2] - ns[i]);
  }
  cout<<ans<<'\n';
}
