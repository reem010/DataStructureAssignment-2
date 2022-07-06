#include <iostream>
#include<algorithm>
#include <array>
using namespace std;
const int MAX=1000000;
template<typename T>
class Queue{
    int rear;
    int front;
    int length;
    T *arr;
    int maxSize;
public:
    Queue(){
        maxSize=MAX;
        arr=new int[maxSize];
        front=0;
        rear=maxSize-1;
        length=0;
    }
    Queue(int size){
        if(size<=0)
            size=100;
        maxSize=size;
        arr=new int[maxSize];
        front=0;
        rear=maxSize-1;
        length=0;
    }
    int getMaxSize(){
        return maxSize;
    }
    bool isEmpty(){
        return length==0;
    }
    bool isFull(){
        return length==maxSize;
    }
    bool addQueue(T item){
        if(isFull()){
            return false;
        }else{
            rear=(rear+1)%maxSize;
            arr[rear]=item;
            length++;
            return true;
        }
    }
    bool deleteQueue(){
        if(isEmpty()){
            return false;
        }else{
            front=(front+1)% maxSize;
            length--;
            return true;
        }
    }
    T getFront(){
        if(!isEmpty())
            return arr[front];
    }
    void getFront(T &f){
        f= arr[front];
    }
    T getRear(){
        if(!isEmpty())
            return arr[rear];
    }
    void printQueue(){
        if(!isEmpty()){
        for(int i=front;i!=rear; i=(i+1)%maxSize){
            cout<<arr[i]<<" ";
        }
        cout<<arr[rear];
        cout<<endl;}
    }
    T search(T elem){
        int pos=-1;
        if(!isEmpty()){
            for(int i=front; i!=rear;i=(i+1)% maxSize){
                if(arr[i]==elem) {
                    pos = i;
                    break;
                }
            }
            if(pos==-1){
                if(arr[rear]==elem){
                    return arr[rear];
                }
            }
        }else{
            cout<<"empty"<<endl;
        }
    }
    int getLength(){
        return length;
    }

};

int buyTicket(int * arr,int position, int arrSize){
    Queue<int>q;
    int posElement = arr[position];
    for(int i=0; i<arrSize;i++){
            q.addQueue(min(arr[i],posElement));
    }
    int sum=0;
    for(;!q.isEmpty();){
        sum+=q.getFront();
        q.deleteQueue();
    }
    return sum;
}
int main()
{
    int arr1[3]={2,3,2};
    int k=2;
    cout<<"tickets = [2,3,2], k = 2"<<endl;
    cout<<"Time= "<<buyTicket(arr1,k,3)<<endl;

    int arr2[4]={5,1,1,1};
    k=0;
    cout<<"tickets = [5,1,1,1], k = 0"<<endl;
    cout<<"Time= "<<buyTicket(arr2,k,4)<<endl;

}
