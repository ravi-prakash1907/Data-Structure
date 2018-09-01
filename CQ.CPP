// Header Files section
#include<iostream.h>
#include<conio.h>

template<class T>  class queue
{
	int rear, front;
	int size;
	int *arr;
  
  public:
	queue(int s)
    {
       front = rear = -1;
       size = s;
       arr = new int[s];
    }

void enqueue(int value);
void dequeue();
void traversal();
};


template<class T>
void queue<T>::enqueue(int value)
{
    if ((front == 0 && rear == size-1) ||
            (rear == (front-1)%(size-1)))
    {
        cout<<"\nQueue is Full";
        return;
    }
 
    else if (front == -1)
    {
        front = rear = 0;
        arr[rear] = value;
    }
 
    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }
 
    else
    {
        rear++;
        arr[rear] = value;
    }
}


template <class T>
void queue<T>::dequeue()
{
    if (front == -1)
    {
        cout<<"\nQueue is Empty";
        return INT_MIN;
    }
 
    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;
 
    cout<<"\nDeleting: "<<data;
}

template <class T>
void queue<T>::traversal()
{
    if (front == -1)
    {
        cout<<"\nQueue is Empty";
        return;
    }
    cout<<"\nElements in Circular Queue are: ";
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout<<arr[i];
    }
    else
    {
        for (int i = front; i < size; i++)
            cout<< arr[i];
 
        for (int i = 0; i <= rear; i++)
            cout<< arr[i];
    }
}

void main()
{
clrscr();
   int choice, x;
	
	cout<<"\nEnter the max. size of the queue: ";
	cin>>x;
	
	list<int> que;
	char ch;
  here:
	clrscr();
	  cout<<"\nMENU:- \n"
	      <<"\n1) Add"
	      <<"\n2) Delete"
	      <<"\n3) Display\n\n";
	  cin>>choice;
	switch(choice)
	{
		case 1:  clrscr();
				 cout<<"\nEnter data: ";
				 cin>>x;
				 que.enqueue(x);
				 break;

		case 2:  clrscr();
				 cout<<"\nEnter data: ";
				 cin>>x;
				 que.dequeue(x);
				 break;

		case 3:  clrscr();
				 que.traversal();
				 break;

		default: "\nInvalid input!!";
	}

  cout<<"\n\nWanna try again??"
      <<"\nHit 'Y', else any other key: ";
  cin>>ch;

  if(ch == 'y' || ch == 'Y')
    goto here;

}
