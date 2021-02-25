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

int n, a;
string k;
int B[100005];
int used[100005];
int main() {
  cin >> n >> a >> k;
  a--;
  rep(i, n) {
    cin >> B[i];
    B[i]--;
  }
  int freq = 1;
  int st = -1;
  int now = a;
  while (!used[B[now]]) {
    used[now] = 1;
    now = B[now];
    freq++;
  }
  st = B[now];
  now = a;
  int beforeLoop = 0;
  while (now != st) {
    beforeLoop++;
    now = B[now];
  }
  freq -= beforeLoop;
  // cout << freq << " " << st << " " << beforeLoop << endl;

  if (k.size() < 7) {
    int kk = stoi(k);
    if (kk < beforeLoop) {
      int ans = a;
      rep(i, kk) { ans = B[ans]; }
      ans++;
      cout << ans << endl;
      return 0;
    }
  }
  ll tot = 0;
  rep(i, k.size()) {
    tot *= 10;
    tot %= freq;
    int d = k[i] - '0';
    tot += d;
    tot %= freq;
  }
  tot -= beforeLoop;
  tot %= freq;
  tot += freq;
  tot %= freq;
  assert(tot >= 0);
  int move = tot - 1;
  move += freq;
  move %= freq;
  assert(move >= 0);
  int ans = B[st];
  rep(i, move) ans = B[ans];
  ans++;
  cout << ans << endl;
  return 0;
}
