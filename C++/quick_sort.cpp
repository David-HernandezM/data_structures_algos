//Description!
//1.- First we pass three arguments to de quicksort method, the arguments are the array, and the indexes of the corners points.
//2.- The case base (return), satisfies if b is greater than or equal to a.
//3.- then three variables will contain a+1, b and 0 (0 is temp).
//4.- while i is less than j, check both if the element in i is greater than the element in a, and te element in j is less or equal than element in a.
//    if it fulfills this, we swap the elements in i and j, then we increment the value of i and decrement the value of j. Else if the element in i is less or equal tan element in a, increment i, else increment j.
//5.- Then check ifthe element in i is greater than element in a, if it fulfills this, decrement i.
//6.- Finally we swap the element in i and a, and call two times quicksort method, one with parameters: array, a, i-1. And second with parameters: array, i+1,b.

//Explanation:
/*
The array is taken with its indices 0 and n-1.  In the recursive method, the base case will be when b is greater than or equal to a (indicating that there is only one element or none to check).
The algorithm needs a pivot to work, and this will be a, the variable i will check the elements less than a and j greater than a, if the element in i is greater than j, they will be exchanged, until i is greater than or equal to j.
Thiis will accommodate the elements smaller and larger than a, in the end, it will put a in the place of i so that this is fulfilled, this will continue to happen in i-1 and i+1, until reaching a single element.
In he end, the algorithm will be ordered
*/

#include <iostream>
using namespace std;

void quickSort(int[], int, int);
void printArray(int[], int);

int main() {
	int size = 51;
	int array[] = {88,47,85,70,92,17,58,21,84,10,61,20,45,1,9,93,16,
			41,77,42,8,36,95,86,39,87,51,52,28,57,3,40,72,11,53,
			13,80,49,62,32,73,14,33,79,66,90,15,81,94,59,88};
	cout << "Array:\n";
	printArray(array, size);
	cout << "\nSorted Array:\n";
	quickSort(array, 0, size-1);
	printArray(array, size);
	return 0;
}

void quickSort(int array[], int a, int b) {
	if (b <= a) return;
	int i = a+1;
	int j = b;
	int temp = 0;
	while (i < j) {
		if (array[i] > array[a] && array[j] <= array[a]) {
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			i++;
			j--;
		} else if (array[i] <= array[a]) {
			i++;
		} else {
			j--;
		}
	}
	if (array[i] > array[a]) {
		i--;
	}
	temp = array[i];
	array[i] = array[a];
	array[a] = temp;
	quickSort(array, a, i-1);
	quickSort(array, i+1, b);
}

void printArray(int array[], int length) {
	for (int i = 0; i < length; i++) {
        cout << array[i];
		if (i < length-1)
			cout << " - ";
	}
}