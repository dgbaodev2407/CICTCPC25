#include <iostream>
#include <vector>
#include <cstring>

int main(void)
{
    int N, M;
    std::cin >> N >> M;
    std::vector<int> h(M, 0);
    long long max = 0;
    std::string s;
    for (int i = 0; i < N; i++)
    {
        std::cin >> s;
        for (int j = 0; j < M; ++j)
        {
            if (s[j] == '.') h[j] += 1;
            else h[j] = 0;
        }
        std::vector<int> st;
        for (int j = 0; j <= M; j++)
        {
            int cur = (j == M ? 0 : h[j]);
            while (!st.empty() && h[st.back()] >= cur)
            {
                int _h = h[st.back()];
                st.pop_back();
                int _l = st.empty() ? -1 : st.back();
                int _w = j - _l - 1;
                long long area = 1LL * _h * _w;
                if (area > max) max = area;
            }
            st.push_back(j);
        }
    }
    std::cout << max << std::endl;
    return 0;
}