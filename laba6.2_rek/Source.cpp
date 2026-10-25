#include <iostream>
#include <iomanip>

using namespace std;

void readArray(int a[], int n, int i = 0)
{
    if (i >= n)
    {
        return;
    }

    cin >> a[i];

    readArray(a, n, i + 1);
}

void printArray(const int a[], int n, int i = 0)
{
    if (i >= n)
    {
        cout << endl;
        return;
    }

    cout << setw(5) << a[i];

    printArray(a, n, i + 1);
}

void findMinMax(const int a[], int n,
    int& iMin, int& iMax, int i = 1)
{
    if (i >= n)
    {
        return;
    }

    if (a[i] < a[iMin])
    {
        iMin = i;
    }

    if (a[i] > a[iMax])
    {
        iMax = i;
    }

    findMinMax(a, n, iMin, iMax, i + 1);
}

int main()
{
    const int MAX = 100;
    int a[MAX];
    int n;

    cout << "Enter n (1..100): ";
    cin >> n;

    if (!cin || n < 1 || n > MAX)
    {
        return 1;
    }

    cout << "Enter array elements:" << endl;
    readArray(a, n);

    cout << "Array:" << endl;
    printArray(a, n);

    int iMin = 0;
    int iMax = 0;

    findMinMax(a, n, iMin, iMax);

    cout << "Minimum index = " << iMin << endl;
    cout << "Maximum index = " << iMax << endl;

    return 0;
}