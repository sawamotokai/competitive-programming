#include <bits/stdc++.h>
#include <cassert>
#define rep(i, N) for (int i = 0; i < (N); ++i)
#define rep2(i, a, b) for (ll i = a; i <= b; ++i)
#define rep3(i, a, b) for (ll i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define nl '\n'
#define endl '\n'
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
using vvll = vector<vll>;
using ii = pair<int, int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vs = vector<string>;
using P = pair<ll, ll>;
using gt = greater<P>;
using minq = priority_queue<P, vector<P>, gt>;
using vP = vector<P>;
template <class T> void takeUnique(vector<T> &v) {
  auto last = std::unique(v.begin(), v.end());
  v.erase(last, v.end());
}
template <class T> void print(const initializer_list<T> &il) {
  for (auto x : il) {
    cout << x << " ";
  }
  cout << "\n";
}
inline void priv(vi a) {
  rep(i, (int)a.size())
      printf("%d%c", a[i], i == (int)a.size() - 1 ? '\n' : ' ');
}
const ll LINF = 1e18L + 1;
const int INF = 1e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// clang++ -std=c++11 -stdlib=libc++

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  vi cnt1(26);
  vi cnt2(26);
  vi cnt3(26);
  int n = s1.size();
  rep(i, n) {
    cnt1[s1[i] - 'A']++;
    cnt2[s2[i] - 'A']++;
    cnt3[s3[i] - 'A']++;
  }
  int sum = 0;
  rep(i, 26) {
    char c = 'A' + i;
    int need = max<int>(0, cnt3[i] - cnt1[i]);
    if (need > cnt2[i]) {
      puts("NO");
      return 0;
    }
    sum += need;
  }
  if (sum > n / 2) {
    puts("NO");
    return 0;
  }
  sum = 0;
  rep(i, 26) {
    char c = 'A' + i;
    int need = max<int>(0, cnt3[i] - cnt2[i]);
    if (need > cnt1[i]) {
      puts("NO");
      return 0;
    }
    sum += need;
  }
  if (sum > n / 2) {
    puts("NO");
    return 0;
  }
  puts("YES");
  return 0;
}
