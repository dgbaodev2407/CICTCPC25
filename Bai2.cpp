#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> board(8);
int pos[8];
int ans = 0;

bool ok(int r, int c)
{
    for (int i = 0; i < r; ++i)
    {
        int pc = pos[i];
        if (pc == c) return false;
        if (abs(pc - c) == abs(i - r)) return false;
    }
    return true;
}

void dq(int r)
{
    if (r == 8) {
        ++ans; return;
    }
    for (int c = 0; c < 8; ++c)
    {
        if (board[r][c] == '*') continue;
        if (!ok(r, c)) continue;
        pos[r] = c;
        dq(r + 1);
        pos[r] = -1;
    }
}

int main(void)
{
    for (int i = 0; i < 8; ++i) std::cin >> board[i];
    std::fill(std::begin(pos), std::end(pos), -1);
    ans = 0;
    dq(0);
    std::cout << ans << std::endl;
    return 0;
}
