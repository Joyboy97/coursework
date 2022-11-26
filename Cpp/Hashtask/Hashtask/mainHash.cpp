#include <iostream>
#include "makeSeuss.hpp"
#include <time.h>
#include <stdlib.h>

using namespace std;
int main() {
	srand(time(NULL));
	makeSeuss voice1("DrSeuss.txt","Seussout1.txt",true,true);
	cout<<endl<<"Total collisions hfn2 "<<endl;
	makeSeuss voice2("DrSeuss.txt","Seussout2.txt",false,true);
	cout<<endl<<"Total collisions hfn2 "<<endl;
	makeSeuss voice3("DrSeuss.txt","Seussout3.txt",true,false);
	makeSeuss voice4("DrSeuss.txt","Seussout4.txt",false,false);
//	//OR
//	makeSeuss voice5("GEChap1a.txt","GEout1.txt",true,true);
//	makeSeuss voice6("GEChap1a.txt","GEout2.txt",false,true);
//	makeSeuss voice7("GEChap1a.txt","GEout3.txt",true,false);
//	makeSeuss voice8("GEChap1a.txt","GEout4.txt",false,false);


//	string k="yes";
//	int i=0,n,a[3],c=0;
//			unsigned int l=0;
//			if(k.size()>2){
//				for(l=0;l<(k.size()/3)*3;l++){
//					cout<<"i="<<i<<endl;
//					n=(int)k[l];
//					c=0;
//					cout<<n<<" [";
//					for(int d=0;d<3;d++){
//						c+=n%10;
//						n/=10;
//						cout<<c<<" ";
//					}
//					cout<<"] "<<l%3<<" "<<l<<endl;
//					a[l%3]=c;
//					if(l%3==2)
//						i+=a[0]*(a[1]+1)+((int)a[1]/a[2]*10);
//					cout<<"i="<<i<<endl;
//					}
//
//				//cout<<"Ya "<<k.size()%l<<endl;
//			}
//			cout<<l<<endl;
//			l=k.size()-l;
//			cout<<l<<" "<<k.size()<<endl;
//			if(l==2){
//				cout<<k[k.size()-l+1]<<"="<<(int)k[k.size()-l+1]<<" "<<k[k.size()-l]<<"="<<(int)k[k.size()-l+1]<<endl;
//				i+=k[k.size()-l+1]*(k[k.size()-l]+1)+(k[k.size()-l]/k[k.size()-l+1]*10);
//				//i+=(int)k[c]%200;
//			}else if(l==1){
//				cout<<k[k.size()-l]<<"="<<(int)k[k.size()-l]<<endl;
//				i+=(int)k[k.size()-l];
//				cout<<"i="<<i<<endl;
//			}
//		i%=100;
//		cout<<"hashcode "<<i<<endl;
//		int c=2,mapSize=2180;
//		bool p=false;
//		while(!p){
//			for(c=2;c<mapSize;c++){
//				if(mapSize%c==0){
//					break;
//				}
//			}
//			if(c==mapSize)
//				p=true;
//			else
//				mapSize++;
//		}
//		cout<<mapSize<<" is nearest prime to 2180"<<endl;
	return 0;
}
