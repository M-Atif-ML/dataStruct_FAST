#include<iostream>
using namespace std;

struct userData{
	string name;
	int age;
	userData(string name = "",int age= 0){
		this->name = name;
		this->age= age;
	}
};

class Node{
	public:
	userData data;
	Node * next;
	Node(string name,int age ):next(nullptr){
		data.name = name;
		data.age = age;
	}

};

class linkList{
	private:
	Node  *head,*tail;
	string name;
	int age;
	
	public:
	linkList():head(nullptr),tail(nullptr){}
	
	void insertAtBegining(){
		cout<<"Enter Name of the person:";
		cin>>name;
		cout<<"Enter the age of the person:";
		cin>>age;
		
		Node * newNode = new Node(name,age);
		
		newNode-> next = head;
		head = newNode;
		
		if(tail == nullptr)
			tail = newNode;
		
	}

	void show(){
		Node* iter= head;
		cout<<"Name\tAge"<<endl;
		while(iter != nullptr){
			cout<<iter->data.name<<"\t";
			cout<<iter->data.age;
			iter = iter->next;
			cout<<endl;
		} 
		cout<<endl;
	
	}
	
	~linkList(){ // deletion logic
		Node * temp = head;
		Node *iter = head->next;
		while (iter != nullptr){
			delete temp;
			temp = iter;
			iter = iter -> next;
		}
		
		delete temp;
	}

};

int main(){
	linkList li;
	li.insertAtBegining();
	li.insertAtBegining();
	li.insertAtBegining();
	li.insertAtBegining();
	li.show();
	
	return 0;

}
