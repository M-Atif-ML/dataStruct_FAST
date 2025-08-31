#include<iostream>
using namespace std;

class toDoList{
	private:
	string *data;
	int cap,size;
	
	bool isFull(){
		return (size == (cap-1));
	}
	bool isEmpty(){
		return (size < 0);
	}
	public:
	toDoList(int capacity){
		cap = capacity;
		
		data= new string[capacity];
		for(int i =0; i < capacity;i++){
			data[i]  = "Null";
		}
		size = -1;
	}
	
	void add_task(){
		string task;
		
		cout<<"Enter tasks:";
		cin>>task;
		
		if(isFull()){
			cout<<"No more cap"<<endl;
			return;
		}
		
		int ind = add_task(task);
		data[ind] = task;
		
	}
	void complete(){
		if(isEmpty()) return;
		string task;
		cout<<"Enter task:";
		cin>>task;
		int index = search(task);
		
		if(index == -1) return;
		
		complete(index);
		size--;
	
	}
	private:
	
	void complete(int index){
		data[index] = "Null";
		
		if(index+1 < cap && data[index+1] != "Null"){
			for(int i = index;i < size;i++)
				data[i] = data[i+1];
		}
		
		data[size] = "Null";
	
	}
	
	int add_task(string task){
		if(search(task) != -1){
			char choice;
			cout<<"The task you entered is already in list so do you still wanna add it at the last or you dont wanna do anything(y/n): " ;
			cin>>choice;
			if(choice == 'Y' || choice == 'y'){
				size++;
				return size;
			}
			
		}

		size++;
		return size;
		
	}
	
	int search(string task){
		for(int i =0 ;i < cap;i++)
			if(task == data[i])
				return i;
		return -1;
		
	}
	public:
	void show(){
		for(int i =0 ; i <= size;i++){
			cout<<i+1<<". "<<data[i]<<endl;
		}
	}
	
	~toDoList(){
		delete [] data;
	}
	

};

int main(){

	toDoList li(5);
	
	li.add_task();
	li.add_task();
	li.add_task();
	li.show();
	
	li.complete();
	
	li.show();
	li.complete();
	li.show();
	
	return 0;

}
