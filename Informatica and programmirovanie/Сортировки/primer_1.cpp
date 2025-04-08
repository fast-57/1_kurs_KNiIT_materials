#include <iostream>
using namespace std;
//просеивание кучи
void heap(int *mas, int n, int i)
{
    int largest = i;   
    int l = 2*i + 1; 
    int r = 2*i + 2;
    if (l < n && mas[l] > mas[largest])
        largest = l;
    if (r < n && mas[r] > mas[largest])
        largest = r;
    if (largest != i)
    {
        swap(mas[i],mas[largest]);
        heap(mas, n, largest);
    }
}


void Sort(int *mas, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(mas, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(mas[0], mas[i]);
        heap(mas, i, 0);
    }
}

int main()
{
    int n; cin >> n;
    int *mas = new int [n];
    srand ((unsigned int)time(NULL));
    for(int i=0; i < n; i++)
        mas[i] = rand() % 11;
    for(int i=0; i < n; i++)
    cout << mas[i] << " ";
    cout << endl;
    Sort(mas, n);
    for(int i=0; i < n; i++)
    cout << mas[i] << " ";
    cout << endl;
 return 0;
}