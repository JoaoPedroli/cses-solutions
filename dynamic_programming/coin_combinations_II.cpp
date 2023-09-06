#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+5, MOD = 1e9+7;

int64_t n, m;
vector<int64_t> cs, dp(MAX);
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
 
  cin>>n>>m;
  cs.resize(n);
  for(auto &v : cs) cin>>v;
  sort(cs.begin(), cs.end());
  dp[0] = 1;
  for(int i = 0; i < n; ++i) {
    for(int k = 0; k < m; ++k) {
      if(k + cs[i] > m) continue;
      if(dp[k] != -1) {
        dp[k+cs[i]] = (dp[k+cs[i]] + dp[k]) % MOD;
      }
    }
  }
  cout<<dp[m]<<'\n';
}
