/////////////////		Stack - Uses LIFO	     /////////////////

#include<iostream.h>
#include<conio.h>

//		NODE		//

template <class T> class node
{
  public:
	T info;
	node<T> *next;

  node(T data, node<T> *ptr = '\0')
	{
	  info = data;
	  next = ptr;
	}
};

//		LIST CLASS		//

template <class T> class stack
{
	node<T> *head, *tail;
  public:
	stack()
	{
	  head = '\0';
	  tail = '\0';
	}

	void push(T);
	void pop();
	void displayList();

};

/////////////////////////////////////////

template <class T>
void stack<T>::push(T val)
{
  if(head != '\0')
  {
    tail->next = new node<T>(val);
    tail = tail->next;
  }
  else
    head = tail = new node<T>(val);
}

/////////////////////////////////////////

template <class T>
void stack<T>::pop()
{
  if(head != '\0')
  {
    if(head == tail)
      head = tail = '\0';
    else
    {
      node<T> *temp;
      for(temp = head; temp->next!=tail; temp = temp->next);
      cout<<"\nDeleting: "<<tail->info;
      tail = temp;
      tail->next = '\0';
      cout<<"\nDeleted!!";
    }
  }
  else
	cout<<"\nList Underflow!!";
}

/////////////////////////////////////////

template <class T>
void stack<T>::displayList()
{
  if(head != '\0')
  {
	cout<<"\nList is:- \n";
	for(node<T> *temp = head; temp!='\0'; temp=temp->next)
	{
	    cout<<temp->info<<"  ->  ";
	}
	cout<<"NULL";
  }
  else
	cout<<"\nList Underflow!!";
}

//-------------------------------------//

/*   	    THE MAIN FUNCTION	       */

//-------------------------------------//

void main()
{
  clrscr();
    int choice, x;
	stack<int> ls;
	char ch;
  here:
	clrscr();
	  cout<<"\nMENU:- \n"
	      <<"\n1) Push"
	      <<"\n2) Pop"
	      <<"\n3) Display\n\n";
	  cin>>choice;
	switch(choice)
	{
		case 1:  clrscr();
				 cout<<"\nEnter data: ";
				 cin>>x;
				 ls.push(x);
				 break;

		case 2:  clrscr();
				 ls.pop();
				 break;

		case 3:  clrscr();
				 ls.displayList();
				 break;

		default: "\nInvalid input!!";
	}

  cout<<"\n\nWanna try again??"
      <<"\nHit 'Y', else any other key: ";
  cin>>ch;

  if(ch == 'y' || ch == 'Y')
    goto here;
}