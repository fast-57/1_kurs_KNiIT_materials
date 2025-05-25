# include <iostream>
# include <vector>
using namespace std;
void sort(vector<int> &x) {
    int n = x.size();
    int prob = n/1.247;
    while (prob >= 1) {
        if (prob < 1) prob = 1;
        for(int i = 0; i < n - prob; i++) {
            if (x[i] > x[i + prob])
                swap(x[i], x[i + prob]);
        }
        prob /= 1.247;
    }
}