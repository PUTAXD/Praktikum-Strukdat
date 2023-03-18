#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int x, y, n;
    cin>>x>>y>>n;

    if(x == 0){
        cout<<"Kasian Ersya";
        return 0;
    }
    queue<int> baris;

    for(int  i=0;i<x;i++){
        int k;
        cin>>k;
        baris.push(k);
    }
    if(n>=x){
        cout<<"Kasian Ersya";
        return 0;
    }

    for(int i=1;i<=n;i++){ //jam ke i
        baris.pop();
        for(int j=0; j<y;j++){
            baris.push(baris.front());
            baris.pop();
        }
    }
    cout<<baris.front()<<endl;
    // // baris.pop();
    //     while(!baris.empty()){
    //     cout << baris.front() << endl;
    //     baris.pop();
    //     }

    return 0;
}