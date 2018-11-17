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

template <class T>
int binarySearch(T arr[], int l, int r, T data) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 
  
        if (arr[mid] == x)   
            return mid; 

        if (arr[mid] > x)  
            return binarySearch(arr, l, mid-1, x); 

        return binarySearch(arr, mid+1, r, x); 
   } 

   return -1; 
} 

////////////////////////////////////////////////////////////

template<class T>
void main()
{
 clrscr();
   T<int> arr[6], x;
   int ch, size = 6, pos;
   char c;


   cout<<"Enter array of size "<<size<<".\n";
   for(int i = 0; i<size; i++)
      cin>>arr2[i];		//2

 MENU:
   clrscr();
   cout<<"\n\nMENUn\n"
	   <<"\n1) Linear search"
	   <<"\n2) Binary search"
       <<"\n   Your choice: ";
   cin>>ch;


	switch(ch)
	{
		case 1:		cout<<"Enter data to search: ";
					  cin>>x;
					  pos = linearSarch(x, arr, size)+1;
					  break;

		case 2:		cout<<"Enter data to search: ";
					  cin>>x;
   					  pos = binarySearch(arr, 0, size-1, x)+1;
   					  break;

		default:	cout<<"\n Oops! Wrong input!";
					pos=-1;

	}

   if(pos != -1)
   {
   	if(pos != 0)
    	 cout<<"\nData found at position: "<<pos;
   	else
    	 cout<<"Data is unavailable!!";
   }
   else
   {
   		cout<<"\nWanna try again?(Y/N)";
		cin>>c;

   		if(c=='y' || c=='Y')
   		goto MENU;
   }

 getch();
}