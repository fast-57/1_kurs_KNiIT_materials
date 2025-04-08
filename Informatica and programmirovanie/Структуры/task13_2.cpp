#include<iostream>
#include<fstream>
#include<vector>
#include<cmath> 
#include<windows.h>
using namespace std;

struct Point {
    double x, y, z;
};

double calculateDistance(const Point& a, const Point& b) { // расстояние между двумя точками
    return sqrt((a.x - b.x) * (a.x - b.x) + 
                (a.y - b.y) * (a.y - b.y) + 
                (a.z - b.z) * (a.z - b.z));
}

Point findOptimalPoint(const vector<Point>& points, double R) { // нахождение точки, вокруг которой шар содержит максимум точек
    int maxCounts = 0; 
    Point optimalPoint = {0, 0, 0};

    for (const auto& center : points) {
        int count = 0; // счётчик точек внутри шара
        for (const auto& p : points) {
            if (calculateDistance(center, p) <= R) {
                count++;
            }
        }
        // обновляем оптимальную точку, если нашли больше точек
        if (count > maxCounts) {
            maxCounts = count;
            optimalPoint = center;
        }
    }
    return optimalPoint;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    vector<Point> points = { // координаты точек
        {1.0, 2.0, 3.0}, 
        {2.0, 3.0, 4.0}, 
        {1.5, 2.5, 3.5}, 
        {5.0, 5.0, 5.0}
    };

    double R = 2.0;

    Point optimalPoint = findOptimalPoint(points, R); 

    cout << "Оптимальная точка: (" 
         << optimalPoint.x << ", " 
         << optimalPoint.y << ", " 
         << optimalPoint.z << ")" << endl;

    return 0;
}
