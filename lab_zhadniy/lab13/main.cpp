//https://site.ada.edu.az/~medv/acm/Docs%20e-olimp/Volume%2016/1598.htm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gather(int neededFood, int n, int price)
{
    int EWorkers, workers, food, days, best = 2000000000;
    if (n >= neededFood) 
    { 
        return 1; 
    }

    for (EWorkers = n; EWorkers <= neededFood; EWorkers++)
    {
        food = days = 0; 
        workers = n;
        while (food < neededFood)
        {
            food += workers;
            while ((workers < EWorkers) && (food >= price))
            {
                workers++; 
                food -= price;
            }
            days++;
        }
        if (days < best) 
        { 
            best = days; 
        }
    }
    return best;
}

int main()
{
    int neededFood, n, price;
    while (cin >> neededFood >> n >> price)
    {
        int res = gather(neededFood, n, price);
        cout << res << endl;
    }
    return 0;
}
