#include <iostream>
using namespace std;
struct node{
	int data;
	node *next;
	node(int data,node *next=NULL){
		this->data = data;
		this->next = next;
	}
};
 
node *createlist(){
	node *head = NULL;
	node *cur = NULL;
	for(int i=0;i<5;i++){
		//head = new node(i,head);
		if(head==NULL){
			head = new node(i);
			cur = head;
		}else{
			cur->next = new node(i);
			cur = cur->next;
		}
	}
	return head;
}
 
void displaylist(node *head){
	cout<<"list node -> ";
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}
 
int main(){
	node *head = createlist();
	displaylist(head);
	return 0;
}