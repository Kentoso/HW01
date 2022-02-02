#include "ArrayChanger.h"
#include <cmath>

void ArrayChanger::FourFive(int* arr, int n, int step) {
	int* copy = new int[n];
	for (int i = 0; i < n; i++)
	{
		copy[i] = arr[i];
	}
	if (std::abs(step) >= n)
	{
		// ((step > 0) - (step < 0)) - get the sign of step
		int a = ((step > 0) - (step < 0));
		step = ((step > 0) - (step < 0)) * (std::abs(step) % n);
	}
	for (int i = 0; i < n; i++)
	{
		if (i + step < 0)
		{
			arr[(n + (i + step)) % n] = copy[i];
		}
		else {
			arr[((i + step) % n)] = copy[i];
		}
	}
	delete[] copy;
}

void ArrayChanger::Seven(int* arr, int n) {
	ArrayChanger::FourFive(arr, n, std::ceil((double)n / 2));
}

int ArrayChanger::TenEleven(int* &arr, int n, int value, bool after) {
	int* copyArr = new int[n + 1];
	int max = -1, maxIndex = -1;
	for (int i = 0; i < n; i++)
	{
		copyArr[i] = arr[i];
		if (arr[i] > max)
		{
			max = arr[i];
			maxIndex = i;
		}
	}
	if (after)
	{
		for (int i = n; i >= maxIndex + 1; i--)
		{
			copyArr[i] = copyArr[i - 1];
		}
		copyArr[maxIndex + 1] = value;
	}
	else
	{
		for (int i = n; i >= maxIndex; i--)
		{
			copyArr[i] = copyArr[i - 1];
		}
		copyArr[maxIndex] = value;
	}

	delete[] arr;
	arr = copyArr;
	return n + 1;
}