#include<iostream>
using namespace std;
class array
{
    private:
        int capacity;
        int lastindex=-1;
        int *arr;
    public:
        array(int);
        bool isEmpty();
        int isFull();
        int findEl(int);
        void append(int);
        void insert(int,int);
        void display();
        void edit(int,int);
        void delet(int);
        int cnt()
        {
            return lastindex+1;
        }
        int getElement(int index)
        {
            return arr[index];
        }
        ~array()
        {
            delete[]arr;
        }

};

        bool array :: isEmpty()
        {
            if(lastindex==-1)
                return true;
            else
                return false;
        }
        void array :: append(int element)
        {
            if(lastindex<capacity)
                arr[++lastindex]=element;
            else
                cout<<"array is full";
        }

        void array :: insert(int element,int index)
        {
            if(index>lastindex)
            {
                append(element);
            }
            else if(index<=lastindex)
            {
                for(int i=lastindex;i>=index;i--)
                {
                    arr[i+1]=arr[i];
                }
                arr[index]=element;
                if(lastindex<capacity)
                    lastindex++;
            }
        }
        void array :: display()
        {
            cout<<endl;
            for(int i=0;i<=lastindex;++i)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
        void array :: delet(int index)
        {
            if(index>lastindex)
                cout<<"position invalid"<<endl;
            else if(index==lastindex)
            {
                lastindex--;
            }
            else
            {
                for(int i=index;i<lastindex;++i)
                {
                    arr[i]=arr[i+1];
                }
                lastindex--;
            }
        }
        int array :: isFull()
        {
            if(lastindex==capacity)
                return 1;
            else
                return 0;
        }

        int array :: findEl(int element)
        {
            for(int i=0;i<lastindex;++i)
            {
                if(arr[i]==element)
                    return i;
            }
            return -1;
        }
        array::array(int size)
        {
            arr=new int[size];
            capacity=size-1;
        }
        void array::edit(int pos,int element)
        {
            arr[pos-1]=element;
        }
int main()
{
    array a(5);
    a.append(1);
    //a.append(2);
    //a.append(3);
    a.append(4);
    a.append(5);
    //a.delet(0);
    cout<<a.isFull();
    cout<<endl;
    //a.insert(10,2);
    //a.display();
    //a.edit(3,20);
    //a.append(6);
    cout<<a.getElement(2);
    a.display();
    cout<<"count:"<<a.cnt();
    cout<<endl<<a.findEl(40);
    return 0;
}
