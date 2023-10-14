#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+10, MOD = 1e9+7;

int n, m, ns[MAX], memo[MAX][105];

int dp(int i, int ant) {
  if(ant < 1 || ant > m || (ns[i] && abs(ns[i] - ant) > 1)) return 0;
  if(i == n) return 1;
  if(memo[i][ant] != -1) return memo[i][ant];
  if(ns[i] == 0) {
    return memo[i][ant] = (((dp(i+1, ant + 1) % MOD) + (dp(i+1, ant - 1) % MOD)) % MOD + dp(i+1, ant)) % MOD;
  }
  memo[i][ant] = dp(i+1, ns[i]) % MOD;
  return memo[i][ant];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);

  memset(memo, -1, sizeof(memo));
  cin>>n>>m;
  for(int i = 0; i < n; ++i) {
    cin>>ns[i];
  }
  int ans = 0;
  if(ns[0] == 0) {
    for(int i = 1; i <= m; ++i) {
      ns[0] = i;
      ans = ((ans % MOD) + (dp(0, i) % MOD)) % MOD;
    }
  } else ans = dp(0, ns[0]) % MOD;
  cout<<ans<<'\n';
}
