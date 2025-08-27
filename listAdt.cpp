#include<iostream>
using namespace std;

class List{
	public:
	virtual void insertion() = 0;
	virtual void deletion() = 0;
	virtual void swap(int &num1,int &num2) = 0;
	virtual void reverse() = 0;
	virtual void search() = 0;
	virtual void sort() = 0;

    	
	 
};

class linearList: public List{

	private:
	int *data,size,capacity;
	
	bool isFull(){
		return (size == (capacity-1));
	}
	bool isEmpty(){
		return (size < 0);
	}
	bool isValidIndex(int index){
		return (index < capacity && index>=0);
	}
		
	
	int insertion(int index){
		if(index != 0 && data[index-1] == 0){ // this mean the array index is greater then size 
			index =size+1;
			cout<<" You index was breaking the linearity I 👨‍💻️ have to add your value at index "<<size+1<<endl;
		}
		else if(data[index] != 0){ // this means the index already have an array stored
			for(int i =size;i>=index;i--){
				data[i+1] = data[i];	
				
			}
		}

		return index;
	}
	int linear_search(int val){ // must return the index of searched value
		for(int i =0 ;i < size; i++){
			if(data[i] == val)
				return i;
		}
		
		return -1;
	}
	void deletion(int index){
		data[index] = 0;
		
		if(index+1 < capacity && data[index+1] ){ // to make our safe from seg fault iam first checking weather the i +1 is in the capacity range
			for(int i = index;i < size; i++){
				data[i] = data[i+1];
 			}	
				
		} 
		data[size] = 0; 
		
		--size;
		
	}
	void bubble_sort(){
		int temp=data[0];
		for(int i=0 ; i <= size;i ++){
			for(int j =i+1; i <=size;i++){
				if(data[i]>data[j]){
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
			
			}
		}
	}
	
	int binary_search(int val,int starting,int ending) {  
		if(starting > ending) return -1;
		int mid = (starting+ending) / 2;
		if(data[mid] == val)
			return mid;
		else if (data[mid] < val) 
			return this->binary_search(val,starting+mid,ending);
		else
			return this->binary_search(val,starting,ending-mid);
			
		return -1;
	}	
	
	public:
	linearList(){
		size=-1;
	}
	linearList(int capacity){
		this->capacity = capacity;
		size=-1;
		data= new int[capacity];
		for(int i =0 ; i < size; i++){
			data[i] = 0;
		}
		
		
	}
	void insertion() override {
		int val,index;
		cout<<" Enter value: ";
		cin>>val;
		cout<<" Enter index: ";
		cin>> index;
		
		if(!isValidIndex(index)){
			cout<<"-Index is not valid 🤬️\n";
			return;
		}
		
		if(isFull()){ // if array is full we cant insert anymore values 
			cout<<"Your array is full 🤢️"<<endl;
			return;
		}
		
		index = insertion(index);
		
		data[index] = val;
		
		size++;
	}
	
	void deletion() override{
		char choice;
		cout<<" Do you wanna delete by index of by value: ";cin>>choice;
		
		if(choice == 'v' || choice == 'V'){
			int val;	
			int index_of_val = linear_search(val); // just to make this simple i am not using binary search because it requires sorted array 
							       // and my sorting algorithm is slow
			if(index_of_val ==-1){
				cout<<"🧐️🧐️🧐️ The value you provide is not in the list 🧐️🧐️🧐️"<<endl;
				return ;
			}	
					
			cout<<"Enter value:";cin>>val;
			deletion(index_of_val);
		}
		else if(choice ==  'i' || choice == 'I'){
			int index;
			cout<<" Enter index: ";cin>>index;
			
			deletion(index);
		}
		else{
			cout<<" You input is invalid "<<endl;
		}
		
		
	}
	
	void swap(int &num1,int &num2) override{
		int temp;
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
	void reverse()  override{
		int mid = size /2;
		
		for(int i =0 ; i <=mid;i++){
			swap(data[i],data[size-i]);
		}		
		
	}

	void search()  override {
		int value;
		cout<<" Enter value 🙃️:= ";cin>>value;
		bubble_sort(); // for binary search we have to first sort the array 
		if(value == 0) {
			cout<<"Sorry 0 is a centinal value:";
			return ;
		}
		
		int index = binary_search(value,0,size);
		
		cout<<" 🐎️Your value is at "<<index<<endl;
	}
	void sort(){
		this->bubble_sort();
		cout<<" Your list is successfully sorted 😉️"<<endl;
	}
	
	linearList mergeLists(linearList *second){
		linearList temp((this->size+1) + (second->size+1));
		// adding elements of first array
		for(int i =0 ; i <=this->size;i++){
			temp.data[i] = this->data[i];
		}
		for(int i = 0; i <= second->size;i++)
			temp.data[i+this->size+1] = second->data[i];
		return temp;
	}
	void view(){
	
		cout<<"\nFrom view:"<<endl;
	
		for(int i =0 ; i < capacity;i++){
			cout<<data[i]<<" ";
		}
		
		cout<<endl;
	}
	
	~linearList(){
		delete [] data ;
	}
};

int main(){
	linearList *li =  new linearList(5);
	linearList *li2 = new linearList(3);
	cout<<"List 1"<<endl;
	li->insertion();
	li->insertion();
	li->insertion();
	li->insertion();
	li->insertion();
	li->view();
	
	cout<<"\nlist 2"<<endl;
	li2->insertion();
	li2->insertion();
	li2->insertion();
	li2->view();
	
	cout<<"Merged:"<<endl;
	linearList merged = li->mergeLists(li2);
	merged.view();
	
	delete li2;
	delete li;
	return 0;
		
	}
