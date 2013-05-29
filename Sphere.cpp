#include "Sphere.h"

#include <math.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

char*** Sphere(const int radius,
               const int volWidth, const int volHeight, const int volDepth,
               const int filledValue = 255, int emptyValue = 0)
{
    // 3D
    char*** pData_3D;
    pData_3D = (char***) malloc(sizeof(char**) * volWidth);
    for (int i = 0; i < volWidth; i++)
    {
        pData_3D[i] = (char**) malloc(sizeof(char*) * volHeight);

        for(int j = 0; j < volHeight; j++)
            pData_3D[i][j] = (char*) malloc(sizeof(char) * volDepth);
    }

    for (int i = -volWidth/2; i < volWidth/2; i++)
        for (int j = -volHeight/2; j < volHeight/2; j++)
            for (int k = -volDepth/2; k < volDepth/2; k++)
            {
                // Vector XYZ length
                float pVector = sqrt((i * i) + (j * j) + (k * k));

                if (pVector < radius)
                    pData_3D[i + volWidth / 2]
                            [j + volHeight / 2]
                            [k + volDepth / 2] = filledValue;
                else
                    pData_3D[i + volWidth / 2]
                            [j + volHeight / 2]
                            [k + volDepth / 2] = emptyValue;
            }

    return pData_3D;
}

char*** SphereShell(const int innerRadius, const int outerRadius,
                    const int volWidth, const int volHeight, const int volDepth,
                    const int filledValue = 255, int emptyValue = 0)
{
    // 3D
    char*** pData_3D;
    pData_3D = (char***) malloc(sizeof(char**) * volWidth);
    for (int i = 0; i < volWidth; i++)
    {
        pData_3D[i] = (char**) malloc(sizeof(char*) * volHeight);

        for(int j = 0; j < volHeight; j++)
            pData_3D[i][j] = (char*) malloc(sizeof(char) * volDepth);
    }

    for (int i = -volWidth/2; i < volWidth/2; i++)
        for (int j = -volHeight/2; j < volHeight/2; j++)
            for (int k = -volDepth/2; k < volDepth/2; k++)
            {
                // Vector XYZ length
                float pVector = sqrt((i * i) + (j * j) + (k * k));

                if (pVector < outerRadius && pVector > innerRadius)
                    pData_3D[i + volWidth / 2]
                            [j + volHeight / 2]
                            [k + volDepth / 2] = filledValue;
                else
                    pData_3D[i + volWidth / 2]
                            [j + volHeight / 2]
                            [k + volDepth / 2] = emptyValue;
            }

    return pData_3D;
}
