#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

struct node{
    int id;
    int r;
    int c;
    bool operator<(const node& rhs)const
    {
        if(r == rhs.r){
            return c<=rhs.c;
        }
        return r < rhs.r;
    }
};

// struct comp{
//         bool operator()(struct node a, struct node b){
//          if(a.r==b.r){
//             return a.c < b.c;
//          }
//          return a.id<b.id;
//         }
//     };

int main(){
    int n,id,r,c;
    char command[10];
    
    node bus;
    cin>>n;
    int flag=0,flag2=0,total=0;

    priority_queue<node> pq;
    // node bus={1, 69, 200};
    // pq.push(bus);

    // bus={2, 70, 100};
    // pq.push(bus);
    // cout<<pq.empty()<<endl;
    
    for(int i=0;i<n;i++){
        cin>>command;
        if(!strcmp(command,"REGIS")){
            cin>>id>>r>>c;
            bus={id, r, c};
            pq.push(bus);
            // total++;
        }else if(!strcmp(command,"SEWA")){
            int sewa,sum=0;
            cin>>sewa;
            
            if(!pq.empty()){
                priority_queue<node> temp = pq;
                while(!temp.empty()){
                    sum = sum + temp.top().c;
                    if(sewa>sum){
                        // cout<<temp.top().id<<" ";
                        temp.pop();
                        flag2++;
                        // cout<<"flag : "<<flag<<endl;
                    }else{

                        temp.pop();
                        flag++;
                        flag2++;
                        
                        break;
                    }
                }
                // cout<<"flag2a : "<<flag2<<endl;
                if(flag!=0){
                    for(int i=0;i<flag2;i++){
                        cout<<pq.top().id<<" ";
                        pq.pop();
                    }
                    cout<<"telah berhasil disewa"<<endl;
                }else{
                    cout<<"Maaf tidak ada bus yang dapat memenuhi keinginan anda"<<endl;
                }

                // total = total-flag2;
                flag = 0;
                flag2 = 0;
                
            }else{
                cout<<"Maaf tidak ada bus yang dapat memenuhi keinginan anda"<<endl;
            }
        }
    }
    if(pq.empty()){
        cout<<"Tidak ada bus yang tersisa"<<endl;
    }else{
        priority_queue<node> temp = pq;
        while(!temp.empty()){
            total++;
            temp.pop();
        }
        cout<<"Ada "<<total<<" bus yang tersisa yaitu ";
        while(!pq.empty()){
        cout<<pq.top().id<<" ";
        pq.pop();
        }

    }
        // while(!pq.empty()){
        // cout<<pq.top().id<<" "<<pq.top().r<<" "<<pq.top().c<< endl;
        // pq.pop();
        // }

    return 0;
}
