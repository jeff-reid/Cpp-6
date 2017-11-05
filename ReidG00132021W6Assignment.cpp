#include <iostream>
#include <cmath>
using namespace std;

void menu() {

    cout << "What would you like to do?\n"
         << "a) Double the number\n"
         << "b) Reverse the digits of the number\n"
         << "c) Raise the number to the power of 2, 3, or 4\n"
         << "d) Sum the digits of the number\n"
         << "e) If the number is a two digit number, then raise the first digit to the\n"
         << "\tpower of the second digit\n"
         << "f) If the number is three digits and the last digit is less than of equal to\n"
         << "\t4, then raise the first two digits to the power of the last digit\n"
         << "g) exit" << endl;

}

int randomGenerator() {
    srand(time(NULL));
    return rand() % (99 - 10 + 1) + 10;
}

int doubleNumber(int doubleThisNumber) {
    int doubled = doubleThisNumber * 2;
    cout << "Your number doubled is, " << doubled << endl;
    return doubled;
}

int reverseDigits(int reverseThis) {
    int remainder,reversedNum = 0;
    while (reverseThis != 0) {
        remainder = reverseThis % 10;
        reversedNum = reversedNum * 10 + remainder;
        reverseThis /= 10;
    }
    cout << "The digits in your number reversed is, " << reversedNum << endl;
    return reversedNum;
}

long raisePower_234(int yourNumber, int powerOf) {
    long result;
    switch (powerOf){
        case 2:
            result = pow(yourNumber,2);
            break;
        case 3:
            result = pow(yourNumber,3);
            break;
        case 4:
            result = pow(yourNumber,4);
            break;
        default:
            break;
    }
    cout << "Your number raised to the power of " << powerOf << " is, " << result << endl;
    return result;
}

int sumTheDigits(long sumTheseDigits) {
    int sum = 0;
    int num = sumTheseDigits;
    while (num != 0) {
        sum += (num % 10);
        num /= 10;
    }
    cout << "Sum of the digits in " << sumTheseDigits << " is, " << sum << "." << endl;
    return sum;
}

long raise1stDigitTo2nd(int twoDigitNum) {
    int first, second, result = 0;
    second = twoDigitNum % 10;
    first = twoDigitNum / 10;
    result = pow(first,second);
    cout << "First digit raised to the power of the second is, " << result << endl;
    return result;
}

long raiseDigitsToPowerOfLast(int threeDigitNum) {
    int first, second, result = 0;
    first = threeDigitNum / 10;
    second = threeDigitNum % 10;
    result = pow(first,second);
    cout << "First 2 digits of your number, raised to the power of the last digit is, " << result << endl;
    return result;
}

void isPrime(int isThisPrime) {
    bool isPrime = true;
    for (int i = 2; i <= isThisPrime / 2; i++) {
        if (isThisPrime % i == 0) {
            isPrime = false;
            break;
        }
    }
    if (isPrime) {
        cout << isThisPrime << " is a prime number.\n" << endl;
    }
    else {
        cout << isThisPrime << " is NOT a prime number.\n" << endl;
    }
}

int main() {

    char menuChoice;
    int yourNumber;
    long newNumber = 0;

    cout << "Here is your number: " << randomGenerator() << '\n';
    yourNumber = randomGenerator();

    do {

        menu();
        cin >> menuChoice;

        switch (menuChoice) {
            case 'a':
                newNumber = doubleNumber(yourNumber);
                isPrime(newNumber);
                break;
            case 'b':
                newNumber = reverseDigits(yourNumber);
                isPrime(newNumber);
                break;
            case 'c':
                int powerOf;
                cout << "Raise " << yourNumber << " to the power of 2, 3, or 4?" << endl;
                cin >> powerOf;
                newNumber = raisePower_234(yourNumber, powerOf);
                isPrime(newNumber);
                break;
            case 'd':
                newNumber = sumTheDigits(yourNumber);
                isPrime(newNumber);
                break;
            case 'e':
                newNumber = raise1stDigitTo2nd(yourNumber);
                isPrime(newNumber);
                break;
            case 'f':
                newNumber = raiseDigitsToPowerOfLast(yourNumber);
                isPrime(newNumber);
                break;
            default:
                break;
        }

        yourNumber = newNumber;

    } while (menuChoice != 'g');

    cout << "GoodBye" << endl;

}