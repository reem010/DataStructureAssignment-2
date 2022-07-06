#include <iostream>
using namespace std;

template<class T>
class Stack{
    int top;
    int MAX_SIZE;
    T *item;
public:
    Stack(int maxsize){
        MAX_SIZE=maxsize;
        item=new T[MAX_SIZE];
        top=-1;
    }
    Stack(){
        MAX_SIZE=1000000;
        item=new T[MAX_SIZE];
        top=-1;
    }
    bool push(T element){
        if(top>=MAX_SIZE-1){
                return false;
        }else {
            top++;
            item[top] = element;
            return true;
        }
    }
    bool isEmpty(){
        if(top==-1)
            return true;
        else
            return false;
    }
    bool pop() {
        if (isEmpty()) {
            return false;
        } else {
            top--;
            return true;
    }
    }
    bool pop(T &elem) {
        if (isEmpty()) {
            return false;
        } else {
            elem = item[top];
            top--;
            return true;
        }
    }
    bool getTop(T &topE){
        if (isEmpty()) {
            return false;
        } else {
            topE = item[top];
            return true;
        }
    }
    T getTop(){
        if (isEmpty()) {
        } else {
            return item[top];
        }
    }

    void clear(){
        top=-1;
    }
    void print(){
        cout<<"[";
        for(int i=top; i>=0;i--){
            cout<<item[i]<<" ";
        }
        cout<<"]";
        cout<<endl;
    }
    int getLength(){
        return top+1;
    }

};
string unixStyle(string path){
    Stack<string>s;
    string temp;
    for(int i=0; i<path.length();i++){
        temp.clear();
        while(path[i]=='/'){i++;}
        while(path[i]!='/'&& i<path.length()){
            temp.push_back(path[i]);
            i++;
        }
        if(temp.compare("..")==0){
            s.pop();
            continue;
        }
        if(temp.compare(".")==0){
            continue;
        }
        if (temp.length()!= 0)
            s.push(temp);
    }
    Stack<string> s2;
    while (!s.isEmpty()) {
        s2.push(s.getTop());
        s.pop();
    }
    string lastString="/";
    for(;!s2.isEmpty();){
        if(s2.getLength()!=1){
            lastString+=s2.getTop()+"/";
        }else{
            lastString+=s2.getTop();
        }
        s2.pop();
    }
    return lastString;
}
int main() {
    cout<<"Example 1:"<<endl;
    cout<<"path = /home/"<<endl;
    cout<<"Output: "<<unixStyle("/home/")<<endl;
    cout<<"Example 2:"<<endl;
    cout<<"path = /../"<<endl;
    cout<<"Output: "<<unixStyle("/../")<<endl;
    cout<<"Example 3:"<<endl;
    cout<<"path = /home//foo/"<<endl;
    cout<<"Output: "<<unixStyle("/home//foo/")<<endl;
}
