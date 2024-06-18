#include<iostream>
using namespace std;


class Node{
public:
int data;
Node *next;

//constructor
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
void insertNode(Node* &tail,int element,int d){

Node* newNode=new Node();
tail=newNode;
newNOde->next=newNode;







}

int main(){


    return 0;
}