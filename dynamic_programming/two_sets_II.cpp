#include <bits/stdc++.h>
using namespace std;
 
const int mxn = 505, mxm = 125255, MOD = 1e9+7;
 
int n, memo[mxn][mxm], somatorio;
 
int dp(int i, int soma) {
  if(i == n+1) {
    return (abs(soma - somatorio) == soma);
  }
  if(memo[i][soma] != -1) return memo[i][soma];
  return memo[i][soma] = (1ll * dp(i+1, soma) + dp(i+1, soma + i)) % MOD;
}
 
int fpow(int b, int e, int m) {
  int result = 1;
  b %= m;
  while (e > 0) {
    if (e&1) result = (1ll * result * b) % m;
    e >>= 1;
    b = (1ll * b * b) % m;
  }
  return result;
}
 
signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  
  cin>>n;
  memset(memo, -1, sizeof(memo));
  somatorio = n * (n+1) / 2;
  cout<<(1ll * dp(1, 0) * fpow(2, MOD-2, MOD)) % MOD<<'\n';
}