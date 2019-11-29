#include <iostream>

using namespace std;

bool checkArray( const int *arr, const int &arrSize, const int &nr)
{
    for(int i =0; i < arrSize; i++)
    {
        for (int j=i+1; j < arrSize; j++)
        {
            if (arr[i]+arr[j] == nr)
            {
                return true;
            }
        }
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
