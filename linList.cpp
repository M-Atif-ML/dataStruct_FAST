#include<iostream>
using namespace std;

class List{
private:
	int *data,capacity,size;
	bool isFull(){
		if (size == (capacity-1)){
			cout<<"Array is full"<<endl;
			return true;
		}
		return false;
	} 
	bool isEmpty(){
		if (capacity > 0){
			return false;
		}
		return true;
	}
	int insertion_(int val,int ind){
		if(data[ind] != 0){
			for(int i = size;i>= ind;i--)
				data[i+1] = data[i];
		}	
		else if(data[ind-1]==0 and ind != 0){ // this means that user is breaking the linearity 
			ind  = size+1;
			cout<<"Index updated: "<<ind<<endl;
		}

		data[ind] = val;
		size+=1;
		return ind;
	}
	void deletion_index(int index){
		data[index] = 0;

		if (data[index+1] != 0){
			for(int i = index;i< size;i++){
				data[i] = data[i+1];
			}
		}
		data[size] = 0;
	}

	int search(int val){
		if (val < 0){
			cout<<"Cant get -ve value"<<endl;
			return -1;
		} 
		int index = -1;
		for(int i= 0 ;i < size;i++){
			if (data[i] == val){
				index = i;
				break;
			}
		}

		return index;
	}
	void deletion_val(int val){
		int index = search(val);
		if(index != -1){
			deletion_index(index);
		}
		else{
			cout<<"cant find "<<val; 
		}
		

		cout<<endl;
	}
	
	void delete_All(int val){
		cout<<"Delete all"<<endl;
		int count = 0;
		for(int i = 0 ; i < size;i++){
			if(data[i] == val){
				deletion_index(search(val));
				i--;
				
			}


				
		}


		
		
	}	
public:
	List(int capacity){
		this->capacity = capacity;
		size=-1;
		data = new int[capacity];
		for(int i = 0 ;i < capacity;i++)
			data[i] = 0;

	}

	void increase_cap() {
	    if (capacity <= 0) return;

	    int new_cap;
	    cout << "Enter how much to increase capacity: ";
	    cin >> new_cap;

	    int *temp = new int[size+1]; // copy only actual used elements
	    for (int i = 0; i <= size; i++) {
	        temp[i] = data[i];
	    }

	    delete [] data;

	    capacity += new_cap; // increase once only
	    data = new int[capacity];

	    // copy old elements back
	    for (int i = 0; i <= size; i++) {
	        data[i] = temp[i];
	    }

	    // initialize the rest with 0
	    for (int i = size+1; i < capacity; i++) {
	        data[i] = 0;
	    }

	    delete [] temp;
	    temp = nullptr;


	}

	void insertion(){
		if (isFull()){
			cout<<"your array is full"<<endl;
			return ;
		}



		int val,ind=-1;
		cout<<"Enter value along with index (val ind):";
		cin>>val>>ind;

		if(ind < 0 || ind >= capacity){
			cout<<"Segmentation -- fault"<<endl;
			return;
		}

		int index = insertion_(val,ind); 

		cout<<"Your value "<<val<<" is added into index = "<<index<<endl;


	}	

	void deletion(){
		if (isEmpty()) return;

		
		char choice;
		cout<<"Do you wanna delete by value or by index: ";
		cin>>choice;

		if (choice == 'v' || choice == 'V'){
			char isAll;
			
			int val;
			cout<<"Ok now enter value: ";
			cin>>val;
			cout<<"Enter do you wanna delete all of the accurance of "<<val<<" (y/n): ";
			cin>>isAll;
			
			if(isAll == 'y') delete_All(val);
			else deletion_val(val);

		}	
		else{
			int index = -1;
			cout<<"Enter index: ";cin>>index;
			if(index < 0 || index > size){ return; }

			deletion_index(index);

		}

		
	}



	void view(){
		for (int i =0 ; i < capacity;i++){
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}

	void cont_insertion(){
		for (int i = 0; i< capacity;i++){
			this->insertion();
		}
	}
	int get_cap(){ return capacity;}
	int get_size(){ return size;}
	~List(){
		delete [] data;
		data = nullptr;
	}
};





int main(){
	List li(4);
	li.view();



	li.cont_insertion();
	li.view();
	li.deletion();


	li.view();
	return 0;
}
