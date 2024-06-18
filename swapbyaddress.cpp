#include<iostream>
using namespace std;

class Node{
public:
int data;
Node *next;

Node(int d){
this->data=d;
this->next=NULL;


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



swap(int pos1,int pos2,Node* &head){
Node* prev1=NULL;
Node* prev2=NULL;
Node* curr1=head;
Node* curr2=head;
Node* forward=NULL;

int cnt=1;
while(cnt<pos1){
    prev1=curr1;
    
    curr1=curr1->next;
    cnt++;
}


cnt=1;
while(cnt<pos2){
    prev2=curr2;
   
    curr2=curr2->next;
    cnt++;
}

forward=curr2->next;
prev1->next=curr2;
curr2->next=curr1->next;
prev2->next=curr1;
curr1->next=forward;

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
  
    int pos1,pos2;
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



cout <<"enter the position 1 to be swapped";
cin >> pos1;

cout <<"enter the position 2 to be swapped";
cin >> pos2;

swap(pos1,pos2,head);
print(head);



return 0;
}  