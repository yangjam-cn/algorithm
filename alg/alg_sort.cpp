/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: alg_sort.cpp
 * @Description: 排序算法
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-14 12:57:07
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-15 15:26:18
 */
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;
int *create_random_array(const int &length, const int &range);
void swap_value(int &a, int &b);
void print_array(int arr[], const int &length);
/*检查一个序列是否有序*/
bool is_sorted(int arr[], int length);
/*计算函数执行时间*/
time_t timer(int arr[], const int &length, void (*sortFun)(int [], const int &));
/*测试函数*/
void test(const int &length, const int &range, void (*sortFun)(int [], const int &));

/*选择排序*/
void select_sort(int arr[], const int &length);
/*插入排序*/
void insert_sort(int arr[], const int &length);
/*希尔排序*/
void shell_sort(int arr[], const int &length);
/*归并排序*/
void merge_sort(int arr[], const int &length);
void merge_sort(int *frst, int *last);
void merge(int *first, int *mid, int *last);
/*快速排序*/
void quick_sort(int arr[], const int &length);
void quick_sort(int *first, int *last);
int *partition(int *first, int *last);


int main(void)
{
    int length[] = {1000, 2000, 4000, 8000, 16000};
    int range = 1000;

    void (*sortFun[])(int [], const int &) = {select_sort, insert_sort, shell_sort
        , merge_sort, quick_sort};

    //debug
    /*
    int size = 12;
    int *arr = create_random_array(size, range);
    quick_sort(arr, size);
    print_array(arr, size);
    delete [] arr;
    */

    for (int size : length)
    {
        cout << size << endl;
        cout << "+++++++++++++++++" << endl;
        for (void (*func)(int [], const int &) : sortFun)
        {
            test(size, range, func);
            // cout << "*********************" << endl;
        }
    }
    return 0;
}


int *create_random_array(const int &length, const int &range)
{
    srand((unsigned int)time(NULL));

    int *arr = new int [length];

    for (int i = 0; i < length; ++i)
        arr[i] = rand() % range;

    return arr;
}


/*101^100 = 001*/
/*001^100 = 101*/
/*001^101 = 100*/
/*warning: 当a和b是同一对象的引用时，a = 0*/
void swap_value(int &a, int &b)
{
    if (a == b)
        return;
    a ^= b;
    b ^= a;
    a ^= b;
}


void print_array(int arr[], const int &length)
{
    for (int i = 0; i < length; i++)
        cout << arr[i] << '\t';
    cout << endl;
}


bool is_sorted(int arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}


time_t timer(int arr[], const int &length, void (*sortFun)(int [], const int &))
{
    time_t start = clock();
    sortFun(arr, length);
    time_t end = clock();
    return end - start;
}


void test(const int &length, const int &range ,void (*sortFun)(int [], const int &))
{
    int *arr = create_random_array(length, range);
    cout << is_sorted(arr, length) << '\t';
    unsigned int time = (unsigned int)timer(arr, length, sortFun);
    cout << time  << '\t';
    cout << is_sorted(arr, length) << endl;
    delete [] arr;
}


/*
 * @Function: select_sort
 * @Description: 选择排序
 * @Input: 
     * arr：数组名或首元素地址
    * length：数组元素数量
 * @Return: 无返回值
 * @Others: 
     * 1. 选择序列最小元素与序列首元素交换
    * 2. 排除首元素，对剩下序列重复1的操作
    * 3. 当序列只剩下一个元素时，结束算法
    * 每轮选择的元素都是当前序列最小元素，故一轮结束后的首元素必小于等于当前序列剩下元素，
    * 经过n-1轮循环后，必然有0<=1<=2<=3...<=n-1，故序列有序
 */
void select_sort(int arr[], const int &length)
{
    int indexOfMinVal = 0;    /*O(1)*/

    for (int i = 0; i < length - 1; ++i)    /*O(n-1)*/
    {
        indexOfMinVal = i;    /*O(1)*/

        for (int j = i + 1; j < length; ++j)    /*O(n-i-1)*/
        {
            if (arr[indexOfMinVal] > arr[j])
                indexOfMinVal = j;
        }
        swap_value(arr[indexOfMinVal], arr[i]);    /*O(1)*/
    }
}


