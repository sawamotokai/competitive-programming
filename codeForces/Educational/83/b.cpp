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

bool permu(vi nums, int idx)
{
  if (idx == nums.size() - 1)
  {
    rep(i, nums.size()) nums[i] -= i;
  }
  rep(i, n.size())
  {
    swap(nums.begin() + idx, nums.begin() + i);
    permu(nums, idx + 1);
    swap(nums.begin() + idx, nums.begin() + i);
  }
}

int main()
{
  int t;
  cin >> t;
  rep(_, t)
  {
    int n;
    cin >> n;
    vi A(n, 0);
    rep(i, n) cin >> A[i];
  }
  return 0;
}