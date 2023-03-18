#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int ConvertToInt(char x){
    if(x == '6')return 1;
    if(x == '7')return 2;
    if(x == '8')return 3;
    if(x == '9')return 4;

    if(x == 'T')return 5;
    if(x == 'J')return 6;
    if(x == 'Q')return 7;
    if(x == 'K')return 8;
    if(x == 'A')return 9;
}
int ConvertToChar(int x){
    if(x == 1)return '6';
    if(x == 2)return '7';
    if(x == 3)return '8';
    if(x == 4)return '9';

    if(x == 5)return 'T';
    if(x == 6)return 'J';
    if(x == 7)return 'Q';
    if(x == 8)return 'K';
    if(x == 9)return 'A';
}

struct node{
    int nilai;
    char jenis;
    bool operator<(const node& rhs)const
    {
            return nilai>rhs.nilai;
    }
};

struct node2{
    char nilai;
    char jenis;
};

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){//jumlah testcase
        // priority_queue<node> pq_n;
        // priority_queue<node> pq_m;

        queue<node2> pq_n;
        queue<node2> pq_m;

        priority_queue<node> temp_pq_n;
        priority_queue<node> temp_pq_m;
        
        // priority_queue<node> last;//inget hapus

        int kartu_n,kartu_m;
        char truf;

        cin>> kartu_n>>kartu_m>>truf;

        //masukan kartu si N
        for(int j=0;j<kartu_n;j++){
            
            char temp[2];
            cin>>temp;
            node temp_si_n ={ConvertToInt(temp[0]),temp[1]};
            temp_pq_n.push(temp_si_n);
        }
        // while(!temp_pq.empty()){
        //         char sementara = ConvertToChar(temp_pq.top().nilai);
        //         node2 nilai_pq_n = {sementara,temp_pq.top().jenis};
        //         pq_n.push(nilai_pq_n);
        //         temp_pq.pop();
        //     }

        //masukan kartu si M
        for(int k=0;k<kartu_m;k++){
            char temp[2];
            cin>>temp;
            node temp_si_m ={ConvertToInt(temp[0]),temp[1]};
            temp_pq_m.push(temp_si_m);
        }
        // while(!temp_pq.empty()){
        //         char sementara = ConvertToChar(temp_pq.top().nilai);
        //         node2 nilai_pq_m = {sementara,temp_pq.top().jenis};
        //         pq_m.push(nilai_pq_m);
        //         temp_pq.pop();
        //     }
        
        priority_queue<node> temp1 = temp_pq_n;
        priority_queue<node> temp2 = temp_pq_m;

        while(!temp2.empty()){
            temp1 = temp_pq_n;
            while(!temp1.empty()){
                if(temp1.top().nilai >= temp2.top().nilai && temp1.top().jenis == temp2.top().jenis){
                    temp2.pop();
                    break;
                }
                temp1.top();
            }        
        }
        // last = temp_pq;//inget hapus
        // while(!last.empty()){//print
        //     cout<<last.top().nilai<<last.top().jenis<<" ";
        //     last.pop();
        //     cout<<"masuk";
        //     }

        cout<<endl;
        while(!pq_n.empty()){
        cout<<pq_n.front().nilai<<pq_n.front().jenis<<" ";
        pq_n.pop();
        }

        cout<<endl;
        while(!pq_m.empty()){
        cout<<pq_m.front().nilai<<pq_m.front().jenis<<" ";
        pq_m.pop();
        }

    return 0;
    }
   

}