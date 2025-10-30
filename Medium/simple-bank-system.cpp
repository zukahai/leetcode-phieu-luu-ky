#include <bits/stdc++.h>

using namespace std;

class Bank {
private:
    vector<long long> balance;
public:
    Bank(vector<long long>& balance) {
        this->balance = balance;
    }

    bool valid(int num) {
        return num >= 1 && num <= balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (!valid(account1) || !valid(account2))
            return false;
        if (balance[account1 - 1] < money)
            return false;
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (!valid(account))
            return false;
        balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (!valid(account))
            return false;
        if (balance[account - 1] < money)
            return false;
        balance[account - 1] -= money;
        return true;
    }
};

int main() {
    vector <long long> balance = {10, 100, 20, 50, 30};
    Bank* obj = new Bank(balance);;
    bool param_1 = obj->deposit(1, 1000);
    bool param_2 = obj->withdraw(1,1011);
    cout << param_2;
    
    // bool param_3 = obj->withdraw(account,money);
}