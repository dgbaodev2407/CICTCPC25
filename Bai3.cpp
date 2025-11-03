#include <iostream>
#include <vector>
#include <algorithm>

bool ask(int y)
{
    std::cout << "? " << y << std::endl;
    std::string r;
    std::cin >> r;
    if (r == "YES") return true;
    else if (r == "NO") return false;
    else exit(1);
}

int main(void)
{
    unsigned long long max = 1e9;
    unsigned long long min = 1;

    while (min < max)
    {
        unsigned long long mid = (min + max) / 2;
        bool ans = ask(mid);
        if (ans) min = mid + 1;
        else max = mid;
    }
    std::cout << "! " << min << std::endl;
    return 0;
}