Find Union and Intersection of two unsorted arrays
    Difficulty Level : Easy
                           Last Updated : 12 Aug,
                       2022 Read
                           Discuss

                               Given two unsorted arrays that represent two
                               sets(elements in every array are distinct),
                       find the union and intersection of two arrays.

                       For example,
                       if the input arrays are :

    arr1[] = {7, 1, 5, 2, 3, 6} arr2[] = {3, 8, 6, 20, 7} Then your program should print Union as{1, 2, 3, 5, 6, 7, 8, 20} and Intersection as{3, 6, 7}.Note that the elements of union and intersection can be printed in any order.

                                                                                                                                                                                                Recommended Problem Union of two arrays Hash Mathematical Rockstand Zoho Solve Problem Submission count : 1.8L Complete Interview Preparation
                                                                                                                                                                                                - GFG

                                                                                                                                                                                                  Method 1(Using Set) :

                                                                                                                                                                                                                        Union of two arrays we can get with the Set data structure very easily.Set is a data structure that allows only the distinct elements in it.So,
    when we put the elements of both the array into the set we will get only the distinct elements that are equal to the union operation over the arrays.Let’s code it now –>

// C++ program for the union of two arrays using Set
#include <bits/stdc++.h>
                           using namespace std;
void getUnion(int a[], int n, int b[], int m)
{

    // Defining set container s
    set<int> s;

    // Inserting array elements in s
    for (int i = 0; i < n; i++)
        s.insert(a[i]);

    for (int i = 0; i < m; i++)
        s.insert(b[i]);
    cout << "Number of elements after union operation: " << s.size() << endl;
    cout << "The union set of both arrays is :" << endl;
    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr
             << " "; // s will contain only distinct
                     // elements from array a and b
}

// Driver Code
int main()
{
    int a[9] = {1, 2, 5, 6, 2, 3, 5, 7, 3};
    int b[10] = {2, 4, 5, 6, 8, 9, 4, 6, 5, 4};

    getUnion(a, 9, b, 10);
}

// contributed by Anirban Chand
Output
Number of elements after union operation: 9
The union set of both arrays is :
1 2 3 4 5 6 7 8 9 
Time Complexity: O(m * log(m) + n * log(n))

Note: O(m + n) in case of Python because in python the set built-in method is quite different than that of C++ once, Python uses an hash map internally.

We can improve performance of getUnion method by iterating over both the arrays for index from 0 to min(n, m)-1 adding all the elements in both the arrays to the set, and then iterate over the other array with the remaining elements and add them to the set.

// C++ program for the union of two arrays using Set
#include <bits/stdc++.h>
using namespace std;
void getUnion(int a[], int n, int b[], int m)
{
    int min = (n < m) ? n : m;

    // Defining set container s
    set<int> s;

    // add elements from both the arrays for
    // index from 0 to min(n, m)-1
    for (int i = 0; i < min; i++)
    {
        s.insert(a[i]);
        s.insert(b[i]);
    }

    if (n > m)
    {
        for (int i = m; i < n; i++)
        {
            s.insert(a[i]);
        }
    }
    else if (n < m)
    {
        for (int i = n; i < m; i++)
        {
            s.insert(b[i]);
        }
    }

    cout << "Number of elements after union operation: " << s.size() << endl;
    cout << "The union set of both arrays is :" << endl;
    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr
             << " "; // s will contain only distinct
                     // elements from array a and b
}

// Driver Code
int main()
{
    int a[9] = {1, 2, 5, 6, 2, 3, 5, 7, 3};
    int b[10] = {2, 4, 5, 6, 8, 9, 4, 6, 5, 4};

    getUnion(a, 9, b, 10);
}

// This code is contributed by Aarti_Rathi
Output
    Number of elements after union operation : 9 The union set of both arrays is : [ 1, 2, 3, 4, 5, 6, 7, 8, 9 ] Time Complexity : O(max(m, n))

                                                                                                                                       Method 2 : (Using map data structure)

                                                                                                                                                      From the knowledge of data structures,
                                                                                                                                                  we know that map stores distinct keys only.So if we insert any key appearing more than one time it gets stored only once.The idea is to insert both the arrays in one common map which would then store the distinct elements of both arrays(union of both the array).

                                                                                                                                                  Below is the implementation of the above method :

// C++ program for the above approach
#include <bits/stdc++.h>
    using namespace std;
void printUnion(int *a, int n, int *b, int m)
{

    // Defining map container mp
    map<int, int> mp;

    // Inserting array elements in mp
    for (int i = 0; i < n; i++)
        mp.insert({a[i], i});

    for (int i = 0; i < m; i++)
        mp.insert({b[i], i});
    cout << "The union set of both arrays is :" << endl;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
        cout << itr->first
             << " "; // mp will contain only distinct
                     // elements from array a and b
}

