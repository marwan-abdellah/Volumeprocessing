#ifndef CREATEPARABOLOID_H
#define CREATEPARABOLOID_H

#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;


char* CreateBigEllipsoid(const int volWidth,
                          const int volHeight,
                          const int volDepth,
                          const float rX,
                          const float rY,
                          const float rZ);

char* CreateBigEllipsoid(const int volWidth,
                          const int volHeight,
                          const int volDepth,
                          const float rX,
                          const float rY,
                          const float rZ)
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

    const int volumeSize = volWidth * volHeight * volDepth;
    char* pData_1D = (char*) malloc (sizeof(char) * volumeSize);

    for (int i = -volWidth/2; i < volWidth/2; i++)
        for (int j = -volHeight/2; j < volHeight/2; j++)
            for (int k = -volDepth/2; k < volDepth/2; k++)
            {

                float diskCheck = ((i * i) / (rX * rX)) +
                        ((j * j) / (rY * rY)) +
                        ((k * k) / (rZ * rZ));

                if (diskCheck < 1)
                    pData_3D[i + volWidth / 2]
                            [j + volHeight / 2]
                            [k + volDepth / 2] = 150;
                else
                    pData_3D[i + volWidth / 2]
                            [j + volHeight / 2]
                            [k + volDepth / 2] = 0;
            }
    int index = 0 ;
    for (int i = 0; i < volWidth; i++)
        for (int j = 0; j < volHeight; j++)
            for (int k = 0; k < volDepth; k++)
            {
                pData_1D[index] = pData_3D[i][j][k];
                index++;
            }

    // Free the 3D array
    for (int i = 0; i < volWidth; i++)
    {
        for (int j = 0; j < volHeight; j++)
        {
            free(pData_3D[i][j]);
        }
        free(pData_3D[i]);
    }
    free(pData_3D);

    return pData_1D;
}

#endif // CREATEPARABOLOID_H
