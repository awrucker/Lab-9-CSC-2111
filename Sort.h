/*
	Dylan Bush & Adam Rucker
	3/27/2017
	Lab 9/ Quick Sort
*/	
#if !defined (SORT_H)
#define SORT_H
#include <iostream>
using namespace std;
template < class T >
class Sort
{
   private: 
      static void _selectionSort(T** items, int numItems, int (*compare) (T* one, T* two));
      static void _mergeSort(T** items, int first, int last, int (*compare) (T* one, T* two));
      static void merge(T** items, int first, int mid, int last, int (*compare) (T* one, T* two));
      static void choosePivot(T** items, int first, int last);
      static int partition(T** items, int first, int last, int (*compare) (T* one, T* two));
      static void _quickSort(T** items, int first, int last, int (*compare) (T* one, T* two));
      static void _insertionSort(T** items, int numItems, int (*compare) (T* one, T* two));
      static int insertLocation(T** items, T* item, int last, int (*compare) (T* one, T* two));
      static void _insertionBinarySort(T** items, int numItems, int (*compare) (T* one, T* two));

      static int linearSearch(T** items, int numItems, T* item, int index, int (*compare) (T* one, T* two));
      static int binarySearch(T** items, int numItems, T* item, int first, int last, int (*compare) (T* one, T* two));

   public:
      static T** selectionSort(T** items, int numItems, int (*compare) (T* one, T* two));
      static T** insertionSort(T** items, int numItems, int (*compare) (T* one, T* two));
      static T** mergeSort(T** items, int numItems, int (*compare) (T* one, T* two));
      static T** quickSort(T** items, int numItems, int (*compare) (T* one, T* two));
      static T** insertionBinarySort(T** items, int numItems, int (*compare) (T* one, T* two));

      static int linearSearch(T** items, int numItems, T* item, int (*compare) (T* one, T* two));
      static int binarySearch(T** items, int numItems, T* item, int (*compare) (T* one, T* two));
};
/*
	Pre: Receives an array of items, the number of items, and a function pointer for comparing items
	Post: Returns a sorted list of items
*/	
template < class T >
T** Sort<T>::quickSort(T** items, int num_items, int (*compare) (T* one, T* two))
{
   //DO THIS
   //create a new array that will be sorted and returned
   //this is in case the original, unsorted array is also needed
	T** sortedItems = new T*[num_items];
	for(int i = 0; i < num_items; i++)
	{
		sortedItems[i] = items[i];                                   //copies a list to be sorted
	}
	_quickSort(sortedItems, 0, num_items-1, compare);          /// calls the recursive function
	return sortedItems;
}
/*
	Pre: Receives a T** items, indexx of the first, index of the last and a comparison function pointer
	Post:Sorts the T** array
*/	
template < class T >
void Sort<T>::_quickSort(T** items, int first, int last, int (*compare) (T* one, T* two))
{
   int pivotIndex;

   //DO THIS
   //make the necessary partition and recursive calls for quick sort
   if (first < last)
   {
	   pivotIndex = partition(items, first, last, compare);        // makes 2 partitions 
	   _quickSort(items, first, pivotIndex-1, compare);           //recursive call for the the 2 partitions 
	   _quickSort(items, pivotIndex+1, last, compare);            // recursive call for the the 2 partition 
   }  
}  
/*
	Pre: Receives a T** items, first, last, and a comparison function pointer
	Post: Returns the index of the partition and the index where the item is in the correct position is.
*/	
template < class T >
int Sort<T>::partition(T** items, int first, int last, int (*compare) (T* one, T* two))
{
    //DO THIS
   //complete the partition method (Lomuto partition)

   //temp is used to swap elements in the array
   T* temp; 

   //initially, choosePivot does nothing           
   choosePivot(items, first, last); 
   int s1 = first-1;                          //makes s1 1 less than the first element of the array
   for(int i = first; i <= last; i++)	//runs through the array from the first through the last
   {
	   if(compare(items[first], items[i]) >= 0)//tests to see if the first item is greater than or equal to items[i]
	   {
		   s1++;                              //increments s1
		   temp = items[i];                   //sets temp = items[i] for swap
		   items[i] = items[s1];			  //does the swap
		   items[s1] = temp;
	   }
   }
   temp = items[s1];
   items[s1] = items[first];
   items[first] = temp;
   return s1;
}
/*
	Pre:Receives an array of items, index of the first and index of the last
	Post: Swaps the first and the item in the middle of first and last to prevent the worse case
*/	
template < class T >
void Sort<T>::choosePivot(T** items, int first, int last)
{
   //DO THIS
   //find a better item to be the partition than simply using the item in the first index
   //you will need to swap
   int midpoint=(last-first)/2;                      //finds the midpoint 

   T* midpointForSwitch= items[midpoint+first];      // saves the midpoint to a temporary memory address
   T* firstItem = items[first];                     // save sthe first elemet in the array
   

   items[midpoint+first]=firstItem;                  //    swaps middle and first
   items[first]= midpointForSwitch;                  //    swaps middle and first 









}

//no work below this point
template < class T >
int Sort<T>::linearSearch(T** items, int numItems, T* item, int (*compare) (T* one, T* two))
{
   return linearSearch(items, numItems, item, 0, compare);
}

template < class T >
int Sort<T>::linearSearch(T** items, int numItems, T* item, int loc, int (*compare) (T* one, T* two))
{
   //we are using a special return type as the cases below are not exceptional
   if (loc == numItems)  //base case end of array
   {
      return -1;  //item not in array (base case #1)
   }

   int index;
   int comp = (*compare) (item, items[loc]);
   if (comp != 0)
   {
      index = linearSearch(items, numItems, item, loc + 1, compare);
   }
   else
   {
      index = loc;
   }

   return index;
}

template < class T >
int Sort<T>::binarySearch(T** items, int numItems, T* item, int (*compare) (T* one, T* two))
{
   return binarySearch(items, numItems, item, 0, numItems - 1, compare);
}

template < class T >
int Sort<T>::binarySearch(T** items, int numItems, T* item, int first, int last, int (*compare) (T* one, T* two)) 
{
   // reaches the base case much faster
   if (first > last) 
   {
      return -1;      // value not in original array (base case #1)
   } 

   int index;
   int mid = first + (last - first)/2;
   int comp = (*compare) (item, items[mid]);
   if (comp == 0) 
   { 
      index = mid;  // value found at search[mid] (base case #2)
   } 
   else if (comp < 0) 
   {
      //making these method calls is extra overhead that recursion requires
      //as it is easy and readable to write a binary search using a loop, that is the preferred implementation
      index = binarySearch(items, numItems, item, first, mid - 1, compare);
   } 
   else 
   {
      index = binarySearch(items, numItems, item, mid + 1, last, compare);
   } 
  
   return index;  //returns the index up through the chain
}

template < class T >
T** Sort<T>::selectionSort(T** items, int numItems, int (*compare) (T* one, T* two))
{
   T** sorted = new T*[numItems];
   for (int i = 0; i < numItems; i++)
   {
      sorted[i] = items[i];
   }

   //passes the address of the function via compare
   _selectionSort(sorted, numItems, compare);
   return sorted;
}

template < class T >
void Sort<T>::_selectionSort(T** items, int numItems, int (*compare) (T* one, T* two))
{
   int min;
   T* item;

   for (int spot = 0; spot < numItems - 1; spot++)                   //n
   {
      min = spot;                                                    //n - 1
      for (int scan = spot + 1; scan < numItems; scan++)             //[n(n + 1)/2] - 1
      {
         //dereferences compare (calls the function)
         if ((*compare) (items[scan], items[min]) < 0)               //(n - 1)(n)/2
         {
            min = scan;                                              //worst case (n - 1)(n)/2
         }
      }

      // Swap the values
      item = items[min];                                             //3(n - 1)
      items[min] = items[spot];
      items[spot] = item;
   }
}

template < class T >
T** Sort<T>::mergeSort(T** items, int numItems, int (*compare) (T* one, T* two))
{
   T** sorted = new T*[numItems];
   for (int i = 0; i < numItems; i++)
   {
      sorted[i] = items[i];
   }

   _mergeSort(sorted, 0, numItems - 1, compare);
   return sorted;
}

template < class T >
void Sort<T>::_mergeSort(T** items, int first, int last, int (*compare) (T* one, T* two))
{
   if (first < last) 
   {
      // sort each half
      int mid = first + (last - first)/2;  //(first + last)/2;   // index of midpoint

      // sort left half sort[first..mid]
      _mergeSort(items, first, mid, compare);

      // sort right half sort[mid + 1..last]   
      _mergeSort(items, mid + 1, last, compare);  
 
      // merge the two halves
      merge(items, first, mid, last, compare);
   } 
}  

template < class T >
void Sort<T>::merge(T** items, int first, int mid, int last, int (*compare) (T* one, T* two)) 
{
   //tempArray
   T** temp = new T*[last - first + 1];
    
   // initialize the local indexes to indicate the subarrays
   int first1 = first;    // beginning of first subarray
   int last1  = mid;      // end of first subarray
   int first2 = mid + 1;  // beginning of second subarray
   int last2  = last;     // end of second subarray

   // while both subarrays are not empty, copy the
   // smaller item into the temporary array
   int index = 0;                    

   while ((first1 <= last1) && (first2 <= last2)) 
   {
      if ((*compare) (items[first1], items[first2]) <= 0)  //careful here for stable sorting
      {
         temp[index] = items[first1];
         first1++;
      }
      else 
      {
         temp[index] = items[first2];
         first2++;
      }  

      index++;
   } 

   // finish off the nonempty subarray

   // finish off the first subarray, if necessary
   while (first1 <= last1) 
   {
      temp[index] = items[first1];
      first1++;
      index++;
   }  

   // finish off the second subarray, if necessary
   while (first2 <= last2)
   {
      temp[index] = items[first2];
      first2++;
      index++;
   }  

   // copy the result back into the original array
   for (index = 0; index <= last - first; index++) 
   {
      items[index + first] = temp[index];
   }

   delete[] temp;  
}  

template < class T >
T** Sort<T>::insertionSort(T** items, int numItems, int (*compare) (T* one, T* two))
{
   T** sorted = new T*[numItems];
   for (int i = 0; i < numItems; i++)
   {
      sorted[i] = items[i];
   }

   _insertionSort(sorted, numItems, compare);
   return sorted;
}

template < class T >
void Sort<T>::_insertionSort(T** items, int numItems, int (*compare) (T* one, T* two))
{
   T* temp;
   int position;

   for (int spot = 1; spot < numItems; spot++)
   {
      temp = items[spot];
      position = spot;

      // shift larger values to the right
      while (position > 0 && (*compare) (items[position - 1], temp) > 0)
      {
         items[position] = items[position - 1];
         position--;
      }
            
      items[position] = temp;
   }
}

template < class T >
T** Sort<T>::insertionBinarySort(T** items, int numItems, int (*compare) (T* one, T* two))
{
   T** sorted = new T*[numItems];
   for (int i = 0; i < numItems; i++)
   {
      sorted[i] = items[i];
   }

   _insertionBinarySort(sorted, numItems, compare);
   return sorted;
}

template < class T >
void Sort<T>::_insertionBinarySort(T** items, int numItems, int (*compare) (T* one, T* two))
{
   T* temp;
   int position;

   for (int spot = 1; spot < numItems; spot++)
   {
      temp = items[spot];

      // shift larger values to the right
      position = insertLocation(items, temp, spot - 1, compare);  //binary search to minimize comparisons
      for(int i = spot; i > position; i--)
      {
         items[i] = items[i - 1];
      }
            
      items[position] = temp;
   }
}

template < class T >
int Sort<T>::insertLocation(T** items, T* item, int last, int (*compare) (T* one, T* two))
{
   //based on array indices
   int first = 0;
   int mid = first + (last - first)/2;

   while (first <= last)
   {
      int comp = ((*compare) (item, items[mid]));
      if (comp == 0)
      {
         break;
      }
      else if (comp < 0)
      {
         last = mid - 1;
         mid = first + (last - first)/2;
      }
      else 
      {
         first = mid + 1;
         mid = first + (last - first)/2;
      }
   }

   return mid;
}

#endif

