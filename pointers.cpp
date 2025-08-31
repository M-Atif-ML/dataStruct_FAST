#include<iostream>
using namespace std;

// void change_vals(int *& p,int *q ){
// 	int y = 190;

// 	cout<<q<<endl;
// 	*q = 123;

// }

// int main(){
// 	int *p,*q,val = 10;
// 	q = &val;
// 	cout<<*q<<endl;
// 	cout<<q<<endl;
// 	change_vals(p,q);
// 	// cout<<*q<<endl;
// 	cout<<val<<endl;

// 	return 0;
// }


// int fab(int i){
// 	if (n <= 0) return 1;

// 	return fact(n-1) * n;
// }

// void fab_(int iter,int limit,int a = 0,int b = 1,int sum = 0){
// 	if (iter >= limit) return ;
// 	sum = a+b;
// 	cout<<sum<<" ";
// 	fab_(iter+1,limit,b,sum,0);
// }
// int main(){
// 	cout<< 0<<" ";
// 	cout<<1<<" ";
// 	fab_(0,10);
// 	// cout<<fact(30)<<endl;
// 	cout<<endl;
// 	int a=0,b=1,sum;
// 	cout<<a<<" "<<b<<" ";
// 	for (int  i = 0; i < 10;i++){
// 		sum = a+b;
// 		cout<<sum<<" ";
// 		a= b;
// 		b= sum;
		


// 	}
// 	cout<<"...";
// 	cout<<endl;
// 	return 0;
// }


// =======================================================================

// int main(){

// 	int size= 0,*arr = new int[size],input;
   

// 	while(input){
		
// 		int *temp = new int[size+1];
// 		for(int i =0 ; i < size;i++){
// 			temp[i] = arr[i];
// 		}
// 		cout<<"Enter number :=";
// 		cin>>input;
// 		temp[size] = input;		
// 		delete [] arr;

// 		arr = temp;
// 		size+=1;

// 		// delete [] temp;
// 	}

// 	for(int i =0 ; i < size;i++){
// 		cout<<arr[i]<<" ";
// 	}	

// 	cout<<endl;

// 	delete [] arr;

// }

// =======================================================================

/*
void addvalues(string *&arr,int &size ){
	string *temp = new string[size+1];
	
	for(int i = 0 ; i < size;i++)
		temp[i] = arr[i];
	cout<<"Enter value: ";
	cin>>temp[size];
	
	delete [] arr;
	
	arr = temp;
	size+=1;
}

int main(){
	char choice = 'y';
	int size= 0 ;
	string *arr= new string[size]; 
	while(choice == 'y' || choice == 'Y'){
		cin>>choice;
		if(choice != 'y' || choice== 'Y') continue;
		addvalues(arr,size);
	}
	
	for(int i =0 ; i < size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	delete [] arr;
	
	return 0;
}


*/


int main(){

	int a = 3, b = 6;
	int *p1 = &a, *p2 = &b;
	int **pp = &p1;

	**pp = *p2 + **pp; // step 1
	pp = &p2;          // step 2
	**pp = **pp - *p1; // step 3

	cout<<a<<endl;
	cout<<b<<endl;
	return 0;
}



