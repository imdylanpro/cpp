/*
 * main.cpp
 *
 *  Created on: Jun 29, 2025
 *      Author: dylan
 */

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex threadLocker;

void count_thread1() {

	threadLocker.lock();
	//	int counter = 0;

	for (int i = 0; i <= 20; i++) {
		cout << "First thread counter value: " << i << endl;;
	}

	threadLocker.unlock();
}

void count_thread2() {

	threadLocker.lock();
	//	int counter = 20;

	for (int i = 20; i >= 0; i--) {
		cout << "Second thread counter value: " << i << endl;
	}

	threadLocker.unlock();
}

int main() {

	cout << "Beginning threading countup and countdown!" << endl;

	thread t1(count_thread1);
	thread t2(count_thread2);

	t1.join();
	t2.join();

	return 0;
}

