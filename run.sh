#!/usr/bin/bash
echo bubble sort - 1
echo insertion sort - 2
echo choice sort - 3
echo heap sort - 4
read type
echo -n > whatsort.txt
echo "$type" >> whatsort.txt
if [[ $type -eq 1 ]]
then
	g++ /home/anastasia/sorts/sorts/bubblesort.cpp -o bubblesort
	./bubblesort
elif [[ $type -eq 2 ]]
then
	g++ /home/anastasia/sorts/sorts/insert.cpp -o insertionsort
	./insertionsort
elif [[ $type -eq 3 ]]
then
	g++ /home/anastasia/sorts/sorts/choice.cpp -o choicesort
	./choicesort
elif [[ $type -eq 4 ]]
then
	g++ /home/anastasia/sorts/sorts/heap.cpp -o heapsort
	./heapsort
fi

python visualize.py
python video.py
