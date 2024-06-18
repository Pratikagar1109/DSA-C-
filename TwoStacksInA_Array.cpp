#include <iostream>
using namespace std;
class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

void push1(int value){
if(top2-top1>0){  // top2=size;
    top1++;
    arr[top1]=value;
}else{
    cout<<"stack overflow";
}
}

void push2(int value){
if(top2-top1>0){  //top2=size;
    top2--;
    arr[top2]=value;
}else{
    cout<<"stack overflow";
}
}

void pop1(){
    if(top1>-1){
        top1--;
    }
    else{
        cout<<"stack underflow";
    }
}

void pop2(){
    if(top2<size){
        top2++;
    }
    else{
        cout<<"stack underflow";
    }
}

void print(){
    for(int i=0;i<size;i++)
{
    cout << arr[i]<<endl;
}
}
};

int main()
{

Stack st(10);

st.push1(1);
st.push1(3);
st.push1(5);
st.push1(7);
st.push1(9);
st.push1(10);
st.push2(2);
st.push2(4);
st.push2(6);
st.push2(8);



st.print();

    return 0;
}