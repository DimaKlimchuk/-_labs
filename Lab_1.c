#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    float z1, z2, a;
    if (scanf_s("%f", &a) != 1) {
        printf("Input error\n");
        return 1;  // Повертається код помилки, оскільки введення не було прочитано правильно
    }

    z1 = (sin(4 * a) / (1 + cos(4 * a))) * (cos(2 * a) / (1 + cos(2 * a)));
    z2 = 1 / tan(3.0 / 2.0 * PI - a);
    printf("Result is z1 = %.2f, z2 = %.2f", z1, z2);
    
    return 0;
} 