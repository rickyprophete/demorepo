#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int i,j,m,n,x,location;
    cout <<"Enter a value to be searched: \n"; cin >> x;
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,22,33,44,55,66,77,88,99,111,222,333,444,555,666,777};
    n = (sizeof(arr)/sizeof(arr[0]));
    i=0,j = n-1;
    while (i < j){
        m = floor((i+j)/2);
        if(x>arr[m]){
            i = m + 1;
        }else{j = m;}
    }
    (x==arr[i])? location = i : location = NULL;
    cout<<"Index of value in array is: "<<location;



}