// Driver Code
int main()
{
    int a[7] = {1, 2, 5, 6, 2, 3, 5};
    int b[9] = {2, 4, 5, 6, 8, 9, 4, 6, 5};

    printUnion(a, 7, b, 9);
}
Output
The union set of both arrays is :
1 2 3 4 5 6 8 9 
The above method has time complexity O(m+n).

*This method is suggested by Vinay Verma

Method 3 (Naive) 

Union: 

Initialize union U as empty.
Copy all elements of the first array to U.
Do the following for every element x of the second array:
If x is not present in the first array, then copy x to U.
Return U.
Intersection: 

Initialize intersection I as empty.
Do the following for every element x of the first array
If x is present in the second array, then copy x to I.
Return I.
The time complexity of this method is O(mn) for both operations. Here m and n are numbers of elements in arr1[] and arr2[] respectively.

However, above method works only for distinct elements in input arrays.

Method 4 (Use Sorting) 

Sort arr1[] and arr2[]. This step takes O(mLogm + nLogn) time.
Use O(m + n) algorithms to find the union and intersection of two sorted arrays.
The overall time complexity of this method is O(mLogm + nLogn).

Method 5 (Use Sorting and Searching) 
Union: 

Initialize union U as empty.
Find smaller m and n and sort the smaller array.
Copy the smaller array to U.
For every element x of a larger array, do the following
Binary Search x in the smaller array. If, x is not present, then copy it to U.
Return U.
Intersection: 

Initialize intersection I as empty.
Find smaller of m and n and sort the smaller array.
For every element x of a larger array, do the following
Binary Search x in the smaller array. If x is present, then copy it to I.
Return I.
Time complexity of this method is min(mLogm + nLogm, mLogn + nLogn) which can also be written as O((m+n)Logm, (m+n)Logn). This approach works much better than the previous approach when the difference between the sizes of two arrays is significant.
Thanks to use_the_force for suggesting this method in a comment here. 

Below is the implementation of this method. However, this method also works only for distinct elements in input arrays.

// A C++ program to print union and intersection
/// of two unsorted arrays
#include <algorithm>
#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x);

// Prints union of arr1[0..m-1] and arr2[0..n-1]
void printUnion(int arr1[], int arr2[], int m, int n)
{
    // Before finding union, make sure arr1[0..m-1]
    // is smaller
    if (m > n)
    {
        int *tempp = arr1;
        arr1 = arr2;
        arr2 = tempp;

        int temp = m;
        m = n;
        n = temp;
    }

    // Now arr1[] is smaller

    // Sort the first array and print its elements (these
    // two steps can be swapped as order in output is not
    // important)
    sort(arr1, arr1 + m);
    for (int i = 0; i < m; i++)
        cout << arr1[i] << " ";

    // Search every element of bigger array in smaller array
    // and print the element if not found
    for (int i = 0; i < n; i++)
        if (binarySearch(arr1, 0, m - 1, arr2[i]) == -1)
            cout << arr2[i] << " ";
}

// Prints intersection of arr1[0..m-1] and arr2[0..n-1]
void printIntersection(int arr1[], int arr2[], int m, int n)
{
    // Before finding intersection, make sure arr1[0..m-1]
    // is smaller
    if (m > n)
    {
        int *tempp = arr1;
        arr1 = arr2;
        arr2 = tempp;

        int temp = m;
        m = n;
        n = temp;
    }

    // Now arr1[] is smaller

    // Sort smaller array arr1[0..m-1]
    sort(arr1, arr1 + m);

    // Search every element of bigger array in smaller
    // array and print the element if found
    for (int i = 0; i < n; i++)
        if (binarySearch(arr1, 0, m - 1, arr2[i]) != -1)
            cout << arr2[i] << " ";
}

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then it can only
        // be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present in right
        // subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not present in array
    return -1;
}

/* Driver program to test above function */
int main()
{
    int arr1[] = {7, 1, 5, 2, 3, 6};
    int arr2[] = {3, 8, 6, 20, 7};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    // Function call
    cout << "Union of two arrays is n";
    printUnion(arr1, arr2, m, n);
    cout << "nIntersection of two arrays is n";
    printIntersection(arr1, arr2, m, n);
    return 0;
}
Output
    Union of two arrays is n3 6 7 8 20 1 5 2 nIntersection of two arrays is n7 3 6 Another
    Approach(When elements in the array may not be distinct) :

// C++ code to find intersection when
// elements may not be distinct
#include <bits/stdc++.h>

                                                               using namespace std;

// Function to find intersection
void intersection(int a[], int b[], int n, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] > b[j])
        {
            j++;
        }
        else if (b[j] > a[i])
        {
            i++;
        }
        else
        {

            // when both are equal
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}

// Driver Code
int main()
{
    int a[] = {1, 3, 2, 3, 3, 4, 5, 5, 6};
    int b[] = {3, 3, 5};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    // sort
    sort(a, a + n);
    sort(b, b + m);

    // Function call
    intersection(a, b, n, m);
}
Output
3 3 5 
 Thanks, Sanny Kumar for suggesting the above method.