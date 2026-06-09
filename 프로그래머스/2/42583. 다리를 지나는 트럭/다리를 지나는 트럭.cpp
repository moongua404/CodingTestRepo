/*
시뮬레이션
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> weightQ;
    for (int w : truck_weights) weightQ.push(w);
    
    queue<pair<int, int>> waitingQ;
    int useWeight = weightQ.front();
    int useQuantity = 1;
    waitingQ.push({bridge_length, weightQ.front()});
    weightQ.pop();
    
    int time = 1;
    while(!waitingQ.empty()) {
        if (waitingQ.front().first <= time) { // 어차피 하나씩 들어옴
            useQuantity--;
            useWeight -= waitingQ.front().second;
            waitingQ.pop();
        }
        if (!weightQ.empty()
                && weight >= useWeight+weightQ.front()
                && bridge_length >= useQuantity+1) {
            useWeight += weightQ.front();
            useQuantity++;
            waitingQ.push({time + bridge_length, weightQ.front()});
            weightQ.pop();
        }
        time++;
    }
    
    return time;
}