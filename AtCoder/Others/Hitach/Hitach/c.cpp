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

ii edges[200010];
int main()
{
  int n;
  cin >> n;
  rep(i, n)
  {
    int a, b;
    cin >> a >> b;
    edges[i] = make_pair(a, b);
    }
  return 0;
}