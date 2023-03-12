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
	std::ofstream infile("/home/anastasia/sorts/sorts/choice.txt");
	infile.is_open();
	int n =100;
	int a[n], j = 0, t=0;
	//введение массива
	for (int i=0; i<n; i++)
	{
	a[i]=rand_uns(0, 500);
	}

	//сортировка Выбором
	for(int i=0; i<n; i++)
	{
		j = i;
		for(int k = i; k<n; k++)
		{
			if(a[j]>a[k])
			{
				j = k;
			}
		}
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		for (int c=0; c<n; c++)
		{
			infile<<a[c]<<" ";
		}
		infile<<std::endl;
	}
	infile.close();
}
