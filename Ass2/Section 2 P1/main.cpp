#include <iostream>
using namespace std;

template<class type>
class List
{
private:
    struct node
    {
        type iteam;
        node * next;
        node *prev;
    };
    int length;
    node *head;
    node *tail;

public:

    List()
    {
        length = 0;
        head = tail = NULL;
    }
    List(type value, int initial_size)
    {
        length=0;
        node *newnode = new node;
        newnode->iteam = value;
        head = tail = newnode;
        length++;
        for(int i=1; i<initial_size; i++)
        {
            this->push_back(value);

        }
    }
    List<type>& operator = (List<type> &another_list)
    {
        length = 0;
        head = tail = NULL;
        Iterator it = another_list.Begin();
        for(int i=0; i<another_list.size(); i++)
        {
            this->push_back(it.current->iteam);;
            if(it.current->next != NULL)
            {
                it++;
            }
        }
        return *this;
    }
    void push_back(type value)
    {
        node *newnode = new node;
        node * dummy = new node;
        newnode->iteam = value;
        newnode->next = dummy;
        if(length==0)
        {
            head = tail = newnode;
        }
        else
        {
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
        }
        dummy->prev = tail;
        length++;
    }

    void InsertFirst(type value)
    {
        node *newnode = new node;
        newnode->iteam = value;
        if(length==0)
        {
            head = tail = newnode;
            newnode->next = new node;
        }
        else
        {
            newnode->next = head;
            newnode->prev = NULL;
            head->prev = newnode;
            head = newnode;
        }
        length++;
    }

    int size()
    {
        return length;
    }

    void deleteFirst()
    {
        if(length==0)
            cout<< "No item in the list"<<endl;
        else if(length==1)
        {
            delete head;
            head=tail=NULL;
        }
        else
        {
            node* cur = head;
            head=head->next;
            delete cur;
        }
        length = length-1;

    }
    void deleteLast()
    {
        if(length==0)
            cout<< "No item in the list"<<endl;
        else if(length==1)
        {
            delete head;
            head=tail=NULL;
        }
        else
        {
            node* pretail = tail;
            tail->prev->next = tail->next;
            tail = tail->prev;
            delete pretail;
        }
        length = length-1;
    }
    void print()
    {
        node* cur = head;
        for(int i=0; i< length; i++)
        {
            cout<< cur->iteam << " ";
            cur = cur->next;
        }
    }

    class Iterator
    {
    private:
        node *current;

    public:
        Iterator()
        {
            current = NULL;
        }
        Iterator(node*another_current)
        {
            current = another_current;
        }
        void operator ++ ()
        {
            if(current->next == NULL )
            {
                throw "this is out of range no elements after";
            }
            else
            {
                current = current->next;
            }

        }
        void operator ++ (type)
        {
            if(current->next == NULL )
            {
                throw "this is out of range no elements after";

            }
            else
            {
                current = current->next;
            }
        }
        void operator -- ()
        {
            if(current->prev == NULL )
            {
                throw "this is out of range no elements before";
            }
            else
            {
                current = current->prev;
            }
        }
        void operator -- (type)
        {
            if(current->prev == NULL )
            {
                throw "this is out of range no elements before";
            }
            else
            {
                current = current->prev;
            }
        }
        type& operator * ()
        {
            return current->iteam;
        }
        bool operator == (const Iterator & another)
        {
            if(current == another.current)
            {
                return true;
            }
            return false;
        }
        bool operator != (const Iterator & another)
        {
            if(current != another.current)
            {
                return true;
            }
            return false;
        }
        friend class List;
    };

    void Insert(type value, Iterator position)
    {
        List::Iterator currentit = this->Begin();
        int flag=0;
        if(position.current->prev == NULL)
        {
            InsertFirst(value);
        }
        else if(position.current->next == NULL)
        {
            push_back(value);
        }
        else
        {
            while(flag == 0)
            {
                if(position == currentit)
                {
                    position--;
                    node *newnode = new node;
                    newnode->iteam = value;
                    newnode->next = position.current->next;
                    newnode->prev = position.current;
                    position.current->next = newnode;
                    length++;
                    currentit++;
                    flag=1;
                }
                else
                {
                    currentit++;
                }
            }
        }
    }
    Iterator Erase(Iterator position)
    {
        if(position.current == head)
        {
            position++;
            deleteFirst();
            return position;
        }
        else if(position.current->prev == tail)
        {
            position--;
            deleteLast();
            return position;
        }
        else
        {
            node *deleteNode = position.current;
            deleteNode->prev->next = deleteNode->next;
            deleteNode->next->prev = deleteNode->prev;
            List::Iterator currentit = position;
            ++currentit;
            if (deleteNode == tail)
                tail = currentit.current;
            delete deleteNode;
            length--;
            return currentit;
        }

    }
    Iterator Begin()
    {
        return Iterator(head);
    }
    Iterator End()
    {
        return Iterator(tail->next);
    }
    ~List()
    {
        while(head != NULL && head != tail->next)
        {
            node* curr = head;
            node* nextToDelete = curr->next;
            head = nextToDelete;
            delete curr;
        }
    }
    void sortList()
    {
        node *index = NULL;
        type temp;
        Iterator it2 = this->Begin();
        if(head == NULL)
        {
            return;
        }
        else
        {
            for(; it2.current->next != NULL; it2++)
            {
                for(index = it2.current->next; index->next != NULL; index = index->next)
                {
                    if(*it2 > index->iteam)
                    {
                        temp = *it2;
                        *it2 = index->iteam;
                        index->iteam = temp;
                    }
                }
            }
        }
    }
};
template <class type>
void mergelist(List <type>&li,List <type>&another_list)
{
    typename List<type>::Iterator it2 = another_list.Begin();
    for(int i=0; i<another_list.size(); i++,it2++)
    {
        li.push_back(*it2);
    }
    li.sortList();
    remoDub(li);
}
template <class type>
void remoDub(List<type>&li)
{
    typename List<type>::Iterator it = li.Begin();
    typename List<type>::Iterator itest = li.Begin();
    itest++;
    int m =li.size();
    for(int i=0; i < m-1; i++)
    {

        if(*it == *itest)
        {
            itest = li.Erase(itest);
        }
        else
        {
            it = itest;
            itest++;
        }
    }
}
int main()
{
    List <int>list1(3,5);
    list1.InsertFirst(6);
    list1.push_back(9);

    list1.print();
    cout<<endl;
    List<int>::Iterator iter = list1.End();
    iter--;
    list1.Insert(7,iter);

    list1.print();
    cout<<endl;
    cout<<endl;

    List<int> test;
    test.InsertFirst(6);
    test.InsertFirst(7);
    test.InsertFirst(9);
    test.push_back(10);
    test.print();
    cout<<endl;

    test.deleteFirst();
    test.print();
    cout<<endl;

    List<int>::Iterator iter1 = test.Begin();
    iter1++;
    iter1 = test.Erase(iter1);
    test.print();
    cout<<endl;
    iter1++;
    test.Erase(iter1);

    test.print();
    cout<<endl;
    cout<<endl;


    List<int> merg1;
    merg1.push_back(1);
    merg1.push_back(2);
    merg1.push_back(3);
    merg1.push_back(5);
    merg1.push_back(6);
    merg1 .print();
    cout<<endl;
    List<int> merg2;
    merg2.push_back(2);
    merg2.push_back(2);
    merg2.push_back(4);
    merg2.push_back(5);
    merg2.push_back(6);
    merg2.push_back(7);
    merg2 .print();
    cout<<endl;
    cout<<endl;

    mergelist(merg1, merg2);
    merg1.print();
    return 0;

}
