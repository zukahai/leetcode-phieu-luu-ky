#include <bits/stdc++.h>

using namespace std;

class MyCalendarThree {
private:
    map<int, int> mp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime - 1]--;
        int sum = 0;
        int res = 0;
        for (auto x: mp) {
            sum += x.second;
            res = max(res, sum);
        }
        return res;
    }
};

int main() {
    MyCalendarThree *m = new MyCalendarThree;
    cout << m->book(47,50);
    cout << m->book(1,10);
    cout << m->book(27,36);
    cout << m->book(40,47);
    cout << m->book(20,27);
    cout << m->book(15,23);
    cout << m->book(10,18);
    cout << m->book(27,36);
    cout << m->book(17,25);
    cout << m->book(8,17);
    cout << m->book(24,33);
    cout << m->book(23,28);
    cout << m->book(21,27);
    cout << m->book(47,50);
    cout << m->book(14,21);
    cout << m->book(26,32);
    cout << m->book(16,21);
    cout << m->book(2,7);
    cout << m->book(24,33);
    cout << m->book(6,13);
    cout << m->book(44,50);
    cout << m->book(33,39);
    cout << m->book(30,36);
    cout << m->book(6,15);
    cout << m->book(21,27);
    cout << m->book(49,50);
    cout << m->book(38,45);
    cout << m->book(4,12);
    cout << m->book(46,50);
    cout << m->book(13,21);
}