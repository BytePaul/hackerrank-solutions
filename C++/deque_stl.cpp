// Problem: Dequel STL
// Link: https://www.hackerrank.com/challenges/deque-stl/problem
// Language: C++
// Difficulty: Medium


#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> dq; // Deque to store indices of elements in the window

    // Process the first k elements (the first window)
    for (int i = 0; i < k; ++i) {
        // Remove elements that are smaller than the current element
        // as they are not useful for finding the max
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        // Add the current index to the deque
        dq.push_back(i);
    }

    // Process the rest of the array
    for (int i = k; i < n; ++i) {
        // The element at the front of the deque is the largest for the last window
        cout << arr[dq.front()] << " ";

        // Remove elements that are out of the current window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove elements that are smaller than the current element
        // as they are not useful for finding the max
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        // Add the current index to the deque
        dq.push_back(i);
    }

    // Print the maximum for the last window
    cout << arr[dq.front()] << endl;
    }

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
