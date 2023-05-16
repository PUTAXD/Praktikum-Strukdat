#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==1){
        string k;
        cin>>k;
        // cout<<k;
        return 0;
    }

    set<string> data;
    for(int i=0;i<n;i++){
        string input;
        cin>>input;
        
        auto long_set = data.size();
        data.insert(input);

        //mengecek ada data yang sama ga?
        if(long_set == data.size()){
            string temp1 = input;
            string sum;
            
            int dijumlah=0;
            reverse(temp1.begin(),temp1.end());

            while(!temp1.empty()){
                int yes = temp1.back()-'0';
                int belum = input.back()-'0';
                
                dijumlah += yes+belum;
                sum.push_back((dijumlah%10)+'0');
                dijumlah/=10;

                temp1.pop_back();
                input.pop_back();
            }
            reverse(sum.begin(),sum.end());
            cout<<sum<<endl;
            return 0;
        }
    }
    // string test;
    // test="12309";
    // reverse(test.begin(),test.end());
    // cout<<test;

    // for(auto i = data.begin(); i != data.end(); i++){
    //     cout << *i << endl;
    // }

    return 0;
}