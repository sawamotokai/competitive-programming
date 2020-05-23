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
  int n; cin >> n;
  vector<string> matrix(n);
  rep(i,n) cin >> matrix[i];
  int top = 0, bottom=n-1;
  string ans(n, 'a');
  auto f = [&]() {
    rep(i, n)
    {
      rep(j, n)
      {
        if (matrix[bottom][i] == matrix[top][j])
        {
          ans[bottom] = matrix[bottom][i];
          ans[top] = matrix[bottom][i];
          return true;
        }
      }
    }
    return false;
  };
   while (bottom >= top)
  {
    if (!f()) {
      cout << -1 << endl;
      return 0;
    }
    bottom--; top++;
  }
  cout << ans << endl;
  return 0;
}