#include<iostream>
//#include<stack>
#include<limits.h>
using namespace std;

class stack {
    // properties 
    public:
    int *arr;
    int top;
    int size;
    // Behaviour 
    stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;

    }
    void push(int element ){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"stack is overflow "<<endl;
        }

    }
    void pop(){
        if(top >= 0){
            top--;

        }
        else{
            cout<<" stack underflow "<<endl;
        }

    }

    int peak(){
        if(top >=0 ){
            return arr[top];
        }
        else{
            cout<<"stack is empty "<<endl;
            return -1;
        }
        

    }
    bool isempty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    stack st(5); // (5) define size of stack 
    st.push(34);
    st.push(56);
    st.push(22);
    st.push(33);
    st.push(22);
    st.push(3);
    
    cout<< st.peak() <<endl;
    st.pop();
    cout<< st.peak() <<endl;
    st.pop();
    cout<< st.peak() <<endl;
    st.pop();
    if(st.isempty()){
        cout<<"stack is empty mere bhai "<<endl;
    }
    else{
        cout<<"stack is not empty mere bhai  "<<endl;
    }
   

    return 0;
}