#include <bits/stdc++.h>
#include <cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
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
  ll n; cin >> n;
  stack<int> num;
  while (n != 1 && n != 0) {
    if (n & 1) {
      num.push(1);
      n--;
      n /= -2;
    } else {
      num.push(0);
      n /= -2;
    }
  }
  if (n==1) num.push(1);
  else num.push(0);
  while (num.size()) {
    printf("%d", num.top());
    num.pop();
  }
  cout << endl;
  return 0;
}