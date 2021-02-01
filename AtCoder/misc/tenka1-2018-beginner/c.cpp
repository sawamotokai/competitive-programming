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
  int N;
  cin >> N;
  vi A(N);
  rep(i, N) cin >> A[i];
  minq q;
  rep(i, N) q.push(A[i]);
  ll ans = 0;
  if (N & 1) {
    ll now = 0;
    rep(i, N / 2) {
      now -= q.top() * 2;
      q.pop();
    }
    now += q.top();
    q.pop();
    now += q.top();
    q.pop();
    while (q.size()) {
      now += 2 * q.top();
      q.pop();
    }
    chmax(ans, now);
    priority_queue<int> q2;
    rep(i, N) q2.push(A[i]);
    now = 0;
    rep(i, N / 2) {
      now += q2.top() * 2;
      q2.pop();
    }
    now -= q2.top();
    q2.pop();
    now -= q2.top();
    q2.pop();
    while (q2.size()) {
      now -= 2 * q2.top();
      q2.pop();
    }
    chmax(ans, now);
  } else {
    priority_queue<int> q2;
    ll now = 0;
    rep(i, N) q2.push(A[i]);
    rep(i, N / 2 - 1) {
      now += q2.top() * 2;
      q2.pop();
    }
    now += q2.top();
    q2.pop();
    now -= q2.top();
    q2.pop();
    while (q2.size()) {
      now -= q2.top() * 2;
      q2.pop();
    }
    chmax(ans, now);
  }
  cout << ans << endl;
  return 0;
}
