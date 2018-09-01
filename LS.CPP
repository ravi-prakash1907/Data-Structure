/*	   WAP to implement Linear Search using templates	   */

#include<iostream.h>
#include<conio.h>

template <class T>

int linearSarch(T data, T arr[], int size)
{
  for(int i=0; i<size; i++)
	if(arr[i] == data)
	  return i;

  return -1;
}

void main()
{
 clrscr();
   int arr[6], size = 6, x, pos;
   char arr2[6], x2;


   cout<<"Enter array of size "<<size<<".\n";
   for(int i = 0; i<size; i++)
      cin>>arr2[i];		//2

   cout<<"Enter data to search: ";
   cin>>x2;			//2

   pos = linearSarch(x2, arr2, size)+1;

   if(pos != 0)
     cout<<"\nData found at position: "<<pos;
   else
     cout<<"Data is unavailable!!";

 getch();
}