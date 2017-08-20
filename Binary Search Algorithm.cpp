/*
Binary Search Algorithm.
Implemented Khurshed Shoeb.
*/
#include<iostream>
using namespace std;

#define arr_size 100

int arr[arr_size];
int temp[arr_size], counter = 0;

void merging(int startPoint, int midPoint, int endPoint)
{
    int firstArrCnt,secArrCnt,i;
    firstArrCnt = startPoint;
    secArrCnt = midPoint + 1;

    for(i = firstArrCnt; firstArrCnt<=midPoint && secArrCnt<=endPoint; i++)
    {
        if(arr[firstArrCnt] < arr[secArrCnt])
            temp[i] = arr[firstArrCnt++];
        else
            temp[i] = arr[secArrCnt++];
    }

    while(firstArrCnt <= midPoint)
        temp[i++] = arr[firstArrCnt++];

    while(secArrCnt <= endPoint)
        temp[i++] = arr[secArrCnt++];

    for(i = startPoint; i<=endPoint; i++)
        arr[i] = temp[i];

}

void sorting(int startPoint, int endPoint)
{
    int midPoint;

    if(startPoint >= endPoint)
        return;

    printf("Counter: %d: Start: %d, End: %d\n",++counter, startPoint, endPoint);

    midPoint = (startPoint+endPoint)/2;

    sorting(startPoint, midPoint);
    sorting(midPoint+1, endPoint);

    merging(startPoint, midPoint, endPoint);
}

int main()
{
    int i, n;

    cout<<"Enter number of elements:"<<endl;
    scanf("%d", &n);
    
    cout<<"Enter %d elements:"<<n;
    
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    sorting(0, n-1);

    cout<<"After sorting the Array:"<<endl;
    for(i = 0; i<n; i++)
        printf("%d ", arr[i]);
    puts("");

    return 0;
}
