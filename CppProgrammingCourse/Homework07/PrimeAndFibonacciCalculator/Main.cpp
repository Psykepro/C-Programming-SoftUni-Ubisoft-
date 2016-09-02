#include <iostream>
#include <Windows.h>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx;
static int fibonacciCounter = 0;
static int primeNumberCounter = 0;

//////////////////////////////////////////////////////////////////////
// Stack overflowing with the recursive way for fibonacciCalculator //
//////////////////////////////////////////////////////////////////////

//unsigned long long fibonacciCalculator(unsigned long long previousResult[2])
//{
//	mtx.lock();
//
//	if (previousResult[0] >= ULLONG_MAX || previousResult[1] >= ULLONG_MAX)
//	{
//		cout << ">>> FIBONACCI <<< Maximum value of unsigned long long reached!" << endl;
//		return 0;
//	}
//
//	int startClock = clock();
//	Sleep(10);
//	unsigned long long previousSecondNumber = previousResult[1];
//	previousResult[1] = previousResult[0] + previousSecondNumber;
//	previousResult[0] = previousSecondNumber;
//	fibonacciCounter++;
//	printf("Fibonacci  %d, %d ms.\n", fibonacciCounter, clock() - startClock);
//
//	mtx.unlock();
//	return fibonacciCalculator(previousResult);
//}

void fibonacciCalculator(unsigned int startingValues[2])
{
	bool isOutOfRangeReached = false;
	unsigned long long firstValue = startingValues[0];
	unsigned long long secondValue = startingValues[1];
	unsigned long long currentFibonacci;


	while (!isOutOfRangeReached)
	{
		if (firstValue >= ULLONG_MAX || secondValue >= ULLONG_MAX)
		{
			mtx.lock();
			cout << ">>> FIBONACCI <<< Maximum value of unsigned long long reached!" << endl;
			mtx.unlock();
			isOutOfRangeReached = true;
			break;
		}

		auto begin = chrono::high_resolution_clock::now();
		Sleep(10);
		currentFibonacci = firstValue + secondValue;
		firstValue = secondValue;
		secondValue = currentFibonacci;
		fibonacciCounter++;
		mtx.lock();
		auto end = chrono::high_resolution_clock::now();
		auto dur = end - begin;
		auto ms = chrono::duration_cast<chrono::milliseconds>(dur).count();
		printf("Fibonacci %d, %lld ms.\n", fibonacciCounter, ms);
		mtx.unlock();
	}
}

void primeNumberCalculator(unsigned int startingNumber)
{
	bool isPrime;
	int currentNumber = startingNumber;
	bool isOutOfRangeReached = false;
	while (!isOutOfRangeReached)
	{
		auto begin = chrono::high_resolution_clock::now();
		Sleep(10);
		isPrime = true;
		if (currentNumber > 1)
		{
			for (int i = 2; i <= currentNumber / 2; i++)
			{
				if (currentNumber % i == 0)
				{
					isPrime = false;
					break;
				}

			}
			if (isPrime)
			{
				primeNumberCounter++;
				mtx.lock();
				auto end = chrono::high_resolution_clock::now();
				auto dur = end - begin;
				auto ms = chrono::duration_cast<chrono::milliseconds>(dur).count();
				printf("Prime %d, %lld ms.\n", primeNumberCounter, ms);
				mtx.unlock();
			}
		}
		currentNumber++;
		if (currentNumber >= ULLONG_MAX)
		{
			mtx.lock();
			cout << ">>> PRIME <<< Maximum value of unsigned long long reached!" << endl;
			mtx.unlock();
			isOutOfRangeReached = true;
		}
	}
}

int main()
{
	unsigned int startingFibonacciNumbers[2] = { 0, 1 };
	unsigned int startingNumber = 1;

	thread primenThread(primeNumberCalculator, startingNumber);
	thread fibonacciThread(fibonacciCalculator, startingFibonacciNumbers);


	primenThread.join();
	fibonacciThread.join();


	system("pause");
	return 0;
}