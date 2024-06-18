#include<iostream>
using namespace std;


class Node{
public:
int data;
Node *next;

Node(int d){
this->data=d;
this->next=NULL;
//cout<<this->data<<endl;
//cout <<this->next<<endl;
}

};
void insertathead(Node* &head,int d){

Node* temp=new Node(d);
temp->next=head;
head=temp;

cout <<"successfully inserted element at head";
}

void insertattail(Node* &tail,int d){

Node *temp=new Node(d);
temp->next=NULL;
tail->next=temp;
tail=tail->next;


}



void print(Node* &head){

    Node* headt=head;
    while(headt!=NULL){
        cout<<headt->data <<" ";
        headt=headt->next;
    }
    cout <<endl;
}
int main() {
  

    Node *node1=new Node(10);

    Node* head=node1;
    Node* tail=node1;

cout<<"///////////////////////"<<endl;

insertathead(head,12);

cout <<"............."<<endl;

print(head);


insertattail(tail,15);

print(head);

return 0;
}