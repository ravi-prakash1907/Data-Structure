/////////////////		SINGLY LINKED LIST	     /////////////////

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

	node<T>* throwHead()
	{
	  return head;
	}


	node<T>* throwTail()
	{
	  return tail;
	}

	void addToHead(T);
	void addToTail(T);
	void delFromHead();
	void delFromTail();
	void addNodeAfter(T, T);
	void addNodeAtPos(T, T);
	void delNodeAfter(T);
	int search(T val);
	void delNodeFromPos(T);
	void reverse();
	void concatinate(list<T>,list<T>);
	void displayList();

};

/////////////////////////////////////////

template <class T>
void list<T>::addToHead(T val)
{
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
    tail->next = new node<T>(val);
    tail = tail->next;
  }
  else
    head = tail = new node<T>(val);
}

/////////////////////////////////////////

template <class T>
void list<T>::delFromHead()
{
  if(head != '\0')
  {
	node<T> *temp = head;
	cout<<"\nDeleting: "<<temp->info;
	head = head->next;
	cout<<"\nDeleted!!";
	delete temp;
  }
  else
	cout<<"\nList Underflow!!";
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
      tail->next = '\0';
      cout<<"\nDeleted!!";
    }
  }
  else
	cout<<"\nList Underflow!!";
}

/////////////////////////////////////////

template <class T>
void list<T>::addNodeAfter(T clue, T val)
{
  if(head != '\0')
  {
    node<T> *temp;
    for(temp = head; temp!='\0'&&temp->info!=clue; temp=temp->next);
    temp->next = new node<T>(val, temp->next);
  }
  else
    cout<<"\nList Underflow!!";
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
    for(temp = head,c = 1; temp!='\0'; temp=temp->next,c++)
      if(c+1 == pos)
      {
	temp->next = new node<T>(val, temp->next);		// adds new node having info part = val and next = temp->next
	return;
      }
    if(temp == '\0')
      cout<<"Invalid position !";
  }
  else
    cout<<"\nList Underflow!!";
}

				    /*

void insertatanylocation()
 {
   struct node *ptr = new node;
   int data,c,counter=0;
   cout<<endl<<"Enter the location at which u want to insert  the element";
   cin>>c;


   if(c==0)       //  it'd more better to initiate position as 1 instead of 0
   {
     insertatstart();
     return;
   }

   else
   for(struct node *j=head;j!=NULL;j=j->next)
   {
     if( (counter+1)==c )
     {
       cout<<endl<<"Enter data: ";     // earlier, these lines
       cin>>data;                      // were absent

      ptr->next=j->next;
      j->next=ptr;
      ptr->info=data;        // Awwww!! it was a garbage value ___ firstly Get 'data'
      return;
     }
     else
      counter++;
   }

   if(counter<c)                        // earlier >
   cout<<"No such location exists"<<endl;
 }
				      */

/////////////////////////////////////////
template <class T>
void list<T>::delNodeFromPos(T pos)
{
  if((head != '\0')||(pos == 1))
  {
    node<T> *temp;
    int c;

    if(pos == 1)
    {
      delFromHead();
      return;
    }
    else
    for(temp = head,c = 1; temp!='\0'; temp=temp->next,c++)
      if(c+1 == pos)
      {
	temp->next = temp->next->next;
	return;
      }
    if(temp == '\0')
      cout<<"Invalid position !";
  }
  else
    cout<<"\nList Underflow!!";
}


//////////////////////////////////

template <class T>
void list<T>::delNodeAfter(T clue)
{
  if(head != '\0')
  {
    node<T> *temp, *x;
    for(temp = head; temp!='\0'&&temp->info!=clue; temp=temp->next);

    if(head==tail)
      delFromHead();

    else if( temp!='\0')
    {
      x = temp->next;
      temp->next=x->next;
      cout<<"\nDeleting: "<<x->info;
      //delete x;
    }

    else if(temp==tail)
      delFromTail();
  }
  else
    cout<<"\nList Underflow!!";
}

/////////////////////////////////////////

template <class T>
int list<T>::search(T val)
{
  node<T> *temp;
  int i;
  for(temp = head, i = 1; temp!='\0'; temp=temp->next, i++)
	if(temp->info == val)
	  return i;
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
	for(tempSec = head, temp=head->next; temp->next!='\0'&&tempSec->next != tail; temp=temp->next, tempSec=tempSec->next);
	{
	  temp->next=tempSec;
	  tempSec->next='\0';
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
    cout<<"\nList Underflow!!";
}

/////////////////////////////////////////

template <class T>
void list<T>::displayList()
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
	list<int> ls;
	char ch;
  here:
	clrscr();
	  cout<<"\nMENU:- \n"
	      <<"\n1)  Add to Head"
	      <<"\n2)  Add to Tail"
	      <<"\n3)  Delete from Head"
	      <<"\n4)  Delete from Tail"
	      <<"\n5)  Add new entry after...(clue)"
	      <<"\n6)  Add at a loc."
	      <<"\n7)  Delete an entry existing after...(clue)"
	      <<"\n8)  Delete from a loc."
	      <<"\n9)  Search in list"
	      <<"\n10) Reverse the list"
	      <<"\n11) Display\n\n";
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
				 cout<<"\nEnter clue: ";
				 cin>>c;
				 ls.addNodeAfter(c, x);
				 break;

		case 6:  clrscr();
				 cout<<"\nEnter data to add: ";
				 cin>>x;
				 cout<<"\nEnter the loc.: ";
				 cin>>c;
				 ls.addNodeAtPos(c, x);
				 break;

		case 7:  clrscr();
				 cout<<"\nEnter clue: ";
				 cin>>x;
				 ls.delNodeAfter(x);
				 break;

		case 8:  clrscr();
				 cout<<"\nEnter pos.: ";
				 cin>>x;
				 ls.delNodeFromPos(x);
				 break;

		case 9:  clrscr();
				 int pos;
				 cout<<"\nEnter item to search: ";
				 cin>>x;
				 pos = ls.search(x);
				 if(pos!=-1)
				   cout<<"\nFound at position: "<<pos;
				 else
				   cout<<"\nItem not found!!";
				 break;

		case 10:  clrscr();
				 ls.reverse();
				 break;

		case 11:  clrscr();
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