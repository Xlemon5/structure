#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Work {
public:
    int time, fine, id;
    Work(int time = 0, int fine = 0, int id = 0) : time(time), fine(fine), id(id) {};
};

bool f(const Work& a, const Work& b) {
    if (a.time * b.fine == b.time * a.fine) return a.id < b.id;
    return a.time * b.fine < b.time* a.fine;
}

int main() {
    int n;
    while (cin >> n) {
        vector<Work> Jobs(n);
        for (int i = 0; i < n; ++i) {
            int t, fine;
            cin >> t >> fine;
            Jobs[i] = Work(t, fine, i + 1);
        }

        sort(Jobs.begin(), Jobs.end(), f);

        for (int i = 0; i < n; ++i) {
            cout << Jobs[i].id << " ";
        }
        cout << endl;
    }
    return 0;
}
