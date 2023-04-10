#include <bits/stdc++.h>

using namespace std;

int main(){
    int val, sum = 0;

    priority_queue<int> a;
    priority_queue<int> b;
    
    while(scanf("%d",&val) != EOF){
        a.push(val);
    }

    if(!a.empty()){
        while(!a.empty()){
            int wadah = a.top();
            a.pop();
            if(a.empty() || a.top()!= wadah){ //kalau a kosong dan urutan paling kanan ga sama dsebelahnya (intinya seharusnya ga ada bialngan yang sama)
                sum = sum + wadah;
                b.push(sum);
            }
        }
        while(!b.empty()){
            cout << b.top() << ' ';
            b.pop();
        }   
    }
    return 0;
}