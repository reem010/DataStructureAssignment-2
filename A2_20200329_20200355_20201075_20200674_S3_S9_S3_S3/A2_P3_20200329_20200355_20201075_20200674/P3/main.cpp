#include<bits/stdc++.h>
using namespace std;
template<class T>
class Node
{
public:
    T data;
    Node* next;
    Node* prev;
    Node() { next = NULL; prev = NULL; }
    Node(T _data) { next = NULL; prev = NULL; data = _data; }
};
template<class T>
class List
{
public:
    Node<T>* head;
    Node<T>* tail;
    int sz; // size of the list
    List() :sz(0) {

        // dummy node
        Node<T>* temp = new Node<T>();

        //pointing the tail to the dummy node
        tail = temp;
        tail->prev = head;
        head = tail;
    }
    List(T val, int _size) :sz(_size)
    {
        // dummy node
        Node<T>* temp = new Node<T>();

        //pointing the tail to the dummy node
        tail = temp;
        tail->prev = head;
        head = tail;

        // how many nodes we need to create
        int nodes = sz;
        while (nodes--)
        {
            Node<T>* temp = new Node<T>(val);

            //insertion from front -> we link between the new node and the head which points to tail(dummy node) and after the link we move the head 1 step backward
            temp->next = head;
            head->prev = temp;

            //moving the head after the link is done
            head = temp;
        }
    }
    ~List()
    {
        // deleting the dummy node
        delete tail;
    }
    void push_front(T value)
    {
        Node<T>* temp = new Node<T>(value);

        //insertion from front -> we link between the new node and the head which at first it points to tail(dummy node) and after the link we move the head 1 step backward
        temp->next = head;
        head->prev = temp;

        //moving the head after the link is done
        head = temp;
        sz++;
    }

    void pop_back()
    {
        if (sz == 1) {
            delete head;
            head = tail;
            tail->prev = NULL; // avoiding dangling pointers
        }
        else
        {
            // the tail points to the dummy and we don't wanna to delete the dummy we want to delete the node before it
            Node<T>* deleteNode = tail->prev;

            deleteNode->prev->next = tail;  // link between the node before the node we want to delete and the tail node(the dummy node)
            tail->prev = deleteNode->prev;

            delete deleteNode; // finally we delete the node
        }
        sz--;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        return (sz == 0);
    }
    void print()
    {
        Node<T>* temp = head;
        // we don't wanna to print the tail node because it's the dummy node
        while (temp != tail)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }cout << endl;
    }
};

template<class T>
class Queue
{
    List<T>list;
public:
    int size()
    {
        return list.size();
    }
    bool empty()
    {
        return list.empty();
    }
    T front()
    {
        if (!empty())
        {
            return (list.tail->prev->data);
        }
        throw"Empty Queue";
    }
    void pop()
    {
        if (!list.empty())
            list.pop_back();
    }
    void push(T val)
    {
        list.push_front(val);
    }
};

class Stack {
private:
    Queue<int> q;
public:
    int top() {
        return q.front();
    }

    void pop() {
        if (!q.empty())
            return q.pop();

    }
    void push(int val) {
        q.push(val);
        int t = q.size() - 1;
        while (t--) {
            q.push(q.front());
            q.pop();
        }
    }
};
int main() {
    Stack sk;
    sk.push(45);
    sk.push(123);
    sk.push(11);
    cout << sk.top() << endl;
    sk.pop();
    cout << sk.top() << endl;

}


