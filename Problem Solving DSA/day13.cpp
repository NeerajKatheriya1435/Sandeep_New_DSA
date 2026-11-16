#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break; // optimization
    }
}

int main()
{

    vector<int> v1={4,6,2,8,3};
    bubbleSort(v1);

    for (int i = 0; i <= v1.size()-1; i++)
    {
        cout<<v1[i]<<endl;
    }
    

    return 0;
}
