////////////////	      CIRCULAR LINKED LIST	       ///////////////

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

template <class T> class list
{
	node<T> *head, *tail;
  public:
	list()
	{
	  head = '\0';
	  tail = '\0';
	}

	void addToHead(T);
	void addToTail(T);
	void delFromHead();
	void delFromTail();
	void addNodeAtPos(T, T);
	int search(T val);
	void delNodeFromPos(T);
	void reverse();
	void displayList();

};

/////////////////////////////////////////

template <class T>
void list<T>::addToHead(T val)
{
  if(head == '\0')
  {
    head = new node<T>(val, head);
    head->next = head;
  }
  else
    head = new node<T>(val, head);

  if(tail == '\0')
    tail = head;
}

/////////////////////////////////////////

template <class T>
void list<T>::addToTail(T val)
{
  if(head != '\0')
  {
    tail->next = new node<T>(val, head);
    tail = tail->next;
  }
  else
  {
    head = tail = new node<T>(val);
    tail->next = head;
    head->next = tail;
  }
}

/////////////////////////////////////////

template <class T>
void list<T>::addNodeAtPos(T pos, T val)
{
  if((head != '\0')||(pos == 1))
  {
    node<T> *temp;
    int c;

    if(pos == 1)
    {
      addToHead(val);		// Adds new node to head
      return;
    }
    else
    temp = head;
    c = 1;

    do
    {
      if(c+1 == pos)
      {
	 if(temp != tail)
	 {
	   temp->next = new node<T>(val, temp->next);		// adds new node having info part = val and next = temp->next
	   return;
	 }
	 else
	 {
	    addToTail(val);
	    return;
	 }
      }
      temp=temp->next;
      c++;

    }while(temp!=head);

    cout<<"Invalid position !";
  }
  else
    cout<<"\nList is empty!!";
}

/////////////////////////////////////////

template <class T>
void list<T>::delFromHead()
{
  if(head != '\0')
  {
     node<T> *temp;// = head;

     if(head == tail)
     {
	temp = head;
	cout<<"\nDeleting: "<<temp->info;
	head = '\0';
	tail = '\0';
	cout<<"\nDeleted!!";
     }
     else if(head->next == tail)
     {
	temp = head;
	cout<<"\nDeleting: "<<temp->info;
	head = tail;
	cout<<"\nDeleted!!";
	tail->next = head;
     }
     else
     {
	temp = head;
	cout<<"\nDeleting: "<<temp->info;
	head = head->next;
	tail->next = head;
	cout<<"\nDeleted!!";
     }

     delete temp;
  }
  else
	cout<<"\nList is empty!!";
}

/////////////////////////////////////////

template <class T>
void list<T>::delFromTail()
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
      tail->next = head;
    }

    cout<<"\nDeleted!!";
  }
  else
	cout<<"\nList is empty!!";
}

/////////////////////////////////////////

template <class T>
void list<T>::delNodeFromPos(T pos)
{


 if(head != '\0')
  {
    node<T> *temp;
    int c;

    if(pos == 1)
    {
      delFromHead();		// Adds new node to head
      return;
    }
    else
    temp = head;
    c = 1;

    do
    {
      if(c+1 == pos)
      {
	 if(temp->next != tail)
	 {
	   temp->next = temp->next->next;
	   return;
	 }
	 else
	 {
	    delFromTail();
	    return;
	 }
      }
      temp=temp->next;
      c++;

    }while(temp!=head);

      cout<<"Invalid position !";
  }
  else
    cout<<"\nList is empty!!";

}


//////////////////////////////////

template <class T>
int list<T>::search(T val)
{
  node<T> *temp;
  int i = 1;
  temp = head;
  do
  {
	if(temp->info == val)
	  return i;
	temp=temp->next;
	i++;

  }while(temp != head);
  return -1;
}

/////////////////////////////////////////

template <class T>
void list<T>::reverse()
{
  if(head != '\0')
  {
    node<T> *temp, *head2 = tail, *tempSec;  //earlier

    if(head != tail)
    {
      test:
	for(tempSec = head, temp=head->next; temp->next!=head && tempSec->next != tail; temp=temp->next, tempSec=tempSec->next);
	{
	  temp->next=tempSec;
	  tempSec->next=head;
	  tail=tempSec;
	  if(head!=tail)
	    goto test;
	  else
	    head = head2;
	}
    }
    else
    {
      cout<<"\nList has only one element.";
    }
  }
  else
    cout<<"\nList is empty!!";
}

/////////////////////////////////////////

template <class T>
void list<T>::displayList()
{
  int c = 0;
  if(head != '\0')
  {
	cout<<"\nList is:- \n";
	node<T> *temp = head;

	if(head == tail)
	{
	  cout<<temp->info;
	  return;
	}

	do
	{
	  if(temp != head)
	    cout<<"  ->  "<<temp->info;
	  else
	    cout<<temp->info;

	 temp=temp->next;
	 if(temp == tail)
	   c = 1;
	}while(temp != tail);

	if(c == 1)
	    cout<<"  ->  "<<temp->info;
  }
  else
	cout<<"\nList is empty!!";
}

//-------------------------------------//

/*   	    THE MAIN FUNCTION	       */

//-------------------------------------//

void main()
{
  clrscr();
    int choice, x;
	list<int> ls;
	char ch;
  here:
	clrscr();
	  cout<<"\nMENU:- \n"
	      <<"\n1)  Add to Head"
	      <<"\n2)  Add to Tail"
	      <<"\n3)  Delete from Head"
	      <<"\n4)  Delete from Tail"
	      <<"\n5)  Add at a loc."
	      <<"\n6)  Delete from a loc."
	      <<"\n7)  Search in list"
	      <<"\n8)  Reverse the list"
	      <<"\n9)  Display\n\n";
	  cin>>choice;
	switch(choice)
	{
		case 1:  clrscr();
				 cout<<"\nEnter data: ";
				 cin>>x;
				 ls.addToHead(x);
				 break;

		case 2:  clrscr();
				 cout<<"\nEnter data: ";
				 cin>>x;
				 ls.addToTail(x);
				 break;

		case 3:  clrscr();
				 ls.delFromHead();
				 break;

		case 4:  clrscr();
				 ls.delFromTail();
				 break;

		case 5:  clrscr();
				 int c;
				 cout<<"\nEnter data to add: ";
				 cin>>x;
				 cout<<"\nEnter the loc.: ";
				 cin>>c;
				 ls.addNodeAtPos(c, x);
				 break;

		case 6:  clrscr();
				 cout<<"\nEnter pos.: ";
				 cin>>x;
				 ls.delNodeFromPos(x);
				 break;

		case 7:  clrscr();
				 int pos;
				 cout<<"\nEnter item to search: ";
				 cin>>x;
				 pos = ls.search(x);
				 if(pos!=-1)
				   cout<<"\nFound at position: "<<pos;
				 else
				   cout<<"\nItem not found!!";
				 break;

		case 8:  clrscr();
				 ls.reverse();
				 break;

		case 9:  clrscr();
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
