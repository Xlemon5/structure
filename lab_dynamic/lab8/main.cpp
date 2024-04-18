#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 12345;
vector<vector<int>> dp;

void calculate_dp(int n) {
    dp.resize(n + 1, vector<int>(3, 0));
    dp[0][0] = 1; // Пустая последовательность

    for (int i = 1; i <= n; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
        dp[i][1] = dp[i-1][0] % MOD;
        dp[i][2] = dp[i-1][1] % MOD;
    }
}

void generate_sequences(string current, int len, int last, int n) {
    if (len == n) {
        cout << current << endl;
        return;
    }

    if (dp[len+1][0] > 0) {
        generate_sequences(current + "0", len + 1, 0, n);
    }
    if (last < 2 && dp[len+1][last+1] > 0) {
        generate_sequences(current + "1", len + 1, last + 1, n);
    }
}

int main() {
    int n;
    cin >> n;

    calculate_dp(n);
    cout << "Total sequences: " << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD << endl;

    if (dp[1][0] > 0) generate_sequences("0", 1, 0, n);
    if (dp[1][1] > 0) generate_sequences("1", 1, 1, n);

    return 0;
}
