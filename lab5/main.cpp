#include <iostream>
#include <iomanip>
using namespace std;


int task(vector<vector<int> > & triangle, int n, int k)
{
    return triangle[n][k];
}

void triangle_pascal(vector<vector<int> > & triangle, int row = 10)
{
    for(int i = 0; i < triangle.size(); i++){
        for(int j = 0; j < triangle.size(); j++){
            if (j <= i){
                if(i == 0 or i == j){
                    triangle[i][j] = 1;
                }
                else{
                    triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
                }
            }
        }
    }
}

void print(vector<vector<int> > & a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout << i << ": ";
        for(int j = 0; j < a.size(); j++)
        {
            cout << setw(3) << a[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {

    int row = 7;

    vector<vector<int>> triangle(row, vector<int>(row));
    triangle_pascal(triangle, row);
    print(triangle);

    cout << endl;

    int n = 0, k = 0;
    cout << "Введите число Сочетаний из N по K: " << endl;
    cin >> n >> k;

    cout << task(triangle, n, k) << endl;



    return 0;
}
