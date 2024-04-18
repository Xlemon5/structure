#include <iostream>
#include <vector>

using namespace std;

int countWays(int n) {
  if (n == 1) return 1;  // Если только одна кувшинка, способ один.
  vector<int> dp(n+1);
  dp[1] = 1;  // Один способ добраться до первой кувшинки.
  dp[2] = 2;  // Два способа добраться до второй кувшинки: прямо или через одну.

  for (int i = 3; i <= n; i++) {
	  dp[i] = dp[i-1] + dp[i-2];
	}

  return dp[n];
}

int main() {
  int n;
  cout << "Введите количество кувшинок: ";
  cin >> n;
  cout << "Количество способов добраться до последней кувшинки: " << countWays(n) << endl;
  return 0;
}
