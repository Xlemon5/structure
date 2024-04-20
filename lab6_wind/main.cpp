#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void printPascalTriangle(int numRows, int n, int k) {
    vector<vector<int>> triangle(numRows, vector<int>(numRows, 0));

    for (int i = 0; i < numRows; i++) {
        triangle[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            cout << setw(3) << triangle[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "Число сочетаний: " << triangle[n][k] << endl;

}

int main() {
    setlocale(LC_ALL, "ru");
    int numRows;
    int n;
    int k;


    cout << "Введите количество строк треугольника Паскаля: ";
    cin >> numRows;

    cout << "Число сочетаний: " << endl;
    cin >> n >> k;

    cout << "Треугольник Паскаля:" << endl;
    printPascalTriangle(numRows, n, k);

    return 0;
}
