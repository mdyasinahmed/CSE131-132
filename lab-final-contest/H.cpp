#include <bits/stdc++.h>
using namespace std;

#define N 510
#define inf 1000000
char s[N][N];


int main() {
    int i, j, k;
    int n, m, d;

    cin >> n>> m;

    for(i=1; i<N; i++) {
        for(j=1; j<N; j++)
            s[i][j]='.';
    }

    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++)
            cin>>s[i][j];
    }

    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            if(s[i][j]=='S' && (s[i][j+1]=='W' || s[i][j-1]=='W' || s[i+1][j]=='W' || s[i-1][j]=='W')) {
                //cout<<i<<" "<<j;cout << "\n" ;
                printf("No\n");
                return 0;
            }

            if(s[i][j]=='S') {
                if(s[i][j-1]=='.')
                    s[i][j-1]='D';
                if(s[i][j+1]=='.')
                    s[i][j+1]='D';
                if(s[i-1][j]=='.')
                    s[i-1][j]='D';
                if(s[i+1][j]=='.')
                    s[i+1][j]='D';
            }
        }
    }

    cout<<"Yes\n";

    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            cout<<s[i][j];
        }  
        cout << "\n" ;
    }

    return 0;
}