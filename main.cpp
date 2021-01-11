#include <iostream>

using namespace std;

int main()
{
    int arr[5]={1,3,2,4,7};
    for(int i(0);i<(sizeof(arr)/sizeof(arr[0]));i++){
        for(int j=i+1;j<(sizeof(arr)/sizeof(arr[0]));j++){
	        if((arr[i]==arr[j]) && (i != j)){
	            cout << "Duplicate";
	        } else {
	        	cout<< "Unique";
			}
        }
    }

    return 0;
}
