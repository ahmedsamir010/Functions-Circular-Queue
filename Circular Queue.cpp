#include<iostream>
using namespace std;
#define maxsize 100
class circ {
private:
    int front, rear, arr[maxsize];
public:
    circ() { front = -1, rear = -1; }
    void insert(int value);
    int remove();
    bool isFull();
    bool isEmpty();
    void display();
};
int main()
{
    circ c;
    c.insert(10);
    c.insert(20);
    c.display();
    c.remove();
    c.display();
    return 0;
}

void circ::insert(int value)
{
    if (isFull()) {
        cout << "Circ is Full ";
    }
    if (front == -1 and rear == -1) {
        front = 0, rear = 0;
    }
    else {
        if (rear == maxsize - 1)
            rear = 0;
        else
            rear++;
    }
    arr[rear] = value;
}
int circ::remove()
{
    int temp = arr[front];
    if (isEmpty()) {
        cout << "Circ is Empty" << endl;exit(-1);
    }
        if (front == rear) 
        {// one Element
            rear = -1, front = -1;exit(-1);
        }
        if(front == maxsize - 1)
            front = 0;
        else
            front++;
    return temp;
}
bool circ::isFull()
{
    if ((front == 0 and rear == maxsize - 1) or (front == rear + 1))return true;
    return false;
}

bool circ::isEmpty()
{
    if (front = -1 and rear == -1)return true;
    return false;
}

void circ::display()
{
    if (front <= rear) {
        for (int i = front;i <= rear;i++) {
            cout << arr[i] << "\t";
        }
    }
    else {
        for (int i = front;i < maxsize;i++) {
            cout << arr[i] << "\t";
        }
        for (int i = 0;i <= rear;i++) {
            cout << arr[i] << "\t";
        }
    }
}

