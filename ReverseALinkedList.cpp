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
//destructor
~Node(){
int val=this->data;
if(this->next!=NULL){
    delete next;
    next=NULL;
}
cout <<"memory free for node with data"<< val << endl;
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

void deleteatnode(int position,Node* &head){

if(position==1){
    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
}
else
{
    // deleting any middle or last element
 Node* curr=head;
 Node* prev=NULL;

 int cnt=1;
 while(cnt<position){
    prev=curr;
    curr=curr->next;
    cnt++;
 }
prev->next=curr->next;
curr->next=NULL;
delete curr; 

 }
}

reverse(Node* &head){
Node* curr=head;
Node* prev=NULL;
Node* forward=NULL;


while(head !=NULL){
curr=head;
forward=curr->next;
curr->next=prev;
head=forward;
prev=curr;
}
head=prev;
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
  

    Node *node1=new Node(2);

    Node* head=node1;
    Node* tail=node1;



insertathead(head,1);
print(head);


insertattail(tail,3);
print(head);


insertatmiddle(tail,head,4,4);
print(head);


insertathead(head,5);
print(head);

/*
insertattail(tail,7);
print(head);


insertatmiddle(tail,head,4,8);
print(head);
*/
//deleteatnode(1,head);
reverse(head);
print(head);



return 0;
}  