#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <random>
#include <string>

//Функция, которая меняет местами два элемента по индексам
void replace(int index1, int index2, std::vector<int>& array) {
    array[index1] = array[index1] + array[index2];
    array[index2] = array[index1] - array[index2];
    array[index1] = array[index1] - array[index2];
}

std::vector<int> bubblesort(std::vector<int> array) {
	std::ofstream infile("/home/anastasia/sorts/sorts/bubble.txt");
	infile.is_open();

    for (int i = 0; i < array.size() - 1; i++) {
        for (int j = 0; j < array.size() - 1 - i; j++) {
            if (array[j] >= array[j + 1]) {
                replace(j, j + 1, array);
		for(int c=0; c<array.size(); c++) {
			infile<<array[c]<< " ";
           	 }
		infile << std:: endl;
       		 }
   	 }
	}
    infile.close();
    return array;
}

//Генерация рандомного значения в диапазоне
int rand_uns(int min, int max) {
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);

}


int main() {
        std::vector<int> arr;
        for (int k = 0; k < 100; k++) {
            arr.push_back(rand_uns(0, 500));
        }
        bubblesort(arr);
       	return 0;
}

