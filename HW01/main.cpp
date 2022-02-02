#include "ArrayChanger.h"
#include <iostream>
#include <string>

#define CIN_IGNORE 2147483647

void inputHandling(int& val, const char* prompt) {
	do
	{
		std::cout << prompt << std::endl;
		if (std::cin.fail() || std::cin.bad())
		{
			std::cin.clear();
			std::cin.ignore(CIN_IGNORE, '\n');
		}
		std::cin >> val;
	} while (std::cin.fail() || std::cin.bad());
}

int inputProcessing(int* arr, int n) {
	std::cout << "What do you want to do?: \n1 - fill the array with pseudorandom numbers, 2 - input numbers yourself, 9 - end the execution of this program" << std::endl;
	char action;
	bool repeat = false;
	do
	{
		std::cin >> action;
		switch (action)
		{
		case '1':
			return 1;
		case '2':
			repeat = false;
			break;
		case '9':
			return 9;
		default:
			repeat = true;
			std::cout << "Try again" << std::endl;
			break;
		}
	} while (repeat);
	std::cout << "Now input " << n << " numbers" << std::endl;
	for (size_t i = 0; i < n; i++)
	{
		int newVal;
		inputHandling(newVal, ("Index: " + std::to_string(i)).c_str());
		arr[i] = newVal;
	}
	return 2;
}

void outputArr(int* arr, int n) {
	for (int i = 0; i < n - 1; i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << arr[n - 1] << std::endl;
}

int main() {
	int n;
	inputHandling(n, "Please input the length of the array");
	int* arr = new int[n];
	int inputResult = inputProcessing(arr, n);
	bool endProgram = false;
	if (inputResult == 1)
	{
		int randomMax;
		inputHandling(randomMax, "Set max random integer number");
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % randomMax + 1;
		}
	}
	if (inputResult == 9)
	{
		return 0;
	}

	outputArr(arr, n);

	std::cout << "Task 4-5 - shift all numbers in the array by a certain \"step\"" << std::endl;

	int step;
	inputHandling(step, "Input step (task 4-5)");

	ArrayChanger::FourFive(arr, n, step);

	std::cout << "After transformation (task 4-5)" << std::endl;
	outputArr(arr, n);

	std::cout << "Task 7 - swap first and second halves" << std::endl;

	ArrayChanger::Seven(arr, n);

	std::cout << "After transformation (task 7)" << std::endl;
	outputArr(arr, n);

	std::cout << "Task 10 - insert value after max element \nTask 11 - insert value before max element" << std::endl;

	int value;
	inputHandling(value, "Input value (task 10)");

	n = ArrayChanger::TenEleven(arr, n, value, true);
	std::cout << "After transformation (task 10)" << std::endl;
	outputArr(arr, n);

	inputHandling(value, "Input value (task 11)");

	n = ArrayChanger::TenEleven(arr, n, value, false);
	std::cout << "After transformation (task 11)" << std::endl;
	outputArr(arr, n);

	delete[] arr;

	return 0;
}