/*
 * @Function: insert_sort
 * @Description: 插入排序
 * @Input: 
    * arr：数组名或数组首元素地址
    * length：数组元素数量
 * @Return: 无返回值
 * @Others: 
    * 当前序列有序，当新增元素小于序列尾部元素，将该元素往前移，直至移到序列合适位置
    * 当序列仅有唯一元素时，必然有序
    * 向有序序列中添加元素，将新增元素添加到序列合适位置，序列有序性不改变
    * 经n-2轮之后，n-1个元素构成的序列有序，第n个以同样方式插入时，序列有序性不改变
 */
void insert_sort(int arr[], const int &length)
{
    for (int i = 1; i < length; i++)    /*O(n - 1)*/
    {
        
        //int curIndex = i;    /*O(1)*/

        //while (curIndex > 0 && arr[curIndex] < arr[curIndex - 1])    /*O(i)*/
        //    swap_value(arr[--curIndex], arr[curIndex]);    
        //    /*==>swap(index - 1, index); index--*/

        int index = i - 1, temp = arr[i];

        while (index >= 0 && temp < arr[index])
        {
            arr[index + 1] = arr[index];
            --index;
        }    /*end while (index = -1 || temp > arr[index])*/
        arr[++index] = temp;
    }
}


/**
 * @Function: shell_sort
 * @Description: 希尔排序
 * @Input: 
    * arr：数组名或数组首元素地址
    * length：数组元素数量
 * @Return: 无返回值
 * @Others: 
    * 以一定间隔对数组进行多轮插入排序，每轮缩小间隔，直至间隔为1结束
    * 当间隔为1时，遍历到某元素，此时经插入排序前面序列必然已有序，若该元素无需移动，则操作为O(1)
 */
void shell_sort(int arr[], const int &length)
{
    int h = 1;
    while (h < length / 3)
        h = 3 * h + 1;
    
    while (h >= 1)
    {
        for (int i = h; i < length; i++)
        {
            int index = i - h, temp = arr[index];
 
            while (index >= 0 && temp < arr[index])
            {
                arr[index + h] = arr[index];
                index -= h;
            }    /*end while (index < 0 || temp >= arr[index])*/
            arr[index + h] = temp;
        }

        h = h / 3;
    }
}

/*
 * 若两个有序序列，同时从头遍历序列，每次较小值复制到新序列，最后当两个序列遍历完后，新序列有序
 * 当两个序列仅有一个元素时，序列有序，合并后新序列有序
 * 将序列均分为两份，分别经合并排序后，序列有序，将其按合并操作后，可以实现序列有序
 * 合并两个有序序列，时间操作为O(n+m)
 */
void merge_sort(int arr[], const int &length)
{
    if (length <= 1)
        return;
    
    merge_sort(arr + 0, arr + length - 1);
}
void merge_sort(int *first, int *last)
{
    if (last - first == 0)
    {
        return;
    }

    int *mid = first + (last - first) / 2;
    merge_sort(first, mid);
    merge_sort(mid + 1, last);
    merge(first, mid, last);
}
void merge(int *first, int *mid, int *last)
{
    int length = last - first + 1;
    int *temp = new int [length];
    for (int i = 0; i < length; i++)
        temp[i] = *(first + i);
    
    int left = 0, right = mid - first + 1, cnt = 0;
    while (cnt < length)
    {
        while (left <= mid - first && right <= length - 1)
        {
            if (temp[left] <= temp[right])
                first[cnt++] = temp[left++];
            else if (temp[left] > temp[right])
                first[cnt++] = temp[right++];
        }
        while (left <= mid-first)
            first[cnt++] = temp[left++];
        while (right <= length - 1)
            first[cnt++] = temp[right++];
    }
    
    delete [] temp;
}



void quick_sort(int arr[], const int &length)
{
    if (length <= 1)
        return;
    
    quick_sort(arr, arr + (length - 1));
}
void quick_sort(int *first, int *last)
{
    // static int cnt = 0;
    // cout << cnt++ << '\t' << last - first << endl;

    if (first < last)
    {
        int *loc = partition(first, last);
        quick_sort(first, loc - 1);
        quick_sort(loc + 1, last);
    }
}
int *partition(int *first, int *last)
{
    int temp = *first;

    while (first < last)
    {
        while ((first < last) && *last > temp)
            --last;
        *first = *last;
        while (first < last && *first <= temp)
            ++first;
        *last = *first;
    }    /*end while (first = last)*/
    *first = temp;
    return first;
}
/*
效率对比
length：1000，2000， 4000， 8000，160000
range：100
select_sort: 2    6    25    92    248
insert_sort: 1    4    19     48    166
shell_sort:   0    0    0      1      1
merge_sort: 1     1    1      2      4
quick_sort:  0     0   0      1      1
*/