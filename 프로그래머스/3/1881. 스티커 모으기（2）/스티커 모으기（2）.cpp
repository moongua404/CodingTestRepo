/*
저걸 일열로 쭉 줄세웠을 때
모든 스티커를 순회하며
    이번 걸 집은 경우의 수와
    집지 않은 경우의 수로
    + 첫 아이템을 집었을 때 안집었을 때로 한 번 더
나누어 고려 -> DP
O(n)
*/

#include <vector>
using namespace std;

int getMax1(vector<int>& sticker) {
    int size = sticker.size();
    vector<int> selected(size);
    vector<int> notSelected(size);
    selected[0] = sticker[0];
    for (int i = 1; i < size-1; i++) {
        selected[i] = notSelected[i-1] + sticker[i];
        notSelected[i] = notSelected[i-1];
        if (notSelected[i] < selected[i-1]) {
            notSelected[i] = selected[i-1];
        }
    }
    int maxV = selected[size-2];
    if (maxV < notSelected[size-2]) maxV = notSelected[size-2];
    return maxV;
}

int getMax2(vector<int>& sticker) {
    int size = sticker.size();
    vector<int> selected(size);
    vector<int> notSelected(size);
    for (int i = 1; i < size; i++) {
        selected[i] = notSelected[i-1] + sticker[i];
        notSelected[i] = notSelected[i-1];
        if (notSelected[i] < selected[i-1]) {
            notSelected[i] = selected[i-1];
        }
    }
    int maxV = selected[size-1];
    if (maxV < notSelected[size-1]) maxV = notSelected[size-1];
    return maxV;
}

int solution(vector<int> sticker)
{
    if (sticker.size() == 1) return sticker[0];
    int v1 = getMax1(sticker);
    int v2 = getMax2(sticker);
    return (v1 > v2) ? v1 : v2;
}