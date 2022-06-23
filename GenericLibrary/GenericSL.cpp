// Singly Linear Linked List

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node * next;
};

template <class T>
class GenericSL
{
    private:
        int Count;
        struct node<T> * Head;

    public:
        GenericSL();
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
GenericSL<T>::GenericSL()
{
    Head = NULL;
    Count = 0;
}

template <class T>
void GenericSL<T>::InsertFirst(T No)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;

    newn -> data = No;
    newn -> next = NULL;

    if(Count == 0)
    {
        Head = newn;
    }
    else
    {
        newn -> next = Head;
        Head = newn;
    }

    Count++;

}

template <class T>
void GenericSL<T>::InsertLast(T No)
{
    struct node<T> *newn = NULL;

    newn = new struct node<T>;

    newn -> data = No;
    newn -> next = NULL;

    if(Count == 0)
    {
        Head = newn;
    }
    else
    {
        struct node<T> *temp = Head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    
    }

    Count++;
}

template <class T>
void GenericSL<T>::InsertAtPos(T No,int iPos)
{
    if((iPos < 1) || (iPos > (Count+1)))
    {
        cout << "Invalid Position !!" << endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == Count + 1)
    {
        InsertLast(No);
    }
    else
    {
        struct node<T> *temp = Head;
        struct node<T> *newn = NULL;

        newn = new struct node<T>;

        newn -> data = No;
        newn -> next = NULL;
        
        for(int i = 1; i < (iPos-1); i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;

        Count++;
    }

}

template <class T>
void GenericSL<T>::DeleteFirst()
{
    if(Count == 0)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct node<T> *temp = Head;
        Head = Head -> next;
        delete temp;
    }

    Count--;

}

template <class T>
void GenericSL<T>::DeleteLast()
{
    if(Count == 0)
    {
        return;
    }
    else if(Count == 1)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct node<T> *temp = Head;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;

    }

    Count--;

}

template <class T>
void GenericSL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > Count))
    {
        cout << "Invalid Position !!" << endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp = Head;
        struct node<T> *tempDelete = NULL;

        for(int i = 1; i < (iPos-1); i++)
        {
            temp = temp -> next;
        }

        tempDelete = temp -> next;

        temp -> next = tempDelete -> next;
        delete tempDelete;
        
        Count--;
    }

}

template <class T>
void GenericSL<T>::Display()
{
    struct node<T> *temp = Head;

    if(Count == 0)
    {
        cout << "Linked List is Empty!" << endl;
        return;
    }

    cout << endl;
    while(temp != NULL)
    {
        cout << "|" << temp -> data << "| -> ";
        temp = temp -> next;
    }

    cout << "NULL\n" << endl;
}

template <class T>
int GenericSL<T>::CountNode()
{
    return Count;
}


int main()
{
    GenericSL <int> obj1;
    GenericSL <float> obj2;
    GenericSL <char> obj3;

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