/*
 * decolab.cpp
 *
 *  Created on: Feb 8, 2022
 *      Author: winne
 */

/* Code */
/*Copy these libraries into the top of your .cpp file*/
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
/********************************************************
Function Declarations (4 pts)
Fill in function declarations here.
You want to get into the habit of separating function declarations
From function definitions.
For now, function declarations will go above the main function
(here) and function definitions will go below the main function.
********************************************************/
void func1(string s, int ct);
void func2(string s, int len);
void func3(string s, int len);
int func4(int arr[], int len);
int func5(int arr[], int val, int len);
void func6(int arr[], int ind, int len);
void func7(string s, int arr[], int len, int i1, int i2,bool do_pr);
void func8(string s, int len, int arr[], int len2);
void func9(string s9,int arr1[],int arr2[], int len1,int len2);
void func10(string str10,int arr[],int len);
void func11(string s7,int len,int msize);
void func12(string s,int len,int msize);
void func13(string s,int len,int msize);

/********************** MAIN START ****************************************/

int main() {
string alpha= "abcdefghijklmnopqrstuvwxyz";
cout << "Hello World!" << endl;
/*****************************************************/
 /* for func1 */
cout<<endl<<"func1"<<endl;
string str0 = "let it snow! ";
int x = 4;
func1(str0,x);
/*****************************************************/
 /* for func2 */
cout<<endl<<"func2"<<endl;
string string1 = "kceacruanmpedle sluastethev"; // 28 characters total
func2(string1,28);
/*****************************************************/
 /* for func3 */
cout<<endl<<"func3"<<endl;
 string string2 = "speliknuweorrubs tergudeunfe cestmanlbowctoshac";
func3(string2,47);
/*****************************************************/
 /* for func4 */
int f4arr1[6] = {17, 10, 5, 20, 18, 2};
int f4arr2[8] = {7, 21, 9, 6, 2, 39, 3, 25};
int f4arr3[4] = {-2,1,7,2};
int f4arr4[5] = {5, 8, 2, 13, 7};
int f4arr5[7] = {12, -4, -2, 3, -7, -5, -3};
cout <<endl<<"func4"<<endl<<alpha[func4(f4arr1,6)]<<alpha[func4(f4arr2,8)]<<alpha[func4(f4arr3,4)]<<alpha[func4(f4arr4,5)]<<alpha[func4(f4arr5,7)]<<endl;
/*****************************************************/
 /* for func5 */
string string5 = "vapkfslifbhnoueweoihsakbix";
int f5arr1[14] = {57,16, 46, 41,75,31,64,21,18,13,66,68,81,10};
int f5arr2[20] =
{22,66,67,85,90,92,70,81,42,79,32,27,99,25,49,74,68,12,55,94};
int f5arr3[17] = {96,64,10,73,4,14,71,37,77,52,54,93,19,26,89,84,47};
int f5arr4[13] = {28,49,44,19,37,42,26,78,12,88,67,51,66};
int f5arr5[29] =
{11,32,82,90,97,84,30,77,46,6,69,41,79,48,17,65,25,53,33,16,5,7,21,94,38,27,95,100,92
};
int f5arr6[15] = {84,30,77,46,6,69,1,79,48,17,65,25,53,33,16};
cout <<endl<<"func5"<<endl<< string5[func5(f5arr1,48,14)] << string5[ func5(f5arr2,24,20)]<<string5[func5(f5arr3,80,17) ] << string5 [func5(f5arr4,39,13) ] << string5[func5(f5arr5,36,29) ] << string5 [func5(f5arr6,27,15) ]<< endl;
/*****************************************************/
 /* for func6 */
string string6= "leztiwrqekrktfmwrbfhyljmuekpvonitapsxp";
int f6arr1[10] = {17,4,32,12,8,6,14,24,21,11};
int f6arr2[7] = {21,33,13,18,5,8,35};
int f6arr3[4] = {15,19,32,4};
int f6arr4[5] ={35,20,27,24,6};
/**/
cout <<endl<<"func6"<<endl;
func6(f6arr1,7,10);
for (int i = 0; i < 10; i++) {
cout << string6[f6arr1[i]];
}
cout << " ";
func6(f6arr2,0,7);
for (int i = 0; i < 7; i++) {
cout << string6[f6arr2[i]];
}
cout << " ";
func6(f6arr3,1,4);
for (int i = 0; i < 4; i++) {
cout << string6[f6arr3[i]];
}
cout << " ";
func6(f6arr4,2,5);
for (int i = 0; i < 5; i++) {
cout << string6[f6arr4[i]];
}
cout <<endl<<"func7"<< endl;
/*****************************************************/
 /* for func7 */
string s7 = "skldhbeoieldoodwac hkq cocu iaoe crhpogusyiahhifcet";
int f7arr[27] ={25,45,48,12,10,16,50,9,32,17,19,36,27,33,30,24,20,28,7,6,18,14,37,39,38,42,44};
func7(s7, f7arr, 27, 18,2,false); /* won't decode */
func7(s7,f7arr,27,12,25,true); /* will decode */
 /*****************************************************/
 /* for func8 */
cout<<endl<<"func8"<<endl;
string s6 = "xezuhnbl_uiplypdhqlb";
int len = 20;
int f8arr[] = {2351,92837,482,65,1039,233,23095,1,2037,693842,283};
int len2 = 11;
func8(s6,len,f8arr,len2);
 /*****************************************************/
 /* for func9 */
cout<<endl<<"func9"<<endl;
 string s9 = "slckfoiold,eryt coteidkfzlvkaljwoeihy dnivgphweugaltzsdxls,gfxnbcm wakrm qblanuaksdhzlkjets, anuakd shojqhwtis uzcdoalbicsoiabasboihs";
 int f9arr1[30] = {2,7,9,10,15,24,36,37,42, 44,51,57,66,68,70,74,76,80,88,
89,92,94,98,101,102,113, 115, 120, 122, 124};
int f9len1 = 30;
int f9arr2[17] = {8,16,17,39,40,58,67,71,72,75,77,90,91,93, 99,107,110};
int f9len2 = 17;
func9(s9,f9arr1,f9arr2,f9len1,f9len2);
 /*****************************************************/
 /* for func10 */
cout<<endl<<"func10"<<endl;
string str10 = "alettioe twhaaabosi hkcxl";
int f10arr[23] = {22,11,13,22,5,13,8,3,3,11,7,14,3,19,11,5,1,3,12,9,4,2,22};
func10(str10,f10arr,23);
 /*****************************************************/
 /* for func11 */
cout<<endl<<"func11"<<endl;
string s11 = "mboehdkuxkwpmnfzicosyfmeuqlaitcvwdgn";
len = 36;
func11(s11,len,6);
 /*****************************************************/
 /* for func12 */
cout<<endl<<"func12"<<endl;
string str12 = "gboehdpixkwpangzicjsygmeaqlaltmvwdgeabndckswoshbk";
len = 49;
func12(str12,len,7);
 /*****************************************************/
 /* for func13 */
cout<<endl<<"func13"<<endl;
string s13="w_orp_eshmueryasaa_nootetkdtbueteei_ars!vsfib_t!e_fslg_!rye_yra_";
len = 64;
func13(s13,len,8);
return 0;
}
/*******************************END MAIN *****************************************/
/*******************************func1*****************************************/

