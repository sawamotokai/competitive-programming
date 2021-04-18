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
#define pcnt(x) __builtin_popcountll(x)
#define df(x) ll x = in();
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
inline ll in() {
  ll x;
  scanf("%lld", &x);
  return x;
}
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
const ll LINF = 8e18L + 1;
const int INF = 8e9 + 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dxx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dyy[] = {1, 1, 0, -1, -1, -1, 0, 1};
// g++ -std=c++17 -stdlib=libc++
#define _GLIBCXX_DEBUG
// This slows down the execution; even the time complexity, since it checks if
// std funcs such as lower_bound meets prereqs
int used[10];
int num[10];
int ch[26];

string S[3];
set<char> st;
int n;
ll ans1 = -1;
ll ans2 = -1;
ll ans3 = -1;

void dfs(int p = 0) {
  if (p == n) {
    vll N(3);
    vi ctoi(26);
    int i = 0;
    for (char c : st) {
      ctoi[c - 'a'] = i;
      i++;
    }
    rep(i, 3) {
      rep(j, S[i].size()) {
        N[i] *= 10;
        int d = num[ctoi[S[i][j] - 'a']];
        if (j == 0 and d == 0)
          return;
        N[i] += d;
      }
    }
    if (N[0] + N[1] == N[2]) {
      ans1 = N[0];
      ans2 = N[1];
      ans3 = N[2];
    }
    return;
  }
  rep(i, 10) {
    if (used[i])
      continue;
    used[i] = true;
    num[p] = i;
    dfs(p + 1);
    used[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(16);
  rep(i, 3) cin >> S[i];
  rep(i, 3) { rep(j, S[i].size()) st.insert(S[i][j]); }
  memset(ch, -1, sizeof(ch));
  n = st.size();
  if (n > 10) {
    cout << "UNSOLVABLE" << nl;
    return 0;
  }
  dfs();
  if (ans1 == -1) {
    cout << "UNSOLVABLE" << nl;
  } else {
    cout << ans1 << nl;
    cout << ans2 << nl;
    cout << ans3 << nl;
  }
  return 0;
}
