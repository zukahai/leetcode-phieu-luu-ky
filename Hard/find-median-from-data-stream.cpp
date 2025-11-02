#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
private:
    vector<int> s;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto it = upper_bound(s.begin(), s.end(), num);
        s.insert(it, num);
    }
    
    double findMedian() {
        if (s.size() % 2 != 0)
            return s[s.size() / 2];
        return (s[s.size() / 2] + s[s.size() / 2 - 1]) / 2.0;
    }
};

int main() {
    MedianFinder *m = new MedianFinder();
    m->addNum(5);
    m->addNum(7);
    m->addNum(6);
    m->addNum(10);
    m->addNum(10);
    cout << m->findMedian() << endl;
}