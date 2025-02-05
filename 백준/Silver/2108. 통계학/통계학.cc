#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int getMean(int*arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return round(float(sum) / size);
}

int getMedian(int* arr, int size) {
    if (size % 2 == 0) {
        return round(float(arr[size/2] + arr[size/2+1]) / 2);
    }
    return arr[size/2];
}

int getMode(int* arr, int size) {
    int maxCount = 0, maxVal, curCount = 0, curVal;
    bool secondFlag = false;
    for (int i = 0; i < size; i++) {
        if (curVal != arr[i]) {
            if (maxCount == curCount) {
                if (!secondFlag) {
                    maxVal = curVal;
                    maxCount = curCount;
                    secondFlag = true;
                }
            } else if (curCount > maxCount) {
                maxVal = curVal;
                maxCount = curCount;
                secondFlag = false;
            }
            curVal = arr[i];
            curCount = 1;
        } else {
            curCount++;
        }
    }
    if (maxCount == curCount) {
        if (!secondFlag) {
            maxVal = curVal;
            maxCount = curCount;
            secondFlag = true;
        }
    } else if (curCount > maxCount) {
        maxVal = curVal;
        maxCount = curCount;
        secondFlag = false;
    }
    return maxVal;
}

int getRange(int*arr, int size) {
    return (arr[size-1] - arr[0]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);

    cout << getMean(arr, N) << '\n';
    cout << getMedian(arr, N) << '\n';
    cout << getMode(arr, N) << '\n';
    cout << getRange(arr, N) << '\n';

    return 0;
}