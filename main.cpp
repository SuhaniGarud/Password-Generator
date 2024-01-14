// Simple Random Password Generator
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int selectArray()
{
    srand(time(NULL));
    int i = rand() % 4 +1 ;
    return i;
}

int getKey()
{
    srand(time(NULL));
    int key = rand() % 26;
    return key;
}

void generatePassword(int length)
{
    // initialized resultant string as Null
    string password = "";

    string alphabets = "abcdefghijklmnopqrstuvwxyz";
    string capitals = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string symbols = "!@#$%&";
    string number = "0123456789";

    int key, cnt_alphabets = 0, cnt_capitals = 0, cnt_nums = 0, cnt_symb = 0;

    int count = 0;
    while (count < length)
    {
        int k = selectArray();
        // the beginning of password should be alphabets or capitals
        if (count == 0)
        {
            k = k % 3;
            if (k == 0)
                k++;
        }

        switch (k)
        {
        case 1:
            if ((cnt_alphabets == 2) && (cnt_nums == 0 || cnt_symb == 0 || cnt_capitals == 0 || cnt_capitals == 1))
                break;

            key = getKey();
            password += alphabets[key];
            cnt_alphabets++;
            count++;
            break;

        case 2:
            if ((cnt_capitals == 2) && (cnt_nums == 0 || cnt_symb == 0 || cnt_alphabets == 0 || cnt_alphabets == 1))
                break;

            key = getKey();
            password += capitals[key];
            cnt_capitals++;
            count++;
            break;

        case 3:
            if ((cnt_nums == 1) && ((cnt_alphabets == 0) || (cnt_alphabets == 0) || (cnt_alphabets == 1) || (cnt_capitals == 0) || (cnt_capitals == 1) || (cnt_symb == 0)))
                break;

            key = getKey();
            key %= 10;
            password += number[key];
            cnt_nums++;
            count++;
            break;

        case 4:
            if ((cnt_symb == 1) && ((cnt_alphabets == 0) || (cnt_alphabets == 0) || (cnt_alphabets == 1) || (cnt_capitals == 0) || (cnt_capitals == 1) || (cnt_nums == 0)))
                break;

            key = getKey();
            key %= 6;
            password += symbols[key];
            cnt_symb++;
            count++;
            break;
        }
    }
    cout << "\n-----------------------------\n";
    cout << "         Password             \n";
    cout << "------------------------------\n\n";
    cout << " " << password;
    cout << "\n\nPress any key to continue \n";
    getchar();
}
int main()
{
    int opt, length;
    do
    {
        cout << "\n------------------------\n";
        cout << "   Pasword Generator " << endl;
        cout << "------------------------\n";
        cout << endl;
        cout << "    1. Generate Password"<< "\n";
        cout << "    2. Exit"<< "\n\n";
        cout << "Press key 1 to Generate Password and key 2 to exit: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "Enter Length of Password: ";
            cin >> length;
            if (length < 7)
            {
                cout << "Minimum Length of Password should be 8." << endl;
                cout << "Press any key to try again" << endl;
                getchar();
            }
            else if (length > 100)
            {
                cout << "Maximum length of password should be 100" << endl;
                cout << "Press any key to try again" << endl;
                getchar();
            }
            else
            {
                generatePassword(length);
            }
            break;

        default:
            if (opt != 2)
            {
                cout << "\nInvalid choice\n";
                cout << "Please Press ( 1 ) to generate password and ( 2 ) to exit.\n";
                cout << "Press any key to try again \n";
                getchar();
            }
            break;
        }
    } while (opt != 2);

    return 0;
}
