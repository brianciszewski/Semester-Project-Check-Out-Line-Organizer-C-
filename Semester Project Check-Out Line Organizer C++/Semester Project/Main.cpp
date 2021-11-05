#include<iostream>
#include <time.h>
#include <queue>
using namespace std;

// version 2. Forget objects, arrays make life easy.

int main() {
	srand((int)time(0));
	int counter = 0;
	int queueLengthMax = 0;
	int empty = 0;
	int maxWait = 0;
	int customersArrived = 0;

	int customerArrival = (rand() % 3) + 1;
	int serviceTime = (rand() % 4) + 1;
	queue<int> Q;
	vector<int> L2;
	vector<int> L3;
	vector<int> L4;

	
	for (int i = 0; i < 720; i++) {

		customerArrival -= 1;

		if (customerArrival == 0) {
			cout << "A new customer has arrived.\n";
			customerArrival = (rand() % 3) + 1;
			Q.push(serviceTime);
			L2.push_back(i);
			customersArrived += 1;
			// find max number of elements in Queue
			if ((int)Q.size() > (int)queueLengthMax) {
				queueLengthMax = Q.size();
			}
		}
		// assigns service times after customer is served and next in queue is up front.
		if (!Q.empty()) {
			serviceTime -= 1;
			if (serviceTime == 0) {
				cout << "A customer has been serviced.\n";
				serviceTime = (rand() % 4) + 1;
				Q.pop();
				L3.push_back(i);
				counter += 1;
			}
		}

		// times the queue was empty.
		if (Q.empty() == true) {
			empty += 1;
		}
	}

	// finds the longest wait for any one customer

	for (int k = 0; k < (int)L3.size(); k++) {
		L4.push_back(L3[k] - L2[k]);
	}

	for (int l = 0; l < (int)L4.size(); l++) {
		if (L4[l] > maxWait) {
			maxWait = L4[l];
		}
	}

	cout << "\n\nTotal customers processed:" << counter;
	cout << "\nTotal customers arrived:" << customersArrived;
	cout << "\nThe line reached a maximum of " << queueLengthMax << " people long.\n";
	cout << "The line was empty " << empty << " times.\n";
	cout << "The longest wait for any one customer was " << maxWait << " minutes.\n";
}

/*

 Changing the arrival time from 4 minutes to 3 minutes will increase the average number of arrivals. Thise is because at an arrival time of 
 1-4 minutes, (1+2+3+4)/4 = 2.5 while (1+2+3)/3 = 2. The difference in average RNG is 25%. After running the code 10 time with each arrival 
 time, an average of 288.8 customers arrived for 1-4 minutes and 358 for 1-3 minutes,
 288.8 * 5/4 = 361
 A 25% increase in customers arrived by changing the arrival time to every 1-3 minutes. 

 I chose not to use objects for customers because making ~300 objects seemed much more complicated and innefficient compared to making
 2 arrays to store their apperaance and service intervals. Lists could replace the vectors, but cycling through a vector's index values
 seemed simplier than deleting an element of the list each loop iteration. 
*/