#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        if (n * n - k == 1) {
            cout << "NO\n";
            continue;
        }
        else if(n * n == k){
            cout << "YES" << "\n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    cout << "U";
                }
                cout << "\n";
            }
            continue;
        }

        vector<vector<char>> grid(n, vector<char>(n, 'U'));

        ll batas = k;
        ll row = 0, col = 0;
        bool found = false;

        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n; j++) {
                if (batas == 0) {
                    row = i;
                    col = j;
                    found = true;
                    break;
                }
                batas--;
            }
        }

        for (int i = row; i < n; i++) {

            if (i == row) {
                if (i == n - 1) {
                    ll sisa = n - col;  
                    bool genap = (sisa % 2 == 0);

                    for (int j = 0; j < n; j++) {
                        if (j < col) {
                            grid[i][j] = 'U';
                        } else {
                            int idx = j - col;
                            if (genap) {
                                grid[i][j] = (idx % 2 == 0 ? 'R' : 'L');
                            } else {
                                if (idx == sisa - 1)
                                    grid[i][j] = 'L';
                                else
                                    grid[i][j] = (idx % 2 == 0 ? 'R' : 'L');
                            }
                        }
                    }
                } else {
                    for (int j = 0; j < n; j++) {
                        if (j < col)
                            grid[i][j] = 'U';
                        else
                            grid[i][j] = 'D';
                    }
                }
            }

            else if (i == n - 1) {
                for (int j = 0; j < n; j++) {
                    if (n % 2 == 0)
                        grid[i][j] = (j % 2 == 0 ? 'R' : 'L');
                    else {
                        if (j == n - 1)
                            grid[i][j] = 'L';
                        else
                            grid[i][j] = (j % 2 == 0 ? 'R' : 'L');
                    }
                }
            }

            else {
                for (int j = 0; j < n; j++)
                    grid[i][j] = 'D';
            }
        }

        cout << "YES\n";
        for (auto &r : grid) {
            for (auto &c : r) cout << c;
            cout << "\n";
        }
    }
}
