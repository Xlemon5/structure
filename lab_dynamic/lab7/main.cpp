#include <iostream>
#include <vector>
#include <string>

using namespace std;

// dp[len][last_digit][count], где last_digit = 0 для 5 и last_digit = 1 для 9
vector<vector<vector<long long>>> dp;

void calculate_dp(int n) {
  dp.resize(n + 1, vector<vector<long long>>(2, vector<long long>(3, 0)));
  dp[1][0][1] = 1; // 5
  dp[1][1][1] = 1; // 9

  for (int len = 1; len < n; ++len) {
	  for (int last_digit = 0; last_digit <= 1; ++last_digit) {
		  for (int count = 1; count <= 2; ++count) {
			  int other_digit = 1 - last_digit;
			  if (count < 2) {
				  dp[len+1][last_digit][count+1] += dp[len][last_digit][count];
				}
			  dp[len+1][other_digit][1] += dp[len][last_digit][count];
			}
		}
	}
}

long long count_numbers(int n) {
  long long result = 0;
  for (int last_digit = 0; last_digit <= 1; ++last_digit) {
	  for (int count = 1; count <= 2; ++count) {
		  result += dp[n][last_digit][count];
		}
	}
  return result;
}

void generate_numbers(string current, int len, int last_digit, int count, int n) {
  if (len == n) {
	  cout << current << endl;
	  return;
	}

  if (count < 2 && dp[len+1][last_digit][count+1] > 0) {
	  generate_numbers(current + (last_digit == 0 ? '5' : '9'), len + 1, last_digit, count + 1, n);
	}

  int other_digit = 1 - last_digit;
  if (dp[len+1][other_digit][1] > 0) {
	  generate_numbers(current + (other_digit == 0 ? '5' : '9'), len + 1, other_digit, 1, n);
	}
}

int main() {
  int n;
  cin >> n;

  if (n <= 0) {
	  return 0;
	}

  calculate_dp(n);
  long long total_numbers = count_numbers(n);
  cout << "Total numbers: " << total_numbers << endl;

  if (dp[1][0][1] > 0) generate_numbers("5", 1, 0, 1, n);
  if (dp[1][1][1] > 0) generate_numbers("9", 1, 1, 1, n);

  return 0;
}
