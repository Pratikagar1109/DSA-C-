#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {

     this->size=size;
     arr=new int[size];
     top=-1;
    }

    //inserting 
    void push(int data)
    {
        if(size-top>1){
            top++;
            arr[top]=data;
        }
        else
        {
            cout<<"stack overflow"<<endl;
        }
    }

    void pop(){
    cout<<"the top element of the stack"<<arr[top]<<"is popped out"<<endl;
   if(top>=0){
    top--;
   }
   else{
    cout<<"stack underflow"<<endl;
   }
    }

    int peek(){
 if(top>=0 ){
 return arr[top];
    }
    else
    {
        cout<<"stack is empty";
        return -1;
    }
    }


    bool isEmpty(){
   if(top==-1){
    return true;
   }
   else{
    return false;
   }
    }
};



int main() {


/*
    stack<int>s;

s.push(3);
s.push(4);
s.push(13);
s.push(500);
s.pop();
cout<<"the top of the stack is"<<s.top();

cout<<"the stack is emptyy or not"<<s.empty();
*/

Stack st(5);

st.push(12);
st.push(16);
st.push(10);
st.push(11);

cout<<"the top of the stack is"<<st.peek();
return 0;
}