#include<iostream>
using namespace std;
#define maxsize 100
int top = -1;
class stack {
private:
    int arr[maxsize];
public:
    bool isFull();
    bool isEmpty();
    void push(int value);
    int pop();
    int peek();
    void display();
    double exp(string x);
};

int main()
{
    stack s;string z;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();//10   20   30  40   50
    s.pop();
    s.display();
    cout << "Peek" << s.peek() << endl;
   // infix to PostFix
  //  cout<<"Please Enter "
    cin >> z;
    cout << s.exp(z);
    return 0;
}

bool stack::isFull()
{
    if (top == maxsize - 1)return true;
    return false;
}

bool stack::isEmpty()
{
    if (top == -1)return true;
    return false;
}

void stack::push(int value)
{
    if (isFull()) {
        cout << "Stack is Over Flow" << endl;
        exit(-1);
    }
    else {
        top++;
        arr[top] = value;
    }
}

int stack::pop()
{
    if (isEmpty()) {
        cout << "Stack is Under Flow" << endl;
    }
    else {
        return arr[top--];
    }
}

int stack::peek()
{
    if (isEmpty()) {
        cout << "Stack is Under Flow" << endl;
    }
    else {
        return arr[top];
    }
}

void stack::display()
{
    if (isEmpty()) {
        cout << "Stack is Empty" << endl;
    }
    else {
        for (int i = top;i >= 0;i--) {
            cout << arr[i] << "\t";
        }
    }
}

double stack::exp(string x)
{
    stack s;float op1, op2, val;
    for (int i = 0;i < x.size();i++) {
        if (isdigit(x[i])) {
            s.push(x[i] - 48);
        }
        else {
            op2 = s.pop();
            op1 = s.pop();
            switch (x[i]) {
            case '+':
                val = op2 + op1;
                break;
            case '-':
                val = op1 - op2;
                break;
            case '*':
                val = op2 * op1;
                break;
            case '/':
                val = op1 / op2;
                break;
            case '^':
                val = pow(op1, op2);
            }
            s.push(val);
        }
    }
    return s.pop();
}