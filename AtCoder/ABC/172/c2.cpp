#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ok() puts(ok?"Yes":"No");
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
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
int ans = 0;
ll k;
vector<ll> a, b;
ll get_a(int i)
{
  if (a.size() - 1 - i >= 0)
    return a[a.size() - 1 - i];
  return LINF;
}
ll get_b(int i)
{
  if (b.size() - 1 - i >= 0)
    return b[b.size() - 1 - i];
  return LINF;
}

int f(int i, int j, ll sum=0)
{
  ll na = get_a(i);
  ll nb = get_b(j);
  if (min(na, nb) + sum > k) return 0;
  if (na == nb) {
    if (na == LINF) return 0;
    return 1 + max(f(i + 1, j, sum + na), f(i, j + 1, sum + nb));
  }
  if (na < nb) {
    return 1 + f(i + 1, j, sum + na);
  }
  else {
    return 1 + f(i, j + 1, sum + nb);
  }
}

int main() {
  ll n,m; cin >> n>> m>>k;
  a.resize(n);
  b.resize(m);
  rep(i,n) {
    cin >> a[i];
  }
  rep(i,m) {
    cin >> b[i];
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());


  cout << f(0,0) << endl;

  return 0;
}

