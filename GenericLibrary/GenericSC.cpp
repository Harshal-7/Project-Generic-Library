// Singly Circular Linked List

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class GenericSC
{
    private:
        int Count;
        struct node<T> *Head;
        struct node<T> *Tail;

    public:
        GenericSC();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int CountNode();
};

template <class T>
GenericSC<T>::GenericSC()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

template <class T>
void GenericSC<T>::InsertFirst(T No)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;

    newn->data = No;
    newn->next = NULL;

    if(Count == 0)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }

    Tail->next = Head;

    Count++;

}

template <class T>
void GenericSC<T>::InsertLast(T No)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;

    newn->data = No;
    newn->next = NULL;

    if(Count == 0)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        Tail = Tail->next;
    }

    Tail->next = Head;

    Count++;

}

template <class T>
void GenericSC<T>::InsertAtPos(T No,int iPos)
{
    int iSize = 0;
    iSize = CountNode();

    if((iPos < 1) || (iPos > iSize + 1))
    {
        cout << "Invalid Position!!" << endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iSize + 1)
    {
        InsertLast(No);
    }
    else
    {
        struct node<T> *temp = Head;
        struct node<T> *newn = NULL;

        newn = new struct node<T>;

        newn->data = No;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        Count++;

    }
}

template <class T>
void GenericSC<T>::DeleteFirst()
{
    if(Count == 0)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Tail->next;
        Tail->next = Head;
    }

    Count--;

}

template <class T>
void GenericSC<T>::DeleteLast()
{
    if(Count == 0)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        struct node<T> *temp = Head;

        while(temp->next != Tail)
        {
            temp = temp->next;
        }

        delete Tail;
        Tail = temp;
        Tail->next = Head;
    }

    Count--;

}

template <class T>
void GenericSC<T>::DeleteAtPos(int iPos)
{
    int iSize = 0;
    iSize = CountNode();

    if((iPos < 1) || (iPos > iSize))
    {
        cout << "Invalid Position!!" << endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iSize)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp = Head;

        for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp->next;
        }

        struct node<T> *tempX = temp->next;

        temp->next = tempX->next;
        delete tempX;

        Count--;
        
    }

}

template <class T>
void GenericSC<T>::Display()
{
    struct node<T> *temp = Head;

    if(Count == 0)
    {
        cout << "Linked List is Empty!!" << endl;
        return;
    }

    cout << endl;

    do
    {
        cout << "|" << temp->data << "| - ";
        temp = temp->next;
    }while(temp!=Head);

    cout << endl;

}

template <class T>
int GenericSC<T>::CountNode()
{
    return Count;
}

int main()
{
    GenericSC <int> obj1;
    GenericSC <float> obj2;
    GenericSC <char> obj3;

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

            cout << "1 : Insert First" << endl;
            cout << "2 : Insert Last" << endl;
            cout << "3 : Insert At Position" << endl;
            cout << "4 : Delete First" << endl;
            cout << "5 : Delete Last" << endl;
            cout << "6 : Delete At Position" << endl;
            cout << "7 : Display" << endl;
            cout << "8 : Count Nodes" << endl;
            cout << "9 : Terminate The Application" << endl;

            cin >> iChoise;
            
            switch(iChoise)
            {
                case 1:
                    cout << "\nEnter First Value : " << endl;
                    cin >> iValue;
                    obj1.InsertFirst(iValue);
                    break;

                case 2:
                    cout << "\nEnter Last Value : " << endl;
                    cin >> iValue;
                    obj1.InsertLast(iValue);
                    break;
                
                case 3:
                    cout << "\nEnter First Value : " << endl;
                    cin >> iValue;
                    cout << "\nEnter Position : " << endl;
                    cin >> iPos;
                    obj1.InsertAtPos(iValue,iPos);
                    break;
                
                case 4:
                    obj1.DeleteFirst();
                    break;
                
                case 5:
                    obj1.DeleteLast();
                    break;
                
                case 6:
                    cout << "\nEnter Posotion : " << endl;
                    cin >> iPos;
                    obj1.DeleteAtPos(iPos);
                    break;
                
                case 7:
                    obj1.Display();
                    break;
                
                case 8:
                    iRet = obj1.CountNode();
                    cout << "\nNumber of Nodes : " << iRet << endl;
                    break;

                case 9:
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

            cout << "1 : Insert First" << endl;
            cout << "2 : Insert Last" << endl;
            cout << "3 : Insert At Position" << endl;
            cout << "4 : Delete First" << endl;
            cout << "5 : Delete Last" << endl;
            cout << "6 : Delete At Position" << endl;
            cout << "7 : Display" << endl;
            cout << "8 : Count Nodes" << endl;
            cout << "9 : Terminate The Application" << endl;

            cin >> fChoise;
            
            switch(fChoise)
            {
                case 1:
                    cout << "\nEnter First Value : " << endl;
                    cin >> fValue;
                    obj2.InsertFirst(fValue);
                    break;

                case 2:
                    cout << "\nEnter Last Value : " << endl;
                    cin >> fValue;
                    obj2.InsertLast(fValue);
                    break;
                
                case 3:
                    cout << "\nEnter First Value : " << endl;
                    cin >> fValue;
                    cout << "\nEnter Position : " << endl;
                    cin >> iPos;
                    obj2.InsertAtPos(fValue,iPos);
                    break;
                
                case 4:
                    obj2.DeleteFirst();
                    break;
                
                case 5:
                    obj2.DeleteLast();
                    break;
                
                case 6:
                    cout << "\nEnter Posotion : " << endl;
                    cin >> iPos;
                    obj2.DeleteAtPos(iPos);
                    break;
                
                case 7:
                    obj2.Display();
                    break;
                
                case 8:
                    iRet = obj2.CountNode();
                    cout << "\nNumber of Nodes : " << iRet << endl;
                    break;

                case 9:
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

            cout << "1 : Insert First" << endl;
            cout << "2 : Insert Last" << endl;
            cout << "3 : Insert At Position" << endl;
            cout << "4 : Delete First" << endl;
            cout << "5 : Delete Last" << endl;
            cout << "6 : Delete At Position" << endl;
            cout << "7 : Display" << endl;
            cout << "8 : Count Nodes" << endl;
            cout << "9 : Terminate The Application" << endl;

            cin >> iChoise;
            
            switch(iChoise)
            {
                case 1:
                    cout << "\nEnter First Value : " << endl;
                    cin >> cValue;
                    obj3.InsertFirst(cValue);
                    break;

                case 2:
                    cout << "\nEnter Last Value : " << endl;
                    cin >> cValue;
                    obj3.InsertLast(cValue);
                    break;
                
                case 3:
                    cout << "\nEnter First Value : " << endl;
                    cin >> cValue;
                    cout << "\nEnter Position : " << endl;
                    cin >> iPos;
                    obj3.InsertAtPos(cValue,iPos);
                    break;
                
                case 4:
                    obj3.DeleteFirst();
                    break;
                
                case 5:
                    obj3.DeleteLast();
                    break;
                
                case 6:
                    cout << "\nEnter Posotion : " << endl;
                    cin >> iPos;
                    obj3.DeleteAtPos(iPos);
                    break;
                
                case 7:
                    obj3.Display();
                    break;
                
                case 8:
                    iRet = obj3.CountNode();
                    cout << "\nNumber of Nodes : " << iRet  << endl;
                    break;

                case 9:
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