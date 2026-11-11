#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Рекурсивна перевірка наявності пар "no" або "on"
bool Include(const char* str, int i)
{
    if (strlen(str) < 2 || str[i + 1] == '\0')
        return false;

    if ((str[i] == 'n' && str[i + 1] == 'o') ||
        (str[i] == 'o' && str[i + 1] == 'n'))
    {
        return true;
    }

    return Include(str, i + 1);
}

// Рекурсивна заміна "no" на "***"
char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i] != '\0' && str[i + 1] != '\0')
    {
        if (str[i] == 'n' && str[i + 1] == 'o')
        {
            strcat(t, "***");
            return Change(dest, str, t + 3, i + 2);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else
    {
        while (str[i] != '\0')
        {
            *t++ = str[i++];
        }
        *t = '\0';
        return dest;
    }
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (Include(str, 0))
        cout << "String contains 'no' or 'on'" << endl;
    else
        cout << "String DOES NOT contain 'no' or 'on'" << endl;

    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2 = Change(dest1, str, dest1, 0);

    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;

    return 0;
}