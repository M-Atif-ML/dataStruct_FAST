#include<iostream>
using namespace std;

class Cart{ // idINd = 0 quantInd= 1
	private:
	int **itemsData,capacity,size;
	bool isFull(){
		return (size == (capacity-1));
	}
	
	bool isEmpty(){
		return (size < 0);
	}

	int doesExist(int id){
		for(int i =0 ;i <= size;i++){
			if(itemsData[i][0] == id){
				return i;
			}
		}
		
		return -1;
	}
	
	void decreaseQuantity(int ind){
		itemsData[ind][1] -=1;
	}
	void full_removal(int ind){
		
			
		if(itemsData[ind][1] == 0){
			cout<<"Working fine"<<endl;
			itemsData[ind][0] = 0 ; 
			itemsData[ind][1] = 0;
			cout<<"Size: "<<size<<endl;
			if(itemsData[ind+1][1] != 0){
				cout<<"Hi motherFucker"<<endl;
			}
			
			
		}
			
	}
	public:
	Cart(int capacity){
		this->capacity = capacity;
		size=-1;
		
		itemsData=  new int*[capacity];
		for(int i =0 ;i < capacity;i++){
			itemsData[i] = new int[2];
		}
		
		for(int i =0 ; i < capacity;i++){
			for(int  j =0 ;j < 2;j++){
				itemsData[i][j] = 0;
			}
		}
	}
	
	
	void add_to_cart(){
		
		if(isFull()){

			cout<<"\nYour cart is full"<<endl;
			return ;
		}
	
		int id,quantity;
		
		cout<<"Enter items id:";
		cin>>id;
		
		if(id <1 or id > capacity){
			cout<<id<<" is not available"<<endl;
			return ;
		}
		
		
		int itemInd = doesExist(id);
		if(itemInd != -1){
			itemsData[itemInd][1] +=1;
		}
		else{	
			quantity = 0;
			size++;
			itemsData[size][0] = id;
			itemsData[size][1] = ++quantity;
		}
		
	}
	
	void remove_item(){ //  the messages at each conditions are different thats why i have to make it separate for each message
		if(isEmpty()){
			cout<<"Your cart is empty"<<endl;
			return;
		}
		
		int itemId,itemInd;
		cout<<"Enter items id you wanna delete: ";
		cin>>itemId;
		if(itemId < 1 or itemId > capacity){
			cout<<itemId<<" is not available"<<endl;
			return ; 
		}
		itemInd = doesExist(itemId);
		if(itemInd == -1){
			cout<<itemId<<" is not already deleted "<<endl;
			return;
		}
		
		
		// real logic for deletion
		decreaseQuantity(itemInd);
		if(itemsData[itemInd][1]==0){
			full_removal(itemInd);
		}
		
		
		
	}	
	
	void show_cart(){
	
		cout<<"\nID"<<"\tquantity"<<endl;
		for(int i =0 ; i <capacity;i++){
			cout<<itemsData[i][0]<<"\t"<<itemsData[i][1]<<endl;
		}
		
	}
	
	
	~Cart(){
		for(int i =0 ;i < capacity;i++){
			delete [] itemsData[i];
		}
		
		delete [] itemsData;
	}
};
int main(){
	int size =4;
	Cart cart(size);
	char choice;
	int iter= 0 ;
	cout<<"Do you wanna add an item:";cin>>choice;
	while((choice == 'y' || choice == 'Y') && iter < size){
		cart.add_to_cart();
		cout<<"Do you wanna add an item:";cin>>choice;
		iter++;
	}
	
	cart.show_cart();
	
	cart.remove_item();
	
	cart.show_cart();
		
	
}