void func1(string s, int ct) {
	for(int i=0;i<ct;i++)
		 cout << s<<endl;
}
/*******************************func2*****************************************/

void func2(string s, int len) {
	for(int i=1;i<len;i+=2){
			cout<<s[i];
		}
	cout<< endl;
}
/*******************************func3*****************************************/

void func3(string s, int len) {
	for(int i=len-1;i>=0;i-=2){
			cout<<s[i];
		}
		cout<< endl;
}
/*******************************func4*****************************************/

int func4(int arr[], int len) {
	int avg=0;
	for(int i=0;i<len;i++)
		avg+=arr[i];
	return avg/len;
}
/*******************************func5*****************************************/

int func5(int arr[], int val, int len) {
	int index=arr[0];
			int abs1,abs2;
			if(arr[0]>val){
				abs1=arr[0]-val;
			}else{
				abs1=val-arr[0];
					}
			for(int i=0;i<len;i++){
				if(arr[i]>val){
					abs2=arr[i]-val;
				}else{
					abs2=val-arr[i];
				}
				if(abs1>abs2){
					index=i;
					if(arr[i]<val){
						abs1=val-arr[i];
					}else{
						abs1=arr[i]-val;
					}
				}
				}
	return index;

}
/*******************************func6*****************************************/

void func6(int arr[], int ind, int len) {
	int min=0;
	int tmp;
	//cout << "["<<arr[0];
	for(int i=1;i<len;i++){
		if(arr[i]<arr[min])
			min=i;
		//cout << "," << arr[i];
	}
	//cout << "]"<< endl;
	tmp=arr[min];
	arr[min]=arr[ind];
	arr[ind]=tmp;
	/*cout << "[";
			for(int i=0;i<len;i++){
				cout << arr[i];
				if(i!=len-1)
					cout<<",";
			}
			cout << "]"<< endl;
	*/
}
 /*****************************************************func7*****************************************/

