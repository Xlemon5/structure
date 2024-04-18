#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, const vector<int>& weights, const vector<int>& values, int N) {
  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

  for (int i = 1; i <= N; i++) {
	  for (int j = 0; j <= W; j++) {
		  if (weights[i-1] <= j) {
			  dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i-1]] + values[i-1]);
			} else {
			  dp[i][j] = dp[i-1][j];
			}
		}
	}

  return dp[N][W];
}

int main() {
  int N, W;
  cout << "Введите количество предметов и вместимость рюкзака: ";
  cin >> N >> W;
  vector<int> weights(N), values(N);

  cout << "Введите веса и стоимости предметов:\n";
  for (int i = 0; i < N; i++) {
	  cout << "Предмет " << i + 1 << ": ";
	  cin >> weights[i] >> values[i];
	}

  cout << "Максимальная стоимость, которую можно упаковать: " << knapsack(W, weights, values, N) << endl;

  return 0;
}
