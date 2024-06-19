#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;
   
    Node(int data){

        this->data=data;
        this->prev=NULL;
        this->next= NULL;
    }
};
 void insertathead(int data,Node* &head,Node* &tail){


if(head == NULL)
{
    Node* temp=new Node(data);
    temp->prev=NULL;
    temp->next=NULL;
    head=temp;
    tail=temp;
}
else{

    Node* temp=new Node(data);
    temp->prev=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
}
 }


void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}




int main(){

Node* head=NULL;
Node* tail=NULL;




insertathead(15,head,tail);
insertathead(12,head,tail);

print(head);



    return 0;
}