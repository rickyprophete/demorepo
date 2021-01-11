#include <iostream>
using namespace std;

void bubbleSort(int arr[], int N){
    int j, i, temp, flag, work = 0;
    for(j = 1; j < N; j++)
    {
        flag = 0;
        for(i = 0; i < N - j; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = 1;
                work++;
            }
        }
        if(flag == 0)
        {
                break;
        }
    }

    for(i = 0; i < N; i++)
    {
       cout << arr[i] <<' ';
    }cout << endl;
    cout << work;

}

int main()
{
    int arr[]={1,5,9,2,7};
    const int N = sizeof(arr)/sizeof(int);
    bubbleSort(arr,N);

    return 0;
}
