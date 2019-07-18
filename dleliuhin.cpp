#include <iostream>
#include <string>
#include <algorithm>

#include <assert.h>

using namespace std;

// Можете использовать.
static const char *alphabet = "0123456789ABCDEF";

std::string to_system( int num, int base )
{
    assert( base >= 2 && base <= 16 );

    bool is_negative = (num < 0) ? true : false;

    num = abs(num);

    string res;

    while (num > 0)
    {
        int remain = num % base;

        num /= base;

        res += alphabet[remain];
    }

    if (is_negative)
    {
        res += '-';
    }

    reverse(res.begin(), res.end());

    return res;
}


int main()
{
    cout << "1 in 2th system == " << to_system(1, 2) << endl;

    assert( to_system(10, 10) == "10" );
    assert( to_system(-10, 10) == "-10" );

    assert( to_system(10, 2) == "1010" );

    assert( to_system(10, 3) == "101" );
    assert( to_system(11, 3) == "102" );
    assert( to_system(-12, 3) == "-110" );

    assert( to_system(42, 16) == "2A" );

    // to_system(12, 17)  -- ошибка по assert.

    return 0;
}

