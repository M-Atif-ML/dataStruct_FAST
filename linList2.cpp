#include<iostream>
using namespace std;


// safe array with custom indexing 🤠️
class SafeList {
private:
	int *data,starting,ending,capacity,size;
	bool isFull(){
		return (size == (capacity-1));
	}
	bool isEmpty(){
		return (size < 0);
	}
public:
	SafeList(int starting,int ending){
		this->ending =ending;
		this->starting = starting;
		size= -1;
		capacity = ending-starting+1;
		if(ending-starting < 0) {
			cout<<"Your values are invalid"<<endl;
			return;
		}
		data = new int[capacity];
		
		for(int i =0 ; i < capacity;i++)
			data[i] = 0;
	}
	
	void insert(int index,int val){
		if(isFull()) return ;
		
		starting = -starting;
		index = index+starting;
		
		if(data[index-1]==0)
			index = size + 1;
		else if(data[index] != 0)
			for(int i= size; i >= index; i++)
				data[i] = data[i+1];
		data[index] = val;
		size+=1; 	
		
	}
	
	void view(){
		for(int i =0 ; i < capacity;i++)
			cout<<data[i]<<" ";
		cout<<endl;
	}

};


int main(){
	SafeList li(-5,9);
	

	li.view();
	li.insert(-5,32);
	li.insert(-4,90);
	li.insert(-3,78);

	li.view();
	return 0;
}
