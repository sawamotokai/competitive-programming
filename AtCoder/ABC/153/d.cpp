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
typedef greater<int> gt;
typedef priority_queue<int, vector<int>, gt> minq;
typedef long long ll;
const ll INF = 1e18L + 1;


ll attack(ll r) {
  if (r == 1) {
    return 1;
  }
  ll half = floor(r/2);
  return 1 + 2*attack(half);
}

int main() {
  ll H; cin >> H;
  cout << attack(H) << endl;
  return 0;
}