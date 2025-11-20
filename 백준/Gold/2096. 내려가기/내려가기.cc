#include <iostream>

using namespace std;

int getMin(int a, int b, int c = 0x7FFFFFFF) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int getMax(int a, int b, int c = -1) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

int main() {
    int N;
    int min[3], max[3], cur[3], minTemp[3], maxTemp[3];
    for (int i = 0; i < 3; i++) { min[i] = 0; max[i] = 0; }

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> cur[0] >> cur[1] >> cur[2];
        minTemp[0] = cur[0] + getMin(min[0], min[1]);
        maxTemp[0] = cur[0] + getMax(max[0], max[1]);
        minTemp[1] = cur[1] + getMin(min[0], min[1], min[2]);
        maxTemp[1] = cur[1] + getMax(max[0], max[1], max[2]);
        minTemp[2] = cur[2] + getMin(min[1], min[2]);
        maxTemp[2] = cur[2] + getMax(max[1], max[2]);
        for (int i = 0; i < 3; i++) { min[i] = minTemp[i]; max[i] = maxTemp[i]; }
    }

    cout << getMax(max[0], max[1], max[2]) << " " << getMin(min[0], min[1], min[2]);
}
