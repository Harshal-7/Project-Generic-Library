// Stack in Generic

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class Stack
{
    private:
        struct node<T> *Head;
        int Count;

    public:
        Stack();
        void Push(T);
        void Pop();
        void Display();
        int CountNode();
};

template <class T>
Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}

template <class T>
void Stack<T>::Push(T No)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;

    newn->data = No;
    newn->next = NULL;

    if(Count == 0)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }

    Count++;

}

template <class T>
void Stack<T>::Pop()
{
    T Value;

    if(Count == 0)
    {
        return;
    }
    
    Value = Head->data;
    struct node<T> *temp = Head;

    Head = Head->next;
    delete temp;
    temp = NULL;

    Count--;

    cout << "\nRemoved Element is : " << Value << endl;

}

template <class T>
void Stack<T>::Display()
{
    struct node<T> *temp = Head;

    if(Count == 0)
    {
        cout << "\nStack is Empty!" << endl;
        return;
    }
    cout << endl;

    while(temp != NULL)
    {
        cout << "|" << temp->data << "|  ";
        temp = temp->next;
    }

    cout << endl;

}

template <class T>
int Stack<T>::CountNode()
{
    return Count;
}

int main()
{
    Stack <int> obj1;
    Stack <float> obj2;
    Stack <char> obj3;

    int iOpr = 0;
    int iValue = 0,iPos = 0,iRet = 0;
    float fValue = 0.0;
    char cValue = '\0';

    cout << "\n Choose the Operation : " << endl;
    cout << "1 : Integer" << endl;
    cout << "2 : Float" << endl;
    cout << "3 : Character" << endl;

    cin >> iOpr;
    
    if(iOpr == 1)
    {
        int iChoise = 1;
    
        while(iChoise != 0)
        {
            
            cout << "\nEnter Your Choise : " << endl; 

            cout << "1 : Push" << endl;
            cout << "2 : Pop" << endl;
            cout << "3 : Display" << endl;
            cout << "4 : Count Nodes" << endl;
            cout << "5 : Terminate The Application" << endl;

            cin >> iChoise;
            
            switch(iChoise)
            {
                case 1:
                    cout << "\nEnter First Value : " << endl;
                    cin >> iValue;
                    obj1.Push(iValue);
                    break;
                
                case 2:
                    obj1.Pop();
                    break;
                
                case 3:
                    obj1.Display();
                    break;
                
                case 4:
                    iRet = obj1.CountNode();
                    cout << "\nNumber of Elements in Stack: " << iRet << endl;
                    break;

                case 5:
                    cout << "\nThankyou For Using The Application\n" << endl;
                    iChoise = 0;
                    break;

                default:
                    cout << "\nPlease Enter The Correct Choise !!" << endl;

            }
        }
    }
    else if(iOpr == 2)
    {
        int fChoise = 1;
    
        while(fChoise != 0)
        {
            
            cout << "\nEnter Your Choise : " << endl; 

            cout << "1 : Push" << endl;
            cout << "2 : Pop" << endl;
            cout << "3 : Display" << endl;
            cout << "4 : Count Nodes" << endl;
            cout << "5 : Terminate The Application" << endl;

            cin >> fChoise;
            
            switch(fChoise)
            {
                case 1:
                    cout << "\nEnter First Value : " << endl;
                    cin >> fValue;
                    obj2.Push(fValue);
                    break;
                
                case 2:
                    obj2.Pop();
                    break;
                
                case 3:
                    obj2.Display();
                    break;
                
                case 4:
                    iRet = obj2.CountNode();
                    cout << "\nNumber of Elements in Stack: " << iRet << endl;
                    break;

                case 5:
                    cout << "\nThankyou For Using The Application\n" << endl;
                    fChoise = 0;
                    break;

                default:
                    cout << "\nPlease Enter The Correct Choise !!" << endl;

            }
        }
    }
    else if(iOpr == 3)
    {
        int iChoise = 10;
    
        while(iChoise != 0)
        {
            
            cout << "\nEnter Your Choise : " << endl; 

            cout << "1 : Push" << endl;
            cout << "2 : Pop" << endl;
            cout << "3 : Display" << endl;
            cout << "4 : Count Nodes" << endl;
            cout << "5 : Terminate The Application" << endl;

            cin >> iChoise;
            
            switch(iChoise)
            {
                
                case 1:
                    cout << "\nEnter First Value : " << endl;
                    cin >> cValue;
                    obj3.Push(cValue);
                    break;
                
                case 2:
                    obj3.Pop();
                    break;
                
                case 3:
                    obj3.Display();
                    break;
                
                case 4:
                    iRet = obj3.CountNode();
                    cout << "\nNumber of Elements in Stack: " << iRet << endl;
                    break;

                case 5:
                    cout << "\nThankyou For Using The Application\n" << endl;
                    iChoise = 0;
                    break;

                default:
                    cout << "\nPlease Enter The Correct Choise !!" << endl;

            }
        }

    }
    else
    {
        cout << "\nInvalid Choise!\n" << endl;
    }

    return 0;

}