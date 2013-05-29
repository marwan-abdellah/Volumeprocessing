#include "CreateVolume.h"
#include "Volume.h"

#include "MACROS.h"
#include "Globals.h"

#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Sphere.h"
#include "Ellipsoid.h"
#include "Volume.h"

char* CreateSpheresVolume(const int volumeWidth,
                          const int volumeHeight,
                          const int volumeDepth)
{
    INFO("Creating ... ");

    // Create the big volume
    char*** pData_3D;

    pData_3D = (char***) malloc(sizeof(char**) * volumeWidth);
    for (int i = 0; i < volumeWidth; i++)
    {
        pData_3D[i] = (char**) malloc(sizeof(char*) * volumeHeight);

        for(int j = 0; j < volumeHeight; j++)
            pData_3D[i][j] = (char*) malloc(sizeof(char) * volumeDepth);
    }

    INFO("Initializing ... ");

    // Initializing
    for (int i = 0; i < volumeWidth; i++)
        for (int j = 0; j < volumeHeight; j++)
            for(int k = 0; k < volumeDepth; k++)
                pData_3D[i][j][k] = 0;


    int sphereLimit = 100;
    while (sphereLimit)
    {
        // Generate spheres between 10 and 20 micron
        const int sphereRadius = rand() % 40 + 10;


        INFO("Small sphere creation ... ");

        // Create the sphere volume
        char*** sphere = Sphere(sphereRadius / 2, sphereRadius, sphereRadius, sphereRadius, 255, 0);

        const int xPos = rand() % volumeWidth;
        const int yPos = rand() % volumeHeight;
        const int zPos = rand() % volumeDepth;

        printf("Sphere position : %d %d %d \n", xPos, yPos, zPos);

        INFO("Appending ... ");
        AddBrickToVolume(xPos, yPos, zPos,
                         sphereRadius, sphereRadius, sphereRadius,
                         volumeWidth, volumeHeight, volumeDepth,
                         sphere, pData_3D);


        INFO("Freeing ... ");
        FreeVolume(sphere, sphereRadius, sphereRadius, sphereRadius);

        sphereLimit--;
    }

    const int volSize  = volumeWidth * volumeHeight * volumeDepth;
    char* pData_1D = (char*) malloc (sizeof(char) * volSize);

    INFO("Replacing ... ");
    int index = 0;
    for (int i = 0; i < volumeWidth; i++)
        for (int j = 0; j < volumeHeight; j++)
            for (int k = 0; k < volumeDepth; k++)
            {
                pData_1D[index] = pData_3D[i][j][k];
                index++;
            }

    INFO("Freeing ... ");
    FreeVolume(pData_3D, volumeWidth, volumeHeight, volumeDepth);

    return pData_1D;
}

char* CreateEllipsoidesVolume(const int volumeWidth,
                              const int volumeHeight,
                              const int volumeDepth)
{
    INFO("Creating ... ");

    // Create the big volume
    char*** pData_3D;

    pData_3D = (char***) malloc(sizeof(char**) * volumeWidth);
    for (int i = 0; i < volumeWidth; i++)
    {
        pData_3D[i] = (char**) malloc(sizeof(char*) * volumeHeight);

        for(int j = 0; j < volumeHeight; j++)
            pData_3D[i][j] = (char*) malloc(sizeof(char) * volumeDepth);
    }

    INFO("Initializing ... ");

    // Initializing
    for (int i = 0; i < volumeWidth; i++)
        for (int j = 0; j < volumeHeight; j++)
            for(int k = 0; k < volumeDepth; k++)
                pData_3D[i][j][k] = 0;


    int ellipsoidLimit = 100;
    while (ellipsoidLimit)
    {
        // Generate spheres between 10 and 20 micron
        const int rX = rand() % 40 + 10;
        const int rY = rand() % 40 + 10;
        const int rZ = rand() % 40 + 10;

        INFO("Small sphere creation ... ");

        // Create the sphere volume
        char*** elliposid = Ellipsoid(rX, rY, rZ, rX * 2, rY * 2, rZ * 2, 255, 0);

        const int xPos = rand() % volumeWidth;
        const int yPos = rand() % volumeHeight;
        const int zPos = rand() % volumeDepth;

        printf("Ellipsoid position : %d %d %d \n", xPos, yPos, zPos);

        INFO("Appending ... ");
        AddBrickToVolume(xPos, yPos, zPos,
                         rX * 2, rY * 2, rZ * 2,
                         volumeWidth, volumeHeight, volumeDepth,
                         elliposid, pData_3D);


        INFO("Freeing ... ");
        FreeVolume(elliposid, rX * 2, rY * 2, rZ * 2);

        ellipsoidLimit--;
    }

    const int volSize  = volumeWidth * volumeHeight * volumeDepth;
    char* pData_1D = (char*) malloc (sizeof(char) * volSize);

    INFO("Replacing ... ");
    int index = 0;
    for (int i = 0; i < volumeWidth; i++)
        for (int j = 0; j < volumeHeight; j++)
            for (int k = 0; k < volumeDepth; k++)
            {
                pData_1D[index] = pData_3D[i][j][k];
                index++;
            }

    INFO("Freeing ... ");
    FreeVolume(pData_3D, volumeWidth, volumeHeight, volumeDepth);

    return pData_1D;
}
