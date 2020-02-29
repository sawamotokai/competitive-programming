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

bool compX(ii p1, ii p2)
{
  return p1.first < p2.first;
}
bool compY(ii p1, ii p2)
{
  return p1.second > p2.second;
}

int main()
{
  int n;
  cin >> n;
  vii R(110);
  vii B(110);
  rep(i, n)
  {
    int a, b;
    cin >> a >> b;
    R[i] = make_pair(a, b);
  }
  rep(i, n)
  {
    int c, d;
    cin >> c >> d;
    B[i] = make_pair(c, d);
  }

  int ans = 0;
  // sort(B.begin(), B.end(), compX);
  sort(R.begin(), R.end(), compX);
  rep(i, n)
  {
    std::cout << R[i].first << " " << R[i].second << std::endl;
    std::cout << B[i].first << " " << B[i].second << std::endl;
  }
  vector<vb> isUsed(210, vb(210, false));

  rep(i, n)
  {
    rep(j, n)
    {
      // cout << B[i].first << " <= " << R[j].first << endl;
      if (B[i].first <= R[j].first)
      {
        // std::cout << j << std::endl;
        sort(R.begin(), R.begin() + j, compY);
        rep(k, j)
        {
          std::cout << "fafs" << std::endl;
          if (!isUsed[R[k].first][R[k].second])
          {
            ans++;
            isUsed[R[k].first][R[k].second] = true;
            break;
          }
        }
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}