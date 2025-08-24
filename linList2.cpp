#include<iostream>
using namespace std;


// safe array with custom indexing 🤠️🤠️🤠️🤠️🤠️🤠️🐎️
class SafeList {
private:
	int *data,starting,ending,capacity,size;
	
	bool isFull(){
		
		return (size == (capacity-1));
	}
	
	bool isEmpty(){
		return (size < 0);
	}
	
	void sort(int *arr){
		int temp_var = 0;
		for(int i =0 ; i < size+1;i++){
			for(int j = i+1;j < size+1;j++){
				if(arr[i] > arr[j]){
					temp_var = arr[i];
					arr[i] = arr[j];
					arr[j] = temp_var;
				}	
			}
		}
		
	}
	
	int * sort_by_copy(){
		int * temp_arr = new int[size+1];
		
		for(int i= 0 ; i< size+1;i++){
			temp_arr[i] = data[i];
		}
		
		this->sort(temp_arr);
		
		return temp_arr;
	}
public:
	SafeList(int starting,int ending){
		this->ending =ending;
		this->starting = starting;
		size= -1;
		capacity = ending-starting+1;
		if(ending-starting < 0) {
			cout<<"Your values are invalid " <<endl;
			return;
		}
		data = new int[capacity];
		
		for(int i =0 ; i < capacity;i++)
			data[i] = 0;
	}
	
	void insert(int index,int val){
		if(isFull()) {
			cout<<"Array is full"<<endl;
			return; 
		}
		
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
	
	bool isPalendrom(){
		if(isEmpty()) return true; // return true if the list is empty
		
		for(int i = 0 ; i <= size;i++){
			if(this->data[i] != this->data[size-i]) return false;
		}
		
		return true;
	}
	
	void insertEnd(int val){
		// if(size< 0 || (size == (capacity)-1)) return;
		insert(starting - size,val);

	}
	int sum(){
		int temp = 0;
		
		for(int i  =0 ; i <= size;i++){
			temp += data[i];
		}
		return temp;
	}
	double mean(){
		int sum =  this->sum();
		
		return sum / (size+1);
		
	}
	
	
	void sorted(){
	
		this-> sort(this->data);
	}
	int median(){
		int *sorted = this->sort_by_copy(),med_ind = size / 2; 
		delete [] sorted;
		
		return data[med_ind];
		
	}

	void view(){
		for(int i =0 ; i < size+1;i++)
			cout<<data[i]<<" ";
		cout<<endl;
	}
};


int main(){
	SafeList li(1,9);
	// cout<<"hello"<<endl;

	li.insert(-5,1);
	li.insert(-5,2);
	li.insert(-5,3);
	li.insert(-5,2);
	li.insert(-5,1);
	
	li.sorted();
	
	cout<<li.median()<<endl;
	cout<<li.mean()<<endl;
	//li.insertEnd(1002);


	li.view();
	return 0;
}
