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

int sum(vi &nums)
{
  int s = 0;
  rep(i, nums.size()) s += nums[i];
  return s;
}

int helper(vi &nums)
{
  if (nums.size() == 1)
    return nums[0];
  return helper(vector<int>(nums.begin() + 1, nums.end())) + nums[0] + sum(nums);
}

int main()
{
  int n;
  vi a;
  cin >> n;
  rep(i, n)
  {
    int num;
    cin >> num;
    a.push_back(num);
  }
  sort(a.begin(), a.end());

  cout << helper(a) << endl;
  return 0;
}