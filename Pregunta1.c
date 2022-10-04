#include <algorithm>
#include <iostream>
using namespace std;
 
int sort3(int arr[])
{
    // Insert arr[1]
    if (arr[1] < arr[0])
       swap(arr[0], arr[1]);
 
    // Insert arr[2]
    if (arr[2] < arr[1])
    {
       swap(arr[1], arr[2]);
       if (arr[1] < arr[0])
          swap(arr[1], arr[0]);
    }
}
 
int main()
{
    int a[] = {10, 12, 5};
     
    sort3(a);
 
    for (int i = 0; i < 3; i++)
        cout << a[i] << " ";
 
    return 0;
}