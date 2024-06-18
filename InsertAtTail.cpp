#include<iostream>
using namespace std;


class Node{
public:
int data;
Node *next;



Node(int data){
  cout <<"default constructor called";
this->data=data;
cout << data <<endl;
this->next=NULL;
cout << next <<endl;
}

};
void insertathead(int d,Node* &head){//&is used as we dont want a copy but only only the original value

//new node create
Node* temp=new Node(d);
temp->next=head;
head=temp;
}

void insertattail(int d,Node* &tail){

//Node create
Node *temp=new Node(d);
tail->next=temp;
tail=temp;


}

void print(Node* &head){
    Node *temp=head;//temp is a node pointer used to get the address of thr nodes which have to be printed 
    while(temp!=NULL){
        cout<< temp->data <<" ";
        temp=temp->next;
    }
}
 
int main() {
 
//create a new node
Node *node1=new Node(10);
cout <<node1->data<<endl;
cout <<node1->next<<endl;

//head pointer to node1
Node* head=node1;
Node  *tail=node1;
cout <<"................"<<endl;
 print(head);

insertathead(12,head);
print(head);
insertattail(15,tail);
 print(head);

 

return 0;
}