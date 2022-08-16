#include <iostream>
#include <string>
using namespace std;

void isPalindromeRecursive(string a,int i) {
    int b = (a.length()-1 - i);
    //cout << a[i] << " " << a[b] << endl;
    if (i <= (a.length() / 2)) {
        if (a[i] == a[b])
            isPalindromeRecursive(a, i + 1);
        else
            cout << "the string '" << a << "' Is not a Palindrome" << endl;
    }
    else
        cout << "the string '" << a << "' Is a Palindrome" << endl;
}
;

void isPalindrome(string a) {
    isPalindromeRecursive(a, 0);
}

int main()
{
    string userEntry;
    cout << "Enter word:" << endl;
    getline(cin,userEntry);

    //isPalindrome(userEntry,0);
    isPalindrome(userEntry);
}
