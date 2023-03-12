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

int main()
{

	std::ofstream infile("/home/anastasia/sorts/sorts/insert.txt");
	infile.is_open();
	int n =100;
	int a[n], t, j;
	//введение массива
	for (int i=0; i<n; i++)
	{
		a[i]=rand_uns(0,500);

	}

	//сортировка Вставкой
	for (int i=1; i<n; i++)
	{
		t=a[i];
		for (j=i-1; j>=0 && a[j]>t; j--)
		{
			a[j+1]=a[j];
			a[j]=t;
		for (int c=0; c<n; c++)
		{
			infile<<a[c]<<" ";
		}

		infile<<std::endl;
		}
	}
	infile.close();
}
