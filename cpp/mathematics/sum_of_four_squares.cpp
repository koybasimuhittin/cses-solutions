#include <bits/stdc++.h>
using namespace std;

struct Pair {
    short a, b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    vector<int> qs(t);
    int maxN = 0;
    for (int i = 0; i < t; ++i) {
        cin >> qs[i];
        maxN = max(maxN, qs[i]);
    }

    int M = (int)sqrt(maxN);
    vector<Pair> rep(maxN + 1, Pair{ -1, -1 });

    // Precompute sums of two squares.
    for (int a = 0; a <= M; ++a) {
        int a2 = a * 1LL * a;
        for (int b = a; b <= M; ++b) {
            int s = a2 + b * 1LL * b;
            if (s > maxN) break;
            if (rep[s].a == -1) {   // store first found representation
                rep[s].a = (short)a;
                rep[s].b = (short)b;
            }
        }
    }

    // Answer queries.
    for (int n : qs) {
        for (int s = 0; s <= n; ++s) {
            if (rep[s].a != -1 && rep[n - s].a != -1) {
                auto p1 = rep[s];
                auto p2 = rep[n - s];
                cout << p1.a << " " << p1.b << " "
                    << p2.a << " " << p2.b << "\n";
                break;
            }
        }
    }

    return 0;
}
