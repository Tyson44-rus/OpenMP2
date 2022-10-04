#include <iostream>
#include <omp.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include "Circle.h"

using namespace std;

void searchMinMax(Circle* mas, int n, Circle& minCircleX, Circle& maxCircleX, Circle& minCircleY, Circle& maxCircleY) {
    for (int i = 0; i < n; i++) {
        mas[i].R = abs(mas[i].point1.x - mas[i].point2.x);
        mas[i].minX = mas[i].point1.x - mas[i].R;
        mas[i].minY = mas[i].point1.y - mas[i].R;
    }

}

int main()
{
    setlocale(0, "");
    srand(time(NULL));
    int n;

    cout << "Укажите количество окружностей: ";
    cin >> n;

    Circle* mas = new Circle[n];

    for (int i = 0; i < n; i++) {
        new(&mas[i]) Circle;
        mas[i].point1.x = rand() % 10;
        mas[i].point1.y = rand() % 10;
        mas[i].point2.x = rand() % 10;
        mas[i].point2.y = rand() % 10;
    }

    double timer = omp_get_wtime();

    Circle minCircleX;
    Circle maxCircleX;
    Circle minCircleY;
    Circle maxCircleY;

    searchMinMax(mas, n, minCircleX, maxCircleX, minCircleY, maxCircleY);

    int R = abs(minCircleX.maxX - minCircleX.minX);
    
    if (pow(minCircleX.point2.x - minCircleX.point1.x, 2) + pow(minCircleX.point2.y - minCircleX.point1.y, 2) == pow(R, 2)) {
        cout << minCircleX.point1.x << '\t' << minCircleX.point1.y << '\t' << endl;
    }

    cout << "Время выполнения: " << omp_get_wtime() - timer << " секунд\n";


    system("PAUSE");
    delete[] mas;
    return 0;
}