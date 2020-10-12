#include <algorithm>
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
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
// clang++ -std=c++11 -stdlib=libc++
int countDistinct(vi arr, int n) {
  int res = 1;
  // Pick all elements one by one
  for (int i = 1; i < n; i++) {
    int j = 0;
    for (j = 0; j < i; j++)
      if (arr[i] == arr[j])
        break;

    // If not printed earlier, then print it
    if (i == j)
      res++;
  }
  return res;
}

int N;
int main() {
  cin >> N;
  vi A(N);
  rep(i, N) cin >> A[i];
  auto findMin = [&] {
    int ret = INF;
    rep(i, N) chmin(ret, A[i]);
    return ret;
  };
  while (1) {
    if (countDistinct(A, N) == 1)
      break;
    int mn = findMin();
    rep(i, N) {
      A[i] %= mn;
      if (A[i] == 0)
        A[i] = mn;
    }
  }
  cout << A[0] << endl;
  return 0;
}
