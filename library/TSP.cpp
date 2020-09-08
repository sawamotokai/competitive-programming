int V,E;
int dist[20][20];
int dp[1<<20][20];


int main() {
  cin >> V >> E;
  rep(i,20) rep(j,20) dist[i][j] = INF;
  rep(i,E) {
    int a,b,c; cin >> a >> b >> c;
    dist[a][b] =c;
  }
  rep(i,1<<20) rep(j,20) dp[i][j] = INF;
  dp[0][0] = 0;
  rep(bits, 1 << V) {
      rep(v, V) {
        if ((bits & (1 << v))) continue; // if from node is already visited
        rep(u, V) {
          chmin(dp[bits | (1 << v)][v], dp[bits][u] + dist[u][v]);
        }
      }
  }
  ll ans = dp[(1<<V)-1][0];
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}