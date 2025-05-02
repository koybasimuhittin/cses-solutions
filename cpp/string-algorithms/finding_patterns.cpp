#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f1 first
#define s2 second
#define pb push_back
#define mp make_pair
#define fri(a) freopen(a,"r",stdin);
#define fro(a) freopen(a,"w",stdout);
#define mod(x, m) (x >= m ? x - m : x)
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int q, suffix_array[N], c[N], cc[N];
string s, qs;

void counting_sort(int offset, int n, int class_count) {
    vector<int> m[class_count + 5];

    for (int i = 0; i < n; i++) {
        m[c[mod(suffix_array[i] + offset, n)]].pb(suffix_array[i]);
    }

    int cnt = 0;
    for (int i = 0; i < class_count; i++) {
        for (auto j : m[i]) {
            suffix_array[cnt++] = j;
        }
    }
}

int repair_classes(int offset, int n) {
    cc[suffix_array[0]] = 0;

    for (int i = 1; i < n; i++) {
        if (c[suffix_array[i]] != c[suffix_array[i - 1]] || c[mod(suffix_array[i] + offset, n)] != c[mod(suffix_array[i - 1] + offset, n)]) {
            cc[suffix_array[i]] = cc[suffix_array[i - 1]] + 1;
        }
        else {
            cc[suffix_array[i]] = cc[suffix_array[i - 1]];
        }
    }

    for (int i = 0; i < n; i++) {
        c[i] = cc[i];
    }

    return c[suffix_array[n - 1]] + 1;
}

void build_suffix_array(string s) {
    s = "$" + s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '$') {
            c[i] = 0;
        }
        else {
            c[i] = s[i] - 'a' + 1;
        }
        suffix_array[i] = i;
    }

    int class_count = 27;

    for (int i = 1; i < 2 * n; i *= 2) {
        counting_sort(i / 2, n, class_count);
        counting_sort(0, n, class_count);

        class_count = repair_classes(i / 2, n);
    }
}

bool find_pattern(string qs) {
    int n = s.size();
    int m = qs.size();

    int low = 1;
    int high = n;

    while (low < high) {
        int mid = (low + high) / 2;

        int flag = 0;
        for (int i = 0; i < min(n - suffix_array[mid] + 1, m); i++) {
            char c = s[mod(suffix_array[mid] + i - 1, n)];
            if (qs[i] < c) {
                flag = -1;
                break;
            }
            else if (qs[i] > c) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            if (n - suffix_array[mid] + 1 >= m) {
                flag = -1;
            }
            else {
                flag = 1;
            }
        }

        if (flag == -1) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }


    int flag = 0;
    for (int i = 0; i < min(n, m); i++) {
        char c = s[mod(suffix_array[low] + i - 1, n)];
        if (qs[i] < c) {
            flag = -1;
            break;
        }
        else if (qs[i] > c) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        if (n - suffix_array[low] + 1 >= m) {
            return true;
        }
    }
    return false;
}

int32_t main() {

    //fri("in.txt");
    //fro("out.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    build_suffix_array(s);

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> qs;
        if (find_pattern(qs)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }


    return 0;
}
