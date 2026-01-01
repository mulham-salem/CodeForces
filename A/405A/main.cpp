#include <iostream>

using namespace std;

void printArray(int a[], int n)
{
  for(int i=0; i<n; i++)
  {
     cout << a[i] << " ";
  }
       cout << endl;
}
void swap(int &x, int &y)
{
  int temp = x;
  x = y;
  y = temp;
}
void bubbleSort(int a[], int n)
{
  for(int i=0; i<n; i++)
  {
     for(int j=0; j<n-1; j++)
     {
        if(a[j] > a[j+1])
        swap(a[j], a[j+1]);
     }

  }

}
int main()
{
    const int nmax = 100;
    int n;
    int a[nmax];
    cin >> n;
    for(int i=0; i<n; i++)
    {
      cin >> a[i];
    }
    bubbleSort(a, n);
    printArray(a, n);


    return 0;
}