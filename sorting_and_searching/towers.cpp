#include <bits/stdc++.h>
using namespace std;
 
multiset<int> ms;
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
 
  int x, n; cin>>n;
  for(int i = 0; i < n; ++i) {
    cin>>x;
    auto aux = ms.upper_bound(x);
    if(aux != ms.end()) {
      if(*aux == x) {
        ++aux;
        if(aux != ms.end()) {
          ms.erase(aux);
        }
      } else ms.erase(aux);
    }
    ms.emplace(x);
  }
  cout<<(int)ms.size()<<'\n';
}
