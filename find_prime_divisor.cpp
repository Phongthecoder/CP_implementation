#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
        cin >> n;
        map <int,int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for (int j = 2; j * j <= x; j++) {
                while (x % j == 0) {
                    x /= j;
                    a[j]++;
                }
            }
            if (x != 1) {
                a[x]++;
            }
        }

        for(pair<int,int> p : a){
            cout << p.first << " " << p.second << endl;
        }






    return 0;
}