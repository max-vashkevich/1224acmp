#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
 
struct Pupil
{
public:
    std::string surname, name;
    std::vector<int> marks;
    double average;
    int index;
};
 
int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<Pupil> pupils(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> pupils[i].surname >> pupils[i].name;
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            int tmp;
            std::cin >> tmp;
            sum += tmp;
            pupils[i].marks.push_back(tmp);
        }
        pupils[i].average = (double)sum / m;
        pupils[i].index = i;
    }
    std::sort(pupils.begin(), pupils.end(), [](const Pupil& left, const Pupil& right)
    {
        return left.average > right.average;
    });
    std::vector<Pupil> top(3);
    for (int i = 0; i < 3; i++)
    {
        top[i] = pupils[i];
    }
    for (int i = 3; i < n; i++)
    {
        if (pupils[i].average == top[0].average ||
            pupils[i].average == top[1].average ||
            pupils[i].average == top[2].average)
        {
            top.push_back(pupils[i]);
        }
    }
    std::sort(top.begin(), top.end(), [](const Pupil& left, const Pupil& right)
    {
        return left.index < right.index;
    });
    for (auto pupil : top)
    {
        std::cout << pupil.surname << " " << pupil.name << " (";
        for (int i = 0; i < m; i++)
        {
            std::cout << pupil.marks[i];
            if (i != m - 1)
            {
                std::cout << " ";
            }
            else
            {
                std::cout << ")\n";
            }
        }
    }
    return 0;
}
