#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll,ll>;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;

//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  int n,q; cin >> n >> q;
  vector<priority_queue<int>> kins(200001);
  rep(i,n) {
    int a, b; cin >> a >> b;
    b--;
    kins[b].push(a);
  }
  
  return 0;
}