void func7(string s, int arr[], int len, int i1, int i2,bool do_pr){
		int i,temp;
		if(i1>i2){
			temp=i1;
			i1=i2;
			i2=temp;
		}
		temp=arr[i2];
		for(i=i2;i>i1;i--){
			arr[i]=arr[i-1];
			}
		arr[i1]=temp;
		if(do_pr){
			for(i=0;i<len;i++)
				cout << s[arr[i]];

		}
	}
 /***************************************************func8*****************************************/

void func8(string s, int len, int arr[], int len2) {
		int o,r;
		for(int i=0;i<len2;i++){
			o=0;
			while(arr[i]/10!=0||(r!=arr[i]%10)){
				r=arr[i]%10;
				o+=r;
				//cout <<endl<<r<<" , "<<o<<" , ";
				arr[i]=arr[i]/10;
				//cout<<arr[i];
			}
			cout << s[o%len];
		}
	}
 /***************************************************func9*****************************************/

void func9(string s9,int arr1[],int arr2[], int len1,int len2){
		int arr[len1+len2-1],i2=0,i1=0;
		for(int i=0;i<len1+len2;i++){
			//cout << "we here "<<i1<<" , "<<i2<<" , "<<i<<" , "<<arr1[i1]<<" , "<<arr2[i2]<<" , ";
			if(arr1[i1]<arr2[i2]&&i1<len1){
				arr[i]=arr1[i1];
				i1++;
			}else if(arr1[i1]>arr2[i2]&&i2<len2){
				arr[i]=arr2[i2];
				i2++;
			}else if(i1<len1){
				arr[i]=arr1[i1];
				i1++;
			}else if(i2<len2){
				arr[i]=arr2[i2];
				i2++;
			}
			//cout <<arr[i]<<" , "<<
			cout<<s9[arr[i]];
		}
	}
/***************************************************func10*****************************************/

void func10(string str10,int arr[],int len) {
		int d=0,j,arr2[len];
		for(int i=0;i<len;i++){
			if(j==i-1){
					arr2[i-d-1]=arr[i-1];
					//cout<<i<<" , "<<j<<" , "<<d<<" , "<<arr[i-d]<<" , "<<i-1-d<<endl;
			}
			for(j=0;j<i;j++){
				if(arr[i]==arr[j]){
					d++;
					break;
				}
			}
		}
		for(int i=0;i<len-d;i++)
			cout<<str10[arr2[i]];
	}
/***************************************************func11*****************************************/

void func11(string s7,int len,int msize) {
	char arr[msize][msize];
		int c=0,j;
		for(int i=0;i<msize;i++){
			//cout<<"[";
			for(j=0;j<msize;j++){
				arr[i][j]=s7[c+j];
				//cout<<arr[i][j]<<",";
			}
			//cout<<"]"<<endl;
			c+=j;
		}
		//cout<<endl;
		for(int i=0;i<msize;i++){
			for(j=0;j<msize;j++){
				if(j==i)
					cout<<arr[i][j];
				}
			}
}
 /***************************************************func12*****************************************/

void func12(string s,int len,int msize){
	char arr[msize][msize];
		int c=0,j;
		for(int i=0;i<msize;i++){
			//cout<<"[";
			for(j=0;j<msize;j++){
				arr[i][j]=s[c+j];
				//cout<<arr[i][j]<<",";
			}
			//cout<<"]"<<endl;
			c+=j;
		}
		//cout<<endl;
		for(int i=0;i<msize;i++){
			for(j=0;j<msize;j++){
				if(j+i==msize-1)
					cout<<arr[i][j];
			}
		}
}
 /***************************************************func13*****************************************/

void func13(string s,int len,int msize) {
	char arr[msize][msize];
	int c=0,j;
		for(int i=0;i<msize;i++){
			//cout<<"[";
		for(j=0;j<msize;j++){
			arr[i][j]=s[c+j];
				//cout<<arr[i][j]<<",";
			}
				//cout<<"]"<<endl;
			c+=j;
			}
			//cout<<endl;
		for(int i=0;i<msize;i++){
			for(j=0;j<msize;j++){
				cout<<arr[j][i];
					}
				}
}



