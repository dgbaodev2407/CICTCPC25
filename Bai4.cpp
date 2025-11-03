#include <iostream>
#include <vector>
#include <algorithm>

struct Point
{
    int x, y;
    void MoveUp(int step)
    {
        y += step;
    }
    void MoveDown(int step)
    {
        y -= step;
    }
    void MoveLeft(int step)
    {
        x -= step;
    }
    void MoveRight(int step)
    {
        x += step;
    }
};

bool contains(const std::vector<Point>& XY, const Point& p)
{
    return std::find_if(XY.begin(), XY.end(), [&](const Point& point)
    {
        return point.x == p.x && point.y == p.y;
    }) != XY.end();
}

int main(void)
{
    Point RobotXY = {0, 0};
    std::vector<Point> visited;
    visited.push_back(RobotXY);

    int n;
    std::cin >> n;
    long long step = 0;

    for (int i = 0; i < n; i++)
    {
        char d;
        long long count;
        std::cin >> d >> count;
        switch (d)
        {
        case 'U':
            for (long long j = 0; j < count; j++)
            {
                RobotXY.MoveUp(1);
                step ++;
                if (contains(visited, RobotXY)) goto result;
                visited.push_back(RobotXY);
            }
            break;
        case 'D':
            for (long long j = 0; j < count; j++)
            {
                RobotXY.MoveDown(1);
                step ++;
                if (contains(visited, RobotXY)) goto result;
                visited.push_back(RobotXY);
            }
            break;
        case 'L':
            for (long long j = 0; j < count; j++)
            {
                RobotXY.MoveLeft(1);
                step ++;
                if (contains(visited, RobotXY)) goto result;
                visited.push_back(RobotXY);
            }
            break;
        case 'R':
            for (long long j = 0; j < count; j++)
            {
                RobotXY.MoveRight(1);
                step ++;
                if (contains(visited, RobotXY)) goto result;
                visited.push_back(RobotXY);
            }
            break;
        default:
            exit(1);
        }
    }
    result:
    std::cout << step << std::endl;
    return 0;
}