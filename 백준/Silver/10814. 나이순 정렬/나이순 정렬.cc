#include <iostream>
#include <algorithm>
using namespace std;

class Member {
    int order, age;
    string name;
public:
    void set(int order, int age, string name) {
        this->order = order;
        this->age = age;
        this->name = name;
    }
    static bool compare(Member one, Member other) {
        if (one.age == other.age) {
            return one.order < other.order;
        }
        return one.age < other.age;
    }
    void print() {
        cout << age << ' ' << name << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    Member* members = new Member[N];
    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;
        members[i].set(i, age, name);
    }

    sort(members, members+N, Member::compare);

    for (int i = 0; i < N; i++) {
        members[i].print();
    }
}