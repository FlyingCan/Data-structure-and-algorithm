#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int Partition1(vector<int> &nums, int left, int right)
{ //分割策略1
    int pivot = nums[left];
    while (left < right)
    {
        while (left < right && nums[right] > pivot)
            right--;
        nums[left] = nums[right];
        while (left < right && nums[left] <= pivot)
            left++;
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;
}
int Partition(vector<int> &data, int start, int end)
{
    int pivot = data[start];
    int left = start, right = end;
    while (left < right)
    {
        while (left < right && data[left] <= pivot)
            left++;
        while (left < right && data[right] > pivot)
            right--;
        swap(data[left], data[right]);
    }
    swap(data[left], pivot);
    return left;
}
void quickSort(vector<int> &datas, int start, int end)
{
    if (left >= right)
        return;
    else
    {
        int pivot = Partition1(datas, start, end);
        quickSort(datas, start, pivot - 1);
        quickSort(datas, pivot + 1, end);
    }
}
int main(int argc, char const *argv[])
{
    vector<int> nums({8, 9, 1, 2, 3, 6, 7});
    quickSort(nums, 0, 6);
    for (auto a : nums)
        cout << a << "";
    return 0;
}
