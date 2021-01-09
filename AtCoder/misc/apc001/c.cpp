#include <bits/stdc++.h>
#include <cassert>
#define rep(i, N) for (int i = 0; i < (N); ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define ok() puts(ok ? "Yes" : "No");
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using gt = greater<int>;
using minq = priority_queue<int, vector<int>, gt>;
using P = pair<ll, ll>;
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
}
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// clang++ -std=c++11 -stdlib=libc++

int main() {
  int n;
  cin >> n;
  int lo = 0;
  int hi = n - 1;
  int mid = (lo + hi) / 2;
  string fi;
  cout << lo << endl;
  cin >> fi;
  if (fi == "Vacant")
    return 0;
  rep(i, 19) {
    mid = (lo + hi) / 2;
    cout << mid << endl;
    // cout << lo << " " << mid << " " << hi << " " << endl;
    int d = mid - lo;
    string q;
    cin >> q;
    if (q == "Vacant")
      return 0;
    if (d % 2 == 0) {
      if (q == fi) {
        lo = mid + 1;
        if (q == "Male")
          fi = "Female";
        else
          fi = "Male";
      } else {
        hi = mid - 1;
      }
    } else {
      if (q == fi)
        hi = mid - 1;
      else {
        lo = mid + 1;
        if (q == "Male")
          fi = "Female";
        else
          fi = "Male";
      }
    }
  }
  return 0;
}
