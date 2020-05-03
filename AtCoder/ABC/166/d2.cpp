#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef set<int> si;
typedef map<string, int> msi;
typedef greater<int> gt;
typedef priority_queue<int, vector<int>, gt> minq;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
//clang++ -std=c++11 -stdlib=libc++ 

int main() {
  ll x; cin >> x;
  for(int a=0; a<1000; a++) {
    for (int b=0; b<1000; b++) {
      ll ans1 = pow(a, 5) - pow(b,5);
      ll ans2 = pow(a, 5) - pow(-b,5);
       if (ans1 == x) {
        printf("%d %d\n", a, b);
        return 0;
      }
      if (ans2 == x) {
        printf("%d %d\n", a, -b);
        return 0;
      }
    }
  }
  return 0;
} 