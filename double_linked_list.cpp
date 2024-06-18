#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
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

void insertathead(Node *&tail, Node *&head, int d)
{

    if (head == NULL)
    {
        Node *node1 = new Node(d);
        head = node1;
        tail = node1;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        temp->prev = NULL;
        head = temp;
    }
}

void insertattail(Node *&head, Node *&tail, int d)
{

    if (tail == NULL)
    {
        Node *node1 = new Node(d);
        head = node1;
        tail = node1;
    }
    else
    {
        Node *temp = new Node(d);

        tail->next = temp;
        temp->prev = tail;
        temp->next = NULL;
        tail = temp;
    }
}

void insertatposition(Node *&tail, Node *&head, int d, int position)
{
    if (position == 1)
    {
        insertathead(tail, head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertattail(head, tail, d);
        return;
    }
    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}

void deleteatnode(int position, Node *&head)
{

    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        // deleting any middle or last element
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

       curr->prev=NULL;
       prev->next =curr->next;
       curr->next=NULL;
        delete curr;
    }
}

// printing a double linked list
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

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    Node *node1 = new Node(10);
    head = node1;
    tail = node1;
    print(head);

    insertathead(tail, head, 9);
    print(head);

    insertathead(tail, head, 8);
    print(head);

    insertathead(tail, head, 7);
    print(head);

    insertathead(tail, head, 6);
    print(head);

    insertattail(head, tail, 11);
    print(head);

    insertatposition(tail, head, 13, 7);
    print(head);

    insertatposition(tail, head, 2, 1);
    print(head);

    insertatposition(tail, head, 100, 5);
    print(head);

    insertatposition(tail, head, 100, 1);
    print(head);

    insertatposition(tail, head, 100, 2);
    print(head);

    insertatposition(tail, head, 100, 3);
    print(head);

    insertatposition(tail, head, 100, 4);
    print(head);

    insertatposition(tail, head, 1010, 14);
    print(head);

    insertatposition(tail, head, 104, 1);
    print(head);

    insertatposition(tail, head, 200, 4);
    print(head);
cout <<"head" <<head->data <<endl;
    cout <<"tail" <<tail->data <<endl;

    deleteatnode(16,head);
    print(head); 
    cout <<"head" <<head->data <<endl;
    cout <<"tail" <<tail->data <<endl;
    return 0;
}