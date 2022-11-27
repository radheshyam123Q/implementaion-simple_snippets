#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    int data;
    Node *next;
    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};
class Singlylinkedlist
{
public:
    Node *head;

    Singlylinkedlist()
    {
        head = NULL;
    }
    Singlylinkedlist(Node *n)
    {
        head = n;
    }
    // first op-eration
    Node *nodeExist(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    void appendNode(Node *n)
    {
        if (nodeExist(n->key) != NULL)
        {
            cout << "node already exist with key value" << n->key << "use another key" << endl;
        }
        else
        {
            if (head = NULL)
            {
                head = n;
                cout << "Node is appended" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node is appended" << endl;
            }
        }
    }

    // prepend node code
    void prependNode(Node *n)
    {
        if (nodeExist(n->key) != NULL)
        {
            cout << "node already exist with key value" << n->key << "use another key" << endl;
        }
        else
        {
            n->next = head;
            head = n;
        }
    }

    // inserting a node between node
    void insertNodeAfter(int k, Node *n)
    {

        Node *ptr = nodeExist(k);
        if (ptr == NULL)
        {
            cout << "no node exit with key value" << k << endl;
        }
        else
        {
            if (nodeExist(n->key) != NULL)
            {
                cout << "node already exist with key value" << n->key << "use another key" << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "Node inserted" << endl;
            }
        }
    }
    // delete node by unique id
    void deleteNodeBykey(int k)
    {
        if (head == NULL)
        {
            cout << "singly linked list already empty . cant delete" << endl;
        }
        else if (head != NULL)
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Node unlinked with keys values " << k << endl;
            }
            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next;
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }

                if (temp != NULL)
                {
                    prevptr->next = temp->next;
                    cout << "Node Unlinked with the key value" << k << endl;
                }
                else
                {
                    cout << "Node dosent exist with the key value" << k << endl;
                }
            }
        }
    }
    // update node
    void updateNodeByKey(int k, int d)
    {
        Node *ptr = nodeExist(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node data Updated successfully" << endl;
        }
        else
        {
            cout << "Node Doesn't with the key value  " << endl;
        }
    }
    // printing all the element
    void Printlist()
    {
        if (head == NULL)
        {
            cout << "No Node in Singly Linked List";
        }
        else
        {
            cout << endl
                 << "singly Linked List values : ";
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ") -->";
                temp = temp->next;
            }
        }
    }
};
int main()
{
    Singlylinkedlist s ;
    int option ;
     int key1 , k1, data1 ; 
     do
    {
        cout << "what operation do you want to perform select option number ,enter 0 to exit" << endl;
        cout << "1.appendnode()" << endl;
        cout << "2.prependnode()" << endl;
        cout << "3.insertnodeafter()" << endl;
        cout << "4.deletenodebykey()" << endl;
        cout << "5.updatenodebykey()" << endl;
        cout << "6.print()" << endl;
        cout << "7.clear screen" << endl;
        cin >> option;
        Node* n1 = new Node();
        switch (option)
        {
        case 0:  
            break;
        case 1 :
            cout<<"append node operation \n enter key & data of the node to be appened "<<endl ;
            cin>>key1 ;
            cin>>data1 ;
            n1->key = key1 ;  
            n1->data = data1 ;
            s.appendNode(n1);
            break; 
        case 2 :  
            cout<<"prepend node operation \n enter key & data of the node to be appended"<<endl;
            cin>>key1 ; 
            cin>>data1;
            n1->key = key1 ;  
            n1->data = data1 ;
            s.prependNode(n1);
            break;
        case 3 : 
            cout<<"Insert Node after operation \n enter the key of existing node after which you want to insert this new code "<< endl ;
            cin>>key1 ; 
            cin>>data1;
            n1->key = key1 ;  
            n1->data = data1 ;
            s.insertNodeAfter(k1,n1) ;
            break; 
        case 4 :  
            cout<<"Delete Node By Key Operation - \nenter key of the node to be deleted : "<<endl;
            cin>>k1;
            s.deleteNodeBykey(k1);
            break; 
        case 5 : 
            cout<<"Update Node By Key - \nenter key & NEw data to be  updated"<<endl ;
            cin>>key1 ; 
            cin>>data1;
            s.updateNodeByKey(key1,data1) ;
            break;
        case 6 : 
            s.Printlist();
            break; 
        case 7 : 
           system("cls");
           break;
        default : 
          cout<<"Enter proper opton number "<<endl;
        }
    }while (option!=0);
    
    


    return 0;
}