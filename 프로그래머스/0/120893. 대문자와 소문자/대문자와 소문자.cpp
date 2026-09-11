#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    for (char& ch : my_string) ch += (ch < 'a') ? 32 : -32;
    return my_string;
}