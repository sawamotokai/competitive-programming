#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
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
typedef long long ll;
const ll INF = 1e18L + 1;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll right = pow(c - a - b, 2);
  ll left = 4*a * b;
  bool ok = false;
  // if (sqrt(a) + sqrt(b) < sqrt(c))
  //   ok = true;
  if (left<right && (c - a - b) >= 0)  
    ok = true;
  puts(ok ? "Yes" : "No");
  return 0;
}