#include <vector>
using namespace std;

pair<int, int> subarraySorting(vector<int> a)
{
    // Expected Optimal Complexity O(n) Time, O(1) Space
    // may be start with O(NLogN) and try to improve
    // complete this function
    int i = -1;
    int j = -1;
    int length = a.size();
    // Traversing array:
    for (int k = 1; k < length; k++)
    {
        if (a[k - 1] > a[k] and k == length - 1)
        {
            j = k;
        }
        //  Check unstability :
        else if (a[k - 1] > a[k] and a[k] < a[k + 1])
        {
            j = k;
        }
    }
    for (int k = 0; k < length; k++)
    {
        if (a[k] > a[j])
        {
            j = k - 1;
            break;
        }
    }
    if (i != -1)
    {
        return {i, j};
    }
    return {-1, -1};
}