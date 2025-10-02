#include <bits/stdc++.h>
using namespace std;


int main(){

    int N;

    int plane[N+1];

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> plane[i];
    }

    bool love = false;

    for(int i = 1; i <= N; i++){
        int x = plane[i];
        int y = plane[x];
        int z = plane[y];
        if(plane[z] == x){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
