#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

int rand_uns(int min, int max)
{
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}

void swap (int &a, int &b)
{
	int t=a;
	a=b;
	b=t;
}

void heapify (int arr[100], int n, int i)
{
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;

	if (left < n && arr[left] > arr[largest])
	{
		largest = left;
	 }
	if (right < n && arr[right] > arr[largest])
	{
		largest = right;
	}
	if (largest != i)
	{
	swap(arr[i], arr[largest]);
	heapify (arr, n, largest);
	}
}

void heap_sort (int arr[100], int n)
{
	std::ofstream infile("/home/anastasia/sorts/sorts/heap.txt");
	infile.is_open();
	for (int i = n/2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
		for (int c=0; c<n; c++)
		{
			infile<<arr[c]<<" ";
		}
		infile<<std::endl;
	}
	infile.close();
}

int main()
{
	int n = 100;
	int arr[n];
	for (int i=0; i<n; i++)
	{
		arr[i]=rand_uns(0,500);
	}

	heap_sort(arr, n);
	return 0;
}
