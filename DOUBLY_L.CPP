/////////////////		DOUBLY LINKED LIST	     /////////////////

#include<iostream.h>
#include<conio.h>
#include<stdio.h>

//		NODE		//

template <class T> class node
{
  public:
	T info;
	node<T> *next;
	node<T> *prev;

    node(T data, node<T> *ptr1 = NULL, node<T> *ptr2 = NULL)
	{
	  info = data;
	  prev = ptr1;
	  next = ptr2;
	}
};

//		LIST CLASS		//

template <class T> class list
{
	node<T> *head, *tail;
  public:
	list()
	{
	  head = NULL;
	  tail = NULL;
	}

	void addToHead(T);
	void addToTail(T);
	void delFromHead();
	void delFromTail();
	void addNodeAtPos(T, T);
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
  node<T> *temp;
  if(head != NULL)
  {
    temp = head;
    head = new node<T>(val, NULL, head);
    temp->prev = head;
    if(tail == NULL)
      tail = head;
  }
  else
    head = tail = new node<T>(val);
}

/////////////////////////////////////////  DONE

template <class T>
void list<T>::addToTail(T val)
{
  if(head != NULL)
  {
    tail->next = new node<T>(val, tail);
    tail = tail->next;
  }
  else
    head = tail = new node<T>(val);
}

/////////////////////////////////////////  DONE

template <class T>
void list<T>::delFromHead()
{
  if(head != NULL)
  {
	node<T> *temp = head;
	cout<<"\nDeleting: "<<temp->info;
	if(head == tail)
	  head = tail = NULL;
	else
	{
	  head = head->next;
	  head->prev = NULL;
	}
	cout<<"\nDeleted!!";
	delete temp;
  }
  else
	cout<<"\nList Underflow!!";
}

/////////////////////////////////////////  DONE

template <class T>
void list<T>::delFromTail()
{
  if(head != NULL)
  {
    if(head == tail)
    {
      node<T> *temp;
      cout<<"\nDeleting: "<<tail->info;
      head = tail = NULL;
    }
    else
    {
      node<T> *temp;
      cout<<"\nDeleting: "<<tail->info;
      tail = tail->prev;
      tail->next = NULL;
    }

    cout<<"\nDeleted!!";
  }
  else
	cout<<"\nList Underflow!!";
}

/////////////////////////////////////////  DONE

template <class T>
void list<T>::addNodeAtPos(T pos, T val)
{
  if((head != NULL)||(pos == 1))
  {
    node<T> *temp;
    int c;

    if(pos == 1)
    {
      addToHead(val);		// Adds new node to head
      return;
    }
    else
    for(temp = head,c = 1; temp!=NULL; temp=temp->next,c++)
      if(c+1 == pos)
      {
	temp->next = new node<T>(val, temp, temp->next);
	if(temp != tail)
	  temp->next->next->prev = temp->next;
	return;
      }
    if(temp == NULL)
      cout<<"Invalid position !";
  }
  else
    cout<<"\nList Underflow!!";
}

/////////////////////////////////////////  DONE

template <class T>
void list<T>::delNodeFromPos(T pos)
{
  if((head != NULL)||(pos == 1))
  {
    node<T> *temp1, *temp2;
    int c;

    if(pos == 1)
    {
      delFromHead();
      return;
    }
    else
    for(temp1 = head, temp2 = temp1->next, c = 1; temp2!=NULL; temp1=temp1->next, temp2=temp2->next, c++)
      if(c+1 == pos)
      {
	temp2->next->prev = temp1;
	temp1->next = temp2->next;
	cout<<"\nDeleted!";
	return;
      }
    if(temp2 == NULL)
      cout<<"Invalid position !";
  }
  else
    cout<<"\nList Underflow!!";
}


//////////////////////////////////  DONE

template <class T>
int list<T>::search(T val)
{
  node<T> *temp;
  int i;
  for(temp = head, i = 1; temp!=NULL; temp=temp->next, i++)
	if(temp->info == val)
	  return i;
  return -1;
}

/////////////////////////////////////////

template <class T>
void list<T>::reverse()
{
  if(head != NULL)
  {
    node<T> *i, *temp, *head2 = tail, *tempSec;  //earlier

    if(head != tail)
    {
      test:
	for(tempSec = head, temp=head->next; temp->next!=NULL&&tempSec->next != tail; temp=temp->next, tempSec=tempSec->next);
	{
	  temp->next=tempSec;
	  tempSec->next=NULL;
	  temp->prev= (head2==temp) ? NULL : i;
	  tail=tempSec;

	  i=temp;


	  if(head!=tail)
	    goto test;
	  else
	  {
	    tail->prev=i;
	    head = head2;
	  }
	}
	cout<<"\nList reversed.";
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
  if(head != NULL)
  {
	cout<<"\nList is:- \n";

	cout<<"NULL  <->  ";
	for(node<T> *temp = head; temp!=NULL; temp=temp->next)
	{
	    cout<<temp->info<<"  <->  ";
	}
	cout<<"NULL";
	  
	/*	TO DEPICT THE USE OF PREVIOUS & NEXT POINTERS

	for(node<T> *temp = head; temp!=NULL; temp=temp->next)
	{
	    cout<<endl<<temp->info<<"  |\tPre: "<<temp->prev->info<<",\tNext: "<<temp->next->info;
	}

	*/
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
    int choice, x, c;
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
