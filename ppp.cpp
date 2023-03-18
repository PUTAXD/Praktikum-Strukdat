#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,m,val,min = 1000000001;
	cin>>n>>m;
	int kanan=m;

	list<int> baris;
	for(int i =0;i<n;i++){
		cin>>val;
		baris.push_back(val);
	}

	list<int>::iterator p = baris.begin();
	list<int>::iterator save;

	for(int i=0;i<m;i++){
		if(min>*p){
			min = *p;
			save = p;
		}
		p++;
	}

	cout<<min<<endl;
	while(kanan<n){
		kanan++;
		if(save==baris.begin()){
			p = ++save ;
			min = *p;
			for(int i =1;i<m;i++){
				p++;
				if(min>*p){
					min = *p;
					save = p;
				}
			}
			p++;
		}
		else if(*p<min){
			min = *p;
			save = p;
			p++;
		}
		else{
			p++;
		}
	baris.pop_front();
	cout<<min<<endl;
	}
	
	return 0;
}
