#include <iostream>
#include <algorithm>

using namespace std;

bool checkArray(int arr[], const int &arrSize, const int &nr)
{
    sort(arr, arr + arrSize);
    int begi = 0;
    int endi = arrSize-1;

    while(begi<endi)
    {
        int sum = arr[begi] + arr[endi];
        if(sum == nr) return true;
        else if ( sum < nr ) begi++;
        else if ( sum > nr ) endi--;
    }
    return false;
}

int main()
{

    int arr[] = {2, 20, 19, 12, 8, 7, 3};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    int sum;
    cout << "Give a number" << endl;
    cin >> sum;

    if (checkArray(arr, arrSize, sum)) cout << "true";
    else cout << "false";

    return 0;
}
