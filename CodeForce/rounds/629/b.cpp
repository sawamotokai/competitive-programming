#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
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
const ll INF = 1e18L + 1;

int n, k;
set<string> st;

// void dfs(string s, int bcount, int len)
// {
//   if (len == n)
//   {
//     if (bcount == 2)
//       // cout << s << endl;
//       st.insert(s);
//     return;
//   }
//   if (bcount < 2)
//   {
//     dfs(s + 'b', 1 + bcount, 1 + len);
//     dfs(s + 'a', bcount, len + 1);
//   }
//   else
//   {
//     s.append(n - len, 'a');
//     st.insert(s);
//   }
// }

void solve()
{
  st.clear();
  cin >> n >> k;
  string s;

  cout << *ans << endl;
}

int main()
{
  int t;
  cin >> t;
  rep(i, t) solve();
  return 0;
}