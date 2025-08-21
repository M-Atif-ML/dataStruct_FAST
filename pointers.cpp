#include<iostream>
using namespace std;

void change_vals(int *& p,int *q ){
	int y = 190;

	cout<<q<<endl;
	*q = 123;

}

int main(){
	int *p,*q,val = 10;
	q = &val;
	cout<<*q<<endl;
	cout<<q<<endl;
	change_vals(p,q);
	// cout<<*q<<endl;
	cout<<val<<endl;

	return 0;
}