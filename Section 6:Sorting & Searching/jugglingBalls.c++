#include <vector>
using namespace std;

vector<int> sortBalls(vector<int> balls)
{
    // sort the balls in place in a single pass (O(N) time, O(1) space)
    int low = 0;
    int mid = 0;
    int high = balls.size() - 1;
    // Start the loop:
    while (high > mid)
    {
        if (balls[mid] == 0)
        {
            swap(balls[mid], balls[low]);
            mid++;
            low++;
        }
        else if (balls[mid] == 1)
        {
            mid++;
        }
        else if (balls[mid] == 2)
        {
            swap(balls[mid], balls[high]);
            high--;
        }
    }
    return balls;
}