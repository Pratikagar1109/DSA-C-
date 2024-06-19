#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;


    // CONSTRUCTOR
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

    void insertathead(int data,Node* &head){   // & is used as a reference
    
    Node *temp=new Node(data);
    temp->next=head;
    head=temp;
    cout <<"successfully inserted" << endl;
    }



    void insertattail(int data,Node* &tail){
      Node *temp= new Node(data);
      temp->next=NULL;
      tail->next=temp;
      tail=tail->next;

      cout << "successfully entered at tail"<< endl;

    }

    void  insertinmiddle(int data,Node* &head,int position){
        if(position == 1){
            insertathead(data,head);
            return;
        }


     int count=1;
         Node *headt;
        headt=head;
     while(count < position){
        
        headt=headt->next;
        count ++;
     }

    Node *nodetoinsert=new Node(data);
    nodetoinsert->next=headt->next;
    headt->next=nodetoinsert;
    }
   
  void deletenode(int position,Node* &head){
  
  if(position == 1){
    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
  }
  else{
   Node* prev=NULL;
   Node* curr=head;
   int count=1;
   while(count < position){
    prev=curr;
    curr=curr->next;
    count ++;
   }
   prev->next=curr->next;
   curr->next=NULL;
   delete curr;
  }
  }

   
    void print(Node* &head){    // & is used as a reference
        cout<<"printing the numbers"<< endl;
    while(head != NULL){
        cout << head->data << endl;
        head=head->next;

    }
    }


int main(){
 int data;
    

    Node *node1= new Node(2);
    Node* head=node1;
    Node* tail=node1;

 insertathead(1,head);

 insertattail(3,tail);

 insertinmiddle(9,head,3);

// deletenode(2,head);

 print(head);

    // cout << node1->data << endl;
    // cout << node1->next;

    return 0;
}