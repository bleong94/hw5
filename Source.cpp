#include <iostream>
#include <stack>
#include <fstream>
#include <vector>
#include <cstring>
#include <string> 

using namespace std;

bool get_ints_from_file(int num[10000], string filename);
int bubble_sort(int A[10000], int n);
int InsertionSort(int A[], int n);
int shell_sort(int A[], int n);
void merge(int A[], int low, int high, int mid);
void MergeSort(int A[], int low, int high);
int partition(int A[], int low, int high);
void qsort(int A[], int low, int high);
void swap(int *x, int *y);
void sort_random();
void sort_nearly();
void sort_reversed();
void sort_unique();

int main()
{
	
	sort_random();
	sort_nearly();
	sort_reversed();
	sort_unique();

	system("pause");

}

void sort_random()
{
	//below is a test to see if get_ints_from_file works properly
	/*int test[10000];
	get_ints_from_file(test, "Random.txt");
	cout << test[0] << endl;*/
	cout << "Random" << endl;
	int A[10000];
	int original[10000];

	get_ints_from_file(original, "Random.txt");

	for (int i = 0; i < 10000; i++) //sets A to original
	{
		//cout << original[i] << endl;
		A[i] = original[i];
	}

	//cout << original[0];

	cout << "bubble swaps: " << bubble_sort(A, 10000) << endl;

	//test to see if sorted 
	/*for (int i = 0; i < 10000;i++)
	{
	cout << A[i] << endl;
	}*/

	for (int i = 0; i < 10000; i++) //resets A so unsorted
	{
		A[i] = original[i];
	}

	cout << "insertion swaps: " << InsertionSort(A, 10000) << endl;

	for (int i = 0; i < 10000; i++) //resets A so unsorted
	{
		A[i] = original[i];
	}

	cout << "shell swaps: " << shell_sort(A, 10000) << endl;
}

void sort_nearly()
{
	cout << "nearly" << endl;
	int A[10000];
	int original[10000];

	get_ints_from_file(original, "NearlySorted.txt");

	for (int i = 0; i < 10000; i++) //sets A to original
	{
		A[i] = original[i];
	}

	//cout << original[0];

	cout << "bubble swaps: " << bubble_sort(A, 10000) << endl;

	//test to see if sorted 
	/*for (int i = 0; i < 10000;i++)
	{
	cout << A[i] << endl;
	}*/

	for (int i = 0; i < 10000; i++) //resets A so unsorted
	{
		A[i] = original[i];
	}

	cout << "insertion swaps: " << InsertionSort(A, 10000) << endl;

	for (int i = 0; i < 10000; i++) //resets A so unsorted
	{
		A[i] = original[i];
	}

	cout << "shell swaps: " << shell_sort(A, 10000) << endl;
}

void sort_reversed()
{
	cout << "reversed" << endl;
	
	int A[10000];
	int original[10000];

	get_ints_from_file(original, "Reversed.txt");

	for (int i = 0; i < 10000; i++) //sets A to original
	{
		A[i] = original[i];
	}

	//cout << original[0];

	cout << "bubble swaps: " << bubble_sort(A, 10000) << endl;

	//test to see if sorted 
	/*for (int i = 0; i < 10000;i++)
	{
	cout << A[i] << endl;
	}*/

	for (int i = 0; i < 10000; i++) //resets A so unsorted
	{
		A[i] = original[i];
	}

	cout << "insertion swaps: " << InsertionSort(A, 10000) << endl;

	for (int i = 0; i < 10000; i++) //resets A so unsorted
	{
		A[i] = original[i];
	}

	cout << "shell swaps: " << shell_sort(A, 10000) << endl;
}

void sort_unique()
{
	cout << "unique" << endl;
	
	int A[10000];
	int original[10000];

	get_ints_from_file(original, "FewUnique.txt");

	for (int i = 0; i < 10000; i++) //sets A to original
	{
		A[i] = original[i];
	}

	//cout << original[0];

	cout << "bubble swaps: " << bubble_sort(A, 10000) << endl;

	//test to see if sorted 
	/*for (int i = 0; i < 10000;i++)
	{
	cout << A[i] << endl;
	}*/

	for (int i = 0; i < 10000; i++) //resets A so unsorted
	{
		A[i] = original[i];
	}

	cout << "insertion swaps: " << InsertionSort(A, 10000) << endl;

	for (int i = 0; i < 10000; i++) //resets A so unsorted
	{
		A[i] = original[i];
	}

	cout << "shell swaps: " << shell_sort(A, 10000) << endl;
}



//***********This function gets ints from a file and puts them in an int vector*******************
bool get_ints_from_file(int num[10000], string filename)
{
	ifstream in;
	char cNum[10]; 
	in.open(filename);

	if (!in.is_open()) //check if file is open
	{
		cout << "file not open" << endl;
	
	}
	else
	{
		int i = 0;
		while (in.good()) //keeps reading file until end of file
		{
			in.getline(cNum, 10, ' ');  //gets nums as strings separated by spaces

			num[i] = atoi(cNum);
			
			i++;
		}

	}

	in.close();

	return true;
}


//function for bubble sort for array A having n elements
int bubble_sort(int A[10000], int n)
{
	int i, j, temp;
	int compare, swap;
	compare = swap = 0;

	for (i = 1; i < n; i++)  //number of passes
	{
		for (j = 0; j < n - 1; j++)  //j varies from 0 to n-i
		{
			if (A[j] > A[j + 1]) //compares two successive numbers
			{
				temp = A[j]; //swap A[j] with A[j+1]
				A[j] = A[j + 1];
				A[j + 1] = temp;
				swap++;
			}
			compare++;
		}
	}
	cout << "bubble comparisons: " << compare << endl;
	return swap;
}


int InsertionSort(int A[], int n)
{
	int i, j, element;
	int compare, swap;
	compare = swap = 0;

	for (i = 1; i < n; i++)
	{
		element = A[i];
		//insert ith element in 0 to i-1 array
		j = i;
		while ((j > 0) && (A[j - 1] > element))	//compare if A[j-1] > element
		{
			A[j] > A[j - 1];	//shift elements
			j = j - 1;
			swap++;
		}
		A[j] = element;		//place element at jth position
		compare++;
	}

	cout << "Insert Comparisons: " << compare << endl;
	return swap;
}

int shell_sort(int A[], int n)
{
	int temp, gap, i;
	int swapped;
	int compare, swap;
	compare = swap = 0;

	gap = n / 2;
	do
	{
		do
		{
			swapped = 0;
			for (i = 0; i < n - gap; i++)
			{
				if (A[i] > A[i + gap])
				{
					temp = A[i];
					A[i] = A[i + gap];
					A[i + gap] = temp;
					swapped = 1;
					swap++;
				}
				compare++;
			}
		} while (swapped == 1);
	} while ((gap = gap / 2) >= 1);

	cout << "shell comparisons: " << compare << endl;

	return swap;
}


void merge(int A[], int low, int high, int mid)
{
	int i, j, k, C[10000];
	i = low; //index for first part
	j = mid + 1; //index for second part
	k = 0; //index for array C

	while ((i <= mid) && (j <= high)) //merge arrays A & B in array C
	{
		if (A[i] < A[j])
			C[k] = A[i++];
		else
			C[k] = A[j++];
		k++;
	}

	while (i <= mid)
	{
		C[k++] = A[i++];
	}
	while (j <= high)
	{
		C[k++] = A[j++];
	}
	for (i = low, j = 0; i <= high; i++, j++)	//copy array C contents back to array A
	{
		A[i] = C[j];
	}
}

void MergeSort(int A[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSort(A, low, mid);
		MergeSort(A, mid + 1, high);
		merge(A, low, high, mid);
	}
}


void swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

int partition(int A[], int low, int high)
{
	int j = low;
	int pivot = A[low];
	for (int i = low + 1; i <= high; i++)
	{
		if (A[i] <= pivot)
		{
			j++;
			swap(A[i], A[j]);
		}
	}
	swap(A[j], A[low]);
	return j;
}

void qsort(int A[], int low, int high)
{
	int k;
	if (low < high)
	{
		k = partition(A, low, high);
		qsort(A, low, k - 1);
		qsort(A, k + 1, high);
	}
}