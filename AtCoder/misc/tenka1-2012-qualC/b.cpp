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
  string s;
  cin >> s;
  int n = s.size();
  vector<pair<char, int>> deck;
  string suites = "SHDC";
  int move = INF;
  rep(i, n - 1) {
    char suit = s[i];
    int num;
    if (s[i + 1] == 'K')
      num = 13;
    else if (s[i + 1] == 'Q')
      num = 12;
    else if (s[i + 1] == 'J')
      num = 11;
    else if (s[i + 1] == 'A')
      num = 1;
    else {
      if (i + 2 < n && s[i + 2] <= '9' && s[i + 2] >= '0') {
        num = stoi(s.substr(i + 1, 2));
        i++;
      } else
        num = s[i + 1] - '0';
    }
    deck.eb(suit, num);
    i++;
  }
  char finSuit;
  for (char suit : suites) {
    int now = 0;
    vector<pair<char, int>> trash;
    vi used(14);
    for (auto p : deck) {
      if (used[1] && used[10] && used[12] && used[11] && used[13])
        break;
      int num = p.se;
      if (p.fi == suit) {
        if (num == 10 || num == 1 || num == 11 || num == 12 || num == 13) {
          if (!used[num]) {
            used[num] = 1;
            continue;
          }
        }
      }
      trash.eb(p.fi, num);
      now++;
    }
    if (chmin(move, now))
      finSuit = suit;
  }

  vector<pair<char, int>> trash;
  vi used(14);
  for (auto p : deck) {
    if (used[1] && used[10] && used[12] && used[11] && used[13])
      break;
    int num = p.se;
    if (p.fi == finSuit) {
      if (num == 10 || num == 1 || num == 11 || num == 12 || num == 13) {
        if (!used[num]) {
          used[num] = 1;
          continue;
        }
      }
    }
    trash.eb(p.fi, num);
  }
  if (used[1] && used[10] && used[12] && used[11] && used[13]) {
    for (auto p : trash) {
      string num_s;
      if (p.se == 1)
        num_s = "A";
      else if (p.se == 13)
        num_s = "K";
      else if (p.se == 12)
        num_s = "Q";
      else if (p.se == 11)
        num_s = "J";
      else
        num_s = to_string(p.se);
      cout << p.fi << num_s;
    }
    if (trash.size() == 0)
      cout << 0 << endl;
    else
      cout << endl;
    return 0;
  }
  return 0;
}
