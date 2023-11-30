#include<bits/stdc++.h>
#include<algorithm>

using namespace std;
int counts[200];

int main(){
    int x;
    cin>>x;

    while(x--){
        for(int i=0;i<=100;i++){
            counts[i]=0;
        }
        int q;
        cin>>q;

        for(int i=0;i<q;i++){
            int a;
            cin>>a;
            counts[a]++;
        }

        for(int i=0;i<=100;i++){
            if(counts[i]){
                cout<<i<<" ";
                counts[i]--;
            }else{
                cout<<i<<endl;
                break;
            }
        }

        for(int i=0;i<=100;i++){
            while(counts[i]){
                cout<<i<<" ";
                counts[i]--;
            }
        }
        cout<<endl;
    }
    return 0;
}