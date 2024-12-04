#include <iostream>
using namespace std;

bool submit[30];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, rank;
    float grade, totalGrade = 0.0, totalRank = 0.0;

    for (int i = 0; i < 20; i++) {
        cin >> s >> grade >> rank;
        totalGrade += grade;
        if (rank == "A+") {
            totalRank += 4.5 * grade;
        } else if (rank == "A0") {
            totalRank += 4.0 * grade;
        } else if (rank == "B+") {
            totalRank += 3.5 * grade;
        } else if (rank == "B0") {
            totalRank += 3.0 * grade;
        } else if (rank == "C+") {
            totalRank += 2.5 * grade;
        } else if (rank == "C0") {
            totalRank += 2.0 * grade;
        } else if (rank == "D+") {
            totalRank += 1.5 * grade;
        } else if (rank == "D0") {
            totalRank += 1.0 * grade;
        } else if (rank == "F") {
            totalRank += 0.0;
        } else if (rank == "P") {
            totalGrade -= grade;
        }
    }

    printf("%.6f", (totalRank / totalGrade));
}