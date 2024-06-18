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

cout <<"successfully inserted element at head"<<endl;
}

void insertattail(Node* &tail,int d){

Node *temp=new Node(d);
temp->next=NULL;
tail->next=temp;
tail=tail->next;
}

void insertatmiddle(Node* &tail,Node* &head,int position,int d){

if(position==1){
    insertathead(head,d);
    return;
}
int count=1;
Node *headt=head;
while(count<position-1){
    headt=headt->next;
    count++;
}
//inserting at last position
if(headt->next==NULL){
    insertattail(tail,d);//as we have to update the tail value to null
    return;
}

//creating new node
Node *nodetoinsert=new Node(d);
nodetoinsert->next=headt->next;
headt->next=nodetoinsert;
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


insertatmiddle(tail,head,4,22);
print(head);
cout<<"head"<<head->data <<endl;
cout<<"tail"<<tail->data <<endl;
return 0;
} 