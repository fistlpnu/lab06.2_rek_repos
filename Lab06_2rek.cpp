#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <vector> // Додали бібліотеку для вектора

using namespace std;

void printArrayRecursive(const vector<int>& arr, int size, int index = 0);
void findMaxOddRecursive(const vector<int>& arr, int size, int index, int& maxOdd, int& maxOddIndex);
void swapLastWithMaxOdd(vector<int>& arr, int size, int maxOddIndex);
void fillArrayRecursive(vector<int>& arr, int size, int index, int minValue, int maxValue);

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << "Enter size array: ";
    cin >> n;

    vector<int> arr(n); // Використовуємо вектор замість звичайного масиву

    fillArrayRecursive(arr, n, 0, -35, 25);

    cout << "Initial array:\n";
    printArrayRecursive(arr, n);

    int maxOdd = INT_MIN;
    int maxOddIndex = -1;
    findMaxOddRecursive(arr, n, 0, maxOdd, maxOddIndex);

    if (maxOddIndex != -1)
    {
        swapLastWithMaxOdd(arr, n, maxOddIndex);

        cout << "Modified array:\n";
        printArrayRecursive(arr, n);
    }
    else
    {
        cout << "There are no odd elements in the array.\n";
    }

    return 0;
}

void printArrayRecursive(const vector<int>& arr, int size, int index)
{
    if (index == size)
    {
        cout << endl;
        return;
    }
    cout << setw(5) << arr[index];
    printArrayRecursive(arr, size, index + 1);
}

void findMaxOddRecursive(const vector<int>& arr, int size, int index, int& maxOdd, int& maxOddIndex)
{
    if (index == size)
    {
        return;
    }

    if (arr[index] % 2 != 0 && arr[index] > maxOdd)
    {
        maxOdd = arr[index];
        maxOddIndex = index;
    }

    findMaxOddRecursive(arr, size, index + 1, maxOdd, maxOddIndex);
}

void swapLastWithMaxOdd(vector<int>& arr, int size, int maxOddIndex)
{
    if (maxOddIndex != -1)
    {
        swap(arr[size - 1], arr[maxOddIndex]);
    }
}

void fillArrayRecursive(vector<int>& arr, int size, int index, int minValue, int maxValue)
{
    if (index == size)
    {
        return;
    }

    arr[index] = minValue + (rand() % (maxValue - minValue + 1));
    fillArrayRecursive(arr, size, index + 1, minValue, maxValue);
}
