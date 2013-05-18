#ifndef CREATENOISEVOLUME_H
#define CREATENOISEVOLUME_H

#include "MACROS.h"
#include "Globals.h"

#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "simplexnoise.h"
#include "simplextextures.h"

using namespace std;

float fAbs (float val)
{
    if (val > 0)
        return val;
    else
        return val * -1;
}

char* CreateNoiseVolume(const int volWidth,
                        const int volHeight,
                        const int volDepth);

char* CreateNoiseVolume(const int volWidth,
                        const int volHeight,
                        const int volDepth)
{
    const int volumeSize = volWidth * volHeight * volDepth;
    char* pData_1D = (char*) malloc (sizeof(char) * volumeSize);

    float octaves = 5;
    float persistence = 1;
    float scale = 0.1;

    int index = 0;
    for (int i = 0; i < volWidth; i++)
        for (int j = 0; j < volHeight; j++)
            for (int k = 0; k < volDepth; k++)
            {
                pData_1D[index] = 256 * fAbs(octave_noise_3d(octaves,
                                                  persistence,
                                                  scale,
                                                  i,
                                                  j,
                                                  k));

                index++;
            }

    return pData_1D;
}

#endif // CREATENOISEVOLUME_H
