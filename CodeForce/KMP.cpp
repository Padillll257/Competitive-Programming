#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++) cin >> a[i];

        vector<int> pi(m, 0);
        for (int i = 1; i < m; i++) {
            int j = pi[i-1];
            while (j > 0 && a[i] != a[j]) j = pi[j-1];
            if (a[i] == a[j]) j++;
            pi[i] = j;
        }

        long long count = 0;
        int j = 0; 

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= i; k++) {
                while (j > 0 && k != a[j]) j = pi[j-1];
                if (k == a[j]) j++;
                if (j == m) {
                    count++;
                    j = pi[j-1];
                }
            }
        }

        cout << count << "\n";
    }
}
