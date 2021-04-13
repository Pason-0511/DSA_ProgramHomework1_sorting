#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//InsertionSort
class InsertionSort
{
    public:
        InsertionSort(int number);
        void insert(int e, int *a, const int i);
        void insertionSort();
        void getInitialArray(int i,int x);
        void Output();
    private:
        int *a;
        int n;
};
InsertionSort::InsertionSort(int number)
{
    n = number;
    a = new int[n+1];
}
void InsertionSort::insert(int e,int*a,int i)
{
    a[0] = e;
    while(e<a[i])
    {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = e;
}
void InsertionSort::insertionSort()
{
    for (int j = 2; j <= n;j++)
    {
        int temp = a[j];
        insert(temp, a, j - 1);
    }
}
void InsertionSort::getInitialArray(int i,int x)
{
    a[i] = x;
}
void InsertionSort::Output()
{
    cout << "InsertionSort:";
    for (int i = 1; i <= n;i++)
        cout << a[i] << " ";
    cout << "\n";
    delete[] a;
}
//InsertionSort 

//QuickSort
class QuickSort
{
    public:
        QuickSort(int number);
        void quickSort();
        void quickSort(int *a,int left,int right);
        void getInitialArray(int i,int x);
        void Output();
    private:
        int n;
        int left;
        int right;
        int *a;
};
QuickSort::QuickSort(int number)
{
    n = number;
    left = 1;
    right = n;
    a = new int[n + 2];
}
void QuickSort::quickSort(int *a, int left, int right)
{
    if(left<right)
    {
        int i = left;
        int j = right + 1;
        int pivot = a[left];
        do
        {
            do
                i++;
            while (a[i] < pivot);
            do
                j--;
            while (a[j] > pivot);
            if(i<j)
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        while(i<j);
    int temp = a[left];
    a[left] = a[j];
    a[j] = temp;
    quickSort(a, left, j - 1);
    quickSort(a, j + 1, right);
    }    
}
void QuickSort::quickSort()
{
    if(left<right)
    {
        int i = left;
        int j = right + 1;
        int pivot = a[left];
        do
        {
            do
                i++;
            while (a[i] < pivot);
            do
                j--;
            while (a[j] > pivot);
            if(i<j)
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        while(i<j);
    int temp = a[left];
    a[left] = a[j];
    a[j] = temp;
    quickSort(a, left, j - 1);
    quickSort(a, j + 1, right);
    }
}
void QuickSort::getInitialArray(int i,int x)
{
    a[i] = x;
}
void QuickSort::Output()
{
    cout << "QuickSort:    ";
    for (int i = 1; i <= n;i++)
    cout << a[i] << " ";
    cout << "\n";
    delete[] a;
}
//QuickSort

//MergeSort
class MergeSort
{
    public:
        MergeSort(int number);
        void Merge(int *initialList, int *mergedList, int l, int m, int n);
        void MergePass(int *initialList, int *resultList, int n, int s);
        void mergeSort();
        void getInitialArray(int i,int x);
        void Output();
    private:
        int *a;
        int n;
};
MergeSort::MergeSort(int number)
{
    n = number;
    a = new int[n + 1];
}
void MergeSort::Merge(int *initialList, int *mergedList, int l, int m, int n)
{
    int i1 = l;
    int iResult = l;
    int i2 = m + 1;
    for ( i1 = l,  iResult = l,  i2 = m + 1; i1 <= m && i2 <= n;iResult++)
        {
            if(initialList[i1]<=initialList[i2])
            {
                mergedList[iResult] = initialList[i1];
                i1++;
            }
            else
            {
                mergedList[iResult] = initialList[i2];
                i2++;            
            }
        }
    if(i1>m)
    {
        for (int t = i2; t <= n;t++)
        {
            mergedList[iResult+t-i2] = initialList[t];
        }
    }
    else
        for (int t = i1; t <= m;t++)
        {
            mergedList[iResult+t-i1] = initialList[t];
        }
}
void MergeSort::MergePass(int *initialList, int *resultList, int n, int s)
{
    int i = 1;
    for (i = 1; i <= n - 2 * s + 1;i+=2*s)
        Merge(initialList, resultList, i, i + s - 1, i + 2 * s - 1);
    if((i+s-1)<n)
        Merge(initialList, resultList, i, i + s - 1, n);
    else
        for (int t = i; t <= n;t++)
            resultList[t] = initialList[t];
}
void MergeSort::mergeSort()
{
    int *tempList = new int[n + 1];
    for (int l = 1; l < n;l*=2)
    {
        MergePass(a, tempList, n, l);
        l *= 2;
        MergePass(tempList, a, n, l);
    }
    delete[] tempList;
}
void MergeSort::getInitialArray(int i,int x)
{
    a[i] = x;    
}
void MergeSort::Output()
{
    cout << "MergeSort:    ";
    for (int i = 1; i <= n;i++)
    cout << a[i] << " ";
    cout << "\n";
    delete[] a;
}
//MergeSort

void outputInitialArray(int*a,const int n)
{
    cout << "InitialArray: ";
    for (int i = 1; i <= n;i++)
        cout << a[i] << " ";
    cout << "\n";
}
int main()
{
    clock_t start_I,end_I,start_Q,end_Q,start_M,end_M;
    int n = 0;
    cin >> n;
    int *Array;
    Array = new int[n+1];
    Array[0] = 0;
    InsertionSort I(n);
    QuickSort Q(n);
    MergeSort M(n);
    srand(time(NULL));
    for (int i = 1; i <=n;i++)
    {
        int a = rand() % 5;
        int b = rand() % 10;
        int c = rand() % 10;
        int d = rand() % 10;
        int e = rand() % 10;
        int x = a * 10000 + b * 1000 + c * 100 + d * 10 + e * 1 + 1;
        Array[i] = x;
        I.getInitialArray(i, x);
        Q.getInitialArray(i, x);
        M.getInitialArray(i, x);
    }
    outputInitialArray(Array,n);
    start_I = clock();
    I.insertionSort();
    end_I = clock();
    I.Output();
    start_Q = clock();
    Q.quickSort();
    end_Q = clock();
    Q.Output();
    start_M = clock();
    M.mergeSort();
    end_M = clock();
    M.Output();
    outputInitialArray(Array,n);
    double time_I = (double)(end_I - start_I)/1000;
    double time_Q = (double)(end_Q - start_Q)/1000;
    double time_M = (double)(end_M - start_M)/1000;
    cout <<"InsertionSort_time :" <<time_I << "s" <<endl;
    cout <<"QuickSort_time :" <<time_Q << "s" <<endl;
    cout <<"MergeSort_time :" <<time_M << "s" <<endl;
    delete[] Array;
}