#ifndef CREATESPHERES_H
#define CREATESPHERES_H

#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;


char*** CreateSingleSphere(const int volWidth,
                           const int volHeight,
                           const int volDepth);

char* CreateMultipleSpheres(const int volWidth,
                            const int volHeight,
                            const int volDepth);


char*** CreateSingleSphere(const int volWidth,
                           const int volHeight,
                           const int volDepth)
{
    // 3D spatial array
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

                // Sphere radius
                float sRadius = (volWidth / 2);

                if (pVector < sRadius)
                    pData_3D[i + volWidth / 2]
                            [j + volHeight / 2]
                            [k + volDepth / 2] = 150;
                else
                    pData_3D[i + volWidth / 2]
                            [j + volHeight / 2]
                            [k + volDepth / 2] = 0;
            }

    return pData_3D;
}

void FreeSingleSphere(char*** volume,
                      const int volWidth,
                      const int volHeight,
                      const int volDepth)
{
    for (int i = 0; i < volWidth; i++)
    {
        for (int j = 0; j < volHeight; j++)
        {
            free(volume[i][j]);
        }
        free(volume[i]);
    }
    free(volume);
}


void AppendSmallSphere(const int centerX, const int centerY, const int centerZ,
                       const int sWidth, const int sHeight, const int sDepth,
                       const int lWidth, const int lHeight, const int lDepth,
                       char*** smallSphere, char*** largeSphere)
{
    if (sWidth > lWidth || sHeight > lHeight || sDepth > lDepth)
    {
        INFO("The volumes dimensions are not correct ... ");
        exit(0);
    }

    for (int i = 0; i < lWidth; i++)
        for (int j = 0; j < lHeight; j++)
            for(int k = 0; k < lDepth; k++)
            {
                if (i == centerX && j == centerY && k == centerZ)
                {
                    for (int a = 0; a < sWidth; a++)
                        for (int b = 0; b < sHeight; b++)
                            for (int c = 0; c < sDepth; c++)
                            {
                                const int cI = i   + a - sWidth / 2;
                                const int cJ = j +  b - sHeight / 2;
                                const int cK = k +  c - sDepth / 2;

                                if (cI < 0 || cI > lWidth - 1 ||
                                    cJ < 0 || cJ > lHeight - 1 ||
                                    cK < 0 || cK > lDepth - 1)
                                    continue;
                                else
                                    largeSphere[cI][cJ][cK] +=
                                            smallSphere[a][b][c];
                            }
                }
            }
}

char* CreateMultipleSpheres(const int volWidth,
                            const int volHeight,
                            const int volDepth)
{
    INFO("Creating ... ");

    // Create the big volume
    char*** pData_3D;

    pData_3D = (char***) malloc(sizeof(char**) * volWidth);
    for (int i = 0; i < volWidth; i++)
    {
        pData_3D[i] = (char**) malloc(sizeof(char*) * volHeight);

        for(int j = 0; j < volHeight; j++)
            pData_3D[i][j] = (char*) malloc(sizeof(char) * volDepth);
    }

    INFO("Initializing ... ");

    // Initializing
    for (int i = 0; i < volWidth; i++)
        for (int j = 0; j < volHeight; j++)
            for(int k = 0; k < volDepth; k++)
                pData_3D[i][j][k] = 0;


    int sphereLimit = 100;
    while (sphereLimit)
    {
        // Generate spheres between 10 and 20 micron
        const int sphereRadius = rand() % 40 + 10;


        INFO("Small sphere creation ... ");

        // Create the sphere volume
        char*** sphere = CreateSingleSphere(sphereRadius,
                                            sphereRadius,
                                            sphereRadius);

        const int xPos = rand() % volWidth;
        const int yPos = rand() % volHeight;
        const int zPos = rand() % volDepth;

        printf("Sphere position : %d %d %d \n", xPos, yPos, zPos);

        INFO("Appending ... ");
        AppendSmallSphere(xPos, yPos, zPos,
                          sphereRadius, sphereRadius, sphereRadius,
                          volWidth, volHeight, volDepth,
                          sphere, pData_3D);

        INFO("Freeing ... ");
        FreeSingleSphere(sphere, sphereRadius, sphereRadius, sphereRadius);

        sphereLimit--;
    }

    const int volSize  = volWidth * volHeight * volDepth;
    char* pData_1D = (char*) malloc (sizeof(char) * volSize);

    INFO("Replacing ... ");
    int index = 0;
    for (int i = 0; i < volWidth; i++)
        for (int j = 0; j < volHeight; j++)
            for (int k = 0; k < volDepth; k++)
            {
                pData_1D[index] = pData_3D[i][j][k];
                index++;
            }

    INFO("Freeing ... ");
    FreeSingleSphere(pData_3D, volWidth, volHeight, volDepth);

    return pData_1D;
}




#endif // CREATESPHERES_H
