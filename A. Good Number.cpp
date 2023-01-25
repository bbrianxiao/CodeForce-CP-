//Implementation
//1100 pts
//CF
//Let's call a number k-good if it contains all digits not exceeding k (0, ..., k). 
//You've got a number k and an array a containing n numbers. 
///Find out how many k-good numbers are in a 
//(count each number every time it occurs in array a).
//Solve using unordered_set


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;



int main() {
    int n, k;
    cin >> n >> k;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int num = 0;
    int dig;
    
    //create an unordered_set
    unordered_set<int> s;
    
    //storing the unique digits in the unordered_set
    for (int i = 0; i < n; i++) {
        while (arr[i] > 0) {
            dig = arr[i] % 10;
            if ((dig <= k) && (dig >= 0)) {
                s.insert(dig);
            }
            arr[i] = arr[i] / 10;
        }

        //count the number of elements and compare to k + 1
        if (s.size() == k + 1) {
            num++;
        }

        //empty the set
        s.clear();
    }
    cout << num << endl;
    return 0;
}
    
    
