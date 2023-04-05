#include <iostream>
#include <vector>
using namespace std;
//构建最大堆
void ShiftDown(vector<int> &nums, int i, int n)
{
    int l = 2 * i + 1; //左孩子
    int r = 2 * i + 2; //右孩子
    int min = i;
    if (l < n && nums[min] < nums[l])
    {
        min = l;
    } //有左孩子且比左孩子小
    if (r < n && nums[min] < nums[r])
    {
        min = r;
    }
    if (min != i)
    {
        int temp = nums[i];
        nums[i] = nums[min];
        nums[min] = temp;
        ShiftDown(nums, min, n);
    }
}
void BuildHeap(vector<int> nums)
{
    int p = nums.size() / 2 - 1;
    for (p; p >= 0; p--)
    {
        ShiftDown(nums, p, nums.size());
    }
}
void HeapSort(vector<int> &nums)
{
    BuildHeap(nums);
    for (int i = nums.size() - 1; i > 0; i--)
    {
        int t = nums[0];
        nums[0] = nums[i];
        nums[i] = t;
        ShiftDown(nums, 0, i); //因为只有根变了
    }
}
int main(int argc, char const *argv[])
{
    vector<int> nums({96, 85, 53, 47, 56, 38, 36, 12, 24});
    HeapSort(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
