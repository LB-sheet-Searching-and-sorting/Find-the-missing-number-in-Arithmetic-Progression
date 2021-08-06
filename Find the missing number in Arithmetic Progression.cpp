/*
Given an array that represents elements of arithmetic progression IN ORDER . 
One element is missing in the progression, find the missing number.

ASSUMING POSITIVE NUMBERS ONLY so AP is increading one

My_Approach1: LINEAR SEARCH 

TC = O(n)
SC = O(1)

Traverse the array from [0..n-1] and 2nd term se current d and last d nikaalte jaao aur agar aisa koi point aaya 
jaha current common diff pichle wale se bada hai to missing term = a[i-1]+last diff

My_Approach2: Hashmap

store answer in a hash map and see which key is absent in i/p array
return that key 

TC = O(n)
SC = O(n)


MY_OBSERVATION:

AP koi bhi dia ho 1st and last ter to missing nhi ho sakta na..

sum of AP = n/2(a+l)

original sum nikaalne ke liye muze sirf n/2 ki jagah n+1/2 karna hoga kyuki ek term jyada hoga original wale me
to apna answer hai original sum - current AP sum


My_Approach3: Observation Atharva bhai ka :)

INCORRECT OUTPUT kyuki current sum nikaalte waqt vo series AP nhi hogi bcoz ek term gayab hai. Sum nikaalne ke 
liye for loop hi lagana hoga to O(n) hi jaayga vo
Original sum barabar aari lage to

GFG_Approach4: Use binary search iterative

TC = O(logn)
SC = O(1)

We can solve this problem in O(Logn) time using Binary Search. 
The idea is to go to the middle element. Check if the difference between middle and next to middle is 
equal to diff or not, if not then the missing element lies between mid and mid+1. If the middle element is 
equal to n/2th term in Arithmetic Series (Let n be the number of elements in input array), 
then missing element lies in right half. Else element lies in left half.

*/

#include<bits/stdc++.h>
using namespace std;

//defining class
class solution
{
	public:
		int BS(int arr[],int low,int high,int diff)
		{
			
			int mid=low+(high-low)/2;
			
			while(low<=high)
			{
				// The element just after mid is missing
				if(arr[mid+1]-arr[mid]!=diff)
				{
					return (arr[mid]+diff);
				}
				// The element just before mid is missing
				if (mid > 0 && arr[mid] - arr[mid - 1] != diff)
				{
					return (arr[mid - 1] + diff);
				}
				
				// If the elements till mid follow AP, then recur for right half
    			if (arr[mid] == arr[0] + mid * diff)
    			{
    				low=mid+1;
				}
				else
				{
					// Else recur for left half
    				high=mid-1;
				}
				
			}
			
		}
		
		int findMissing(int arr[], int n)
		{
			 int diff = (arr[n - 1] - arr[0]) / n;
			 
			 return BS(arr, 0, n - 1, diff);
		}
};

// Driver Code
int main()
{
	//creating object
    solution s;
    
    int arr[] = {1, 6, 11, 16, 21, 31};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "\nThe missing element is "<< s.findMissing(arr, n);
    return 0;
}
