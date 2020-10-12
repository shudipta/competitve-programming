// Danger of Mad Snakes: http://codeforces.com/problemset/problem/1425/D
// Problem Tags: combinatorics    dp    math    *2300

// We are going to count the contribution of two snakes (𝐼,𝐽) separately. Assume that the current snake we are interested in has danger value 𝐵1 and 𝐵2. The terms where they are killed must be on the form (...+𝐵1+𝐵2+...)2. Expanding this gives 𝐵21+𝐵22+2𝐵1𝐵2. So, the contribution of 𝐵1𝐵2 to the answer is the number of attack strategies where both 𝐼 and 𝐽 are killed. We can find this using the inclusion-exclusion principle. First, let's define:

// 𝑊: the number of squares where when hit will result in 𝐼 and 𝐽 being killed.
// 𝑈: the number of squares where when hit will result in 𝐼 killed, but not 𝐽.
// 𝑉: the number of squared where when hit will result in 𝐽 killed, but not 𝐼.
// We can calculate all these values easily using prefix sum DP. Then, there are two cases to consider:

// Case 1: a square in 𝑊 is hit. The number of ways is 𝐶(𝑁,𝑀)−𝐶(𝑁−𝑊,𝑀)
// Case 2: a square in 𝑊 is not hit. However, a square in 𝑈 and 𝑉 is hit. Lets define 𝑁′=𝑁−𝑊. The number of ways is 𝐶(𝑁′,𝑀)−𝐶(𝑁′−𝑈,𝑀)−𝐶(𝑁′−𝑉,𝑀)+𝐶(𝑁′−𝑈−𝑉,𝑀)
// Sum the number of ways times 2𝐵1𝐵2 to the answer. Don't also forget to count the contribution of 𝐵21.

// Time Complexity: 𝑂(𝑁2)

// code: http://codeforces.com/contest/1425/submission/94149327

#include<iostream>
#include<vector>
using namespace std;

typedef long long int ll;

const int MAX_N = 2005;
const int GRID_SZ = 1001;
const ll MOD = 1e9 + 7;

ll bigMod(ll a, ll b, ll mod) {
    if (b == 0ll)
        return 1ll;

    ll res = bigMod(a, b/2, mod);
    res = (res * res) % mod;

    if (b & 1ll)
        res = (a * res) % mod;
    
    return res;
}

ll fact[MAX_N], invFact[MAX_N];
void precalc() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = (invFact[i - 1] * bigMod(i, MOD - 2, MOD)) % MOD;
    }

    return;
}

ll nCr(ll n, ll r) {
    if (r > n)
        return 0; 
    return (fact[n] * ((invFact[r] * invFact[n - r]) % MOD)) % MOD;
}

void snakeSum(vector<vector<int>> &snakes) {
    for (int i = 1; i < GRID_SZ; i++) {
        for (int j = 1; j < GRID_SZ; j++) {
            snakes[i][j] += snakes[i - 1][j] + snakes[i][j - 1] - snakes[i - 1][j - 1];
        }
    }
}

int subSum(vector<vector<int>>& snakes, int x1, int y1, int x2, int y2) {
    x1 = max(1, x1); y1 = max(1, y1);
    x2 = min(1000, x2); y2 = min(1000, y2);
    if (x1 > x2 || y1 > y2)
         return 0;
    return snakes[x2][y2] - snakes[x2][y1 - 1] - snakes[x1 - 1][y2] + snakes[x1 - 1][y1 - 1];
}

int getW(vector<vector<int>>& snakes, int& r, int x1, int y1, int x2, int y2) {
    int tmpx = x1, tmpy = y1;
    x1 = min(tmpx, x2) + r, y1 = min(tmpy, y2) + r;
    x2 = max(tmpx, x2) - r, y2 = max(tmpy, y2) - r;

    return subSum(snakes, x2, y2, x1, y1);
}

int main() {
    precalc();

    int n, m, r;
    cin >> n >> m >> r;
    vector<int> x(n), y(n), danger(n);
    vector<vector<int>> snakes(GRID_SZ);
    for (int i = 0; i < GRID_SZ; i++)
        snakes[i].resize(GRID_SZ);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> danger[i];
        snakes[ x[i] ][ y[i] ] = 1;
    }
    
    snakeSum(snakes);

    ll res = 0ll;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int w = getW(snakes, r, x[i], y[i], x[j], y[j]);
            ll cnt = nCr(n, m) - nCr(n - w, m);
            if (cnt < 0ll)
                cnt += MOD;

            int u = subSum(snakes, x[i] - r, y[i] - r, x[i] + r, y[i] + r) - w;
            int v = subSum(snakes, x[j] - r, y[j] - r, x[j] + r, y[j] + r) - w;
            cnt += nCr(n - w, m) - nCr(n - w - u, m) - nCr(n - w - v, m) + nCr(n - w - u - v, m);
            cnt %= MOD;
            if (cnt < 0ll)
                cnt += MOD;
            if (i == j)
                res += (cnt * ((1ll * danger[i] * danger[j]) % MOD)) % MOD;
            else
                res += (((2ll * cnt) % MOD) * ((1ll * danger[i] * danger[j]) % MOD)) % MOD;
            res %= MOD;
        }
    }

    cout << res << endl;

    return 0;
}
