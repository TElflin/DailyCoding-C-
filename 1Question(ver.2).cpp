#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool checkArray(vector<int> arr, const int &nr)
{
    sort(arr.begin(), arr.end());
    int begi = 0;
    int endi = arr.size()-1;

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

    vector<int> arr = {2, 20, 19, 12, 8, 7, 3};

    int sum;
    cout << "Give a number" << endl;
    cin >> sum;

    if (checkArray(arr,  sum)) cout << "true";
    else cout << "false";

    return 0;
}
