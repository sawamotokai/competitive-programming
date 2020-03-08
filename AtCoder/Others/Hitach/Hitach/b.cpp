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
typedef long long ll;
const ll INF = 1e18L + 1;

int a[110000];
int b[110000];

int main()
{
  int A, B, M;
  cin >> A >> B >> M;
  int ans = 1e9 + 1;
  rep(i, A)
  {
    cin >> a[i];
    ans = min(ans, a[i]);
  }
  int minB = 1e9 + 1;
  rep(i, B)
  {
    cin >> b[i];
    minB = min(minB, b[i]);
  }
  ans += minB;
  rep(i, M)
  {
    int x, y, c;
    cin >> x >> y >> c;
    int price = a[x - 1] + b[y - 1] - c;
    ans = min(ans, price);
  }
  cout << ans << endl;
  return 0;
}