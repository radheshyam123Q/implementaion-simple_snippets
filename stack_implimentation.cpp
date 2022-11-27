#include <iostream>
#include <string>
using namespace std;

class stack
{
private:
    int top;
    int arr[5];

public:
    stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == 4)
            return true;
        else
            return false;
    }
    void push(int value)
    {
        if (isFull())
        {
            cout << "stack overflow";
        }
        else
        {
            top++;
            arr[top] = value;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow";
            return 0;
        }
        else
        {
            int pop_value = arr[top];
            arr[top] = 0;
            top--;
            return pop_value;
        }
    }
    int count()
    {
        return (top + 1);
    }
    int peek(int pos)
    {
        if (isEmpty())
        {
            cout << "stack underflow";
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }
    void change(int pos, int val)
    {
        arr[pos] = val;
        cout << "the value is changed at location " << pos << endl;
    }
    void display()
    {
        for (int i = 4; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    int option, value, position;
    stack s1;
    do
    {
        cout << "what operation do you want to perform select option number ,enter 0 to exit" << endl;
        cout << "1.push()" << endl;
        cout << "2.pop()" << endl;
        cout << "3.isEmpty()" << endl;
        cout << "4.isFull()" << endl;
        cout << "5.peek()" << endl;
        cout << "6.count()" << endl;
        cout << "7.change()" << endl;
        cout << "8.display()" << endl;
        cout << "9.clear screen" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "enter the item to push in stack " << endl;
            cin >> value;
            s1.push(value);
            break;
        case 2:
            cout << "pop function is called" << s1.pop() << endl;
            break;
        case 3:
            if (s1.isEmpty())
            {
                cout << "stack is empty" << endl;
            }
            else
            {
                cout << "stack is not full " << endl;
            }
            break;
        case 4:
            if (s1.isFull())
            {
                cout << "stack is full" << endl;
            }
            else
            {
                cout << "stack is not full" << endl;
            }
            break;

        case 5:
            cout << "enter the position for peek" << endl;
            cin >> position;
            cout << "peek function is called , the value at  " << position << " is " << s1.peek(position) << endl;
            break;
        case 6:
            cout << "count is called and the element in stack is " << s1.count();
            break;
        case 7:
            cout << "change function is called" << endl;
            cout << "enter the position of item you want to change" << endl;
            cin >> position;
            cout << "enter the value of item you want to change " << endl;
            cin >> value;
            s1.change(position, value);
            break;
        case 8:
            cout << "dislplay function is called " << endl;
            s1.display();
            break;
        case 9:
            system("cls");
            break;
        default:
            cout << "Enter the proper option number" << endl;
        }
    } while (option != 0);

    return 0;
}