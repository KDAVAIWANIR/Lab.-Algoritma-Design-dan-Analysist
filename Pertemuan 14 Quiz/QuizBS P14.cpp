#include <iostream>
using namespace std;

int binarySearch (int arr[], int n, int target){
	int low = 0;
	int high = n - 1;
	
	while (low <= high) {
		int mid = (low + high) / 2;
		
		if (arr[mid] == target)
			return mid;
		
		else if (arr[mid] < target)
			low = mid + 1;
		
		else
			high = mid - 1;
	}
		return -1;
}
int main(){
	int arr[] = {11, 22, 33, 44, 55, 66, 77};
	int n = sizeof(arr) / sizeof(arr[0]);
	int target;
	
	cout << " Masukkan angka yang ingin dicari : ";
	cin >> target;
	
	int result = binarySearch (arr, n, target);
	
	if (result != -1)
		cout << " Angka ditemukan di indeks ke " << result << endl;
		
		else 
		cout << " Angka tidak ditemukan " << endl;
		
		return 0;
}
