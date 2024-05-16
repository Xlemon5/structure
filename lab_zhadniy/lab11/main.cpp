#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    int mm = min(min(a.first, a.second), min(b.first, b.second));
    if ((mm == a.first) || (mm == b.second)) return false;
    return true;
}

void customSort(vector<pair<int, int>>& v)
{
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (cmp(v[i], v[j])) {
                swap(v[i], v[j]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int up[310];

    for (int i = 0; i < n; i++) {
        cin >> up[i];
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        v.push_back(make_pair(up[i], b));
    }

    customSort(v);

    int sum = 0, a = 0;
    for (int i = 0; i < v.size(); i++) {
        a += v[i].first;
        sum = max(a, sum) + v[i].second;
    }

    cout << sum << endl;
    return 0;
}
