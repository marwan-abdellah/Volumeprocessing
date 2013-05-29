#ifndef VOLUMEWRITER_H
#define VOLUMEWRITER_H

#include "MACROS.h"
#include "Globals.h"

#include <fstream>

using namespace std;

void VolumeWriter(const char* volData,
                  const int volWidth,
                  const int volHeight,
                  const int volDepth,
                  char* fileName);

void VolumeWriter(const char* volData,
                  const int volWidth,
                  const int volHeight,
                  const int volDepth,
                  char* fileName)
{
    ofstream fileStream(fileName, ios::out | ios::binary);

    int index = 0;
    for (int i = 0; i < volWidth; i++)
        for (int j = 0; j < volHeight; j++)
            for (int k = 0; k < volDepth; k++)
            {
                fileStream << volData[index];
                index++;
            }

    INFO("The volume has been successfully writte");
}

#endif // VOLUMEWRITER_H
