/*
 @Date    : 2017-12-21 19:53:18
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p304
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class Account
{
public:
    static double rate() { return interestRate; }
    static void rate(double);
    void calculate() { amount += amount * interestRate; }
private:
    static constexpr int period = 30;
    static double interestRate;
    static double initRate();
    double amount;
    double daily_tbl[period];
    string owner;
};

double Account::initRate(void) { interestRate = 0.1; return interestRate; }
double Account::interestRate;
void Account::rate(double newRate) { interestRate = newRate; }
constexpr int Account::period;

#endif
