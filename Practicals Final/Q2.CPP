#include<iostream.h>
#include<conio.h>

template <class T>
void swap(T *one, T *two) 
{ 
    T temp = *one; 
    *one = *two; 
    *two = temp; 
}

//--------------------------------------//

template <class T>
void insertionSort(T arr[], int n) 
{ 
   int i, j; 
   T key;
   for (i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       
       for (j = i-1; j >= 0 && arr[j] > key; j--) 
           arr[j+1] = arr[j]; 
       arr[j+1] = key; 
   } 
} 

//--------------------------------------//

template <class T>
void bubbleSort(T arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)          
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
}

//--------------------------------------//

template <class T>
void selectionSort(T arr[], int n) 
{ 
    int i, j, minAt; 
   
    for (i = 0; i < n-1; i++) 
    { 
        minAt = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[minAt]) 
            minAt = j; 
  
        swap(&arr[minAt], &arr[i]); 
    } 
} 

///////////////////////////////////////////////////////////

template <class T>
void getArr(T arr[], int n)
{
	cout<<"Enter the array: ";
	for(int i=0; i<n; i++)
		cin>>arr[i];
}

template <class T>
void putArr(T arr[], int n)
{
	cout<<"Sorted array: \n\n";
	for(int i=0; i<n; i++)
		cout<<arr[i];
}
////////////////////////////////////////////////////////////

template<class T>
void main()
{
 clrscr();
   T<int> arr[6], x;
   int ch, size = 6;
   char c;

   cout<<"Enter array of size "<<size<<".\n";
   for(int i = 0; i<size; i++)
      cin>>arr2[i];		//2

  	getArr(arr, size);

 MENU:
   clrscr();
   cout<<"\n\nMENUn\n"
   	   <<"\n1) Insertion sort"
   	   <<"\n2) Bubble sort";
   	   <<"\n3) Selection sort"
   	   <<"\n   Your choice: ";
   cin>>ch;


	switch(ch)
	{
		case 1:		insertionSort(arr, size);
 	  				break;

		case 2:		bubbleSort(arr, size);
   					break;

   		case 3:		selectionSort(arr, size);
   					break;

		default:	cout<<"\n Oops! Wrong input!";

	}

	putArr(arr, size);

   		cout<<"\n Wanna try again?(Y/N): ";
		cin>>c;

   		if(c=='y' || c=='Y')
   		goto MENU;

 getch();
}
