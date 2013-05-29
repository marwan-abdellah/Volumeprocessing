#include "VolumeWriter.h"

#include <fstream>
#include "MACROS.h"
#include "Globals.h"

using namespace std;

void VolumeWriter(const char* volData,
                  const int volWidth,
                  const int volHeight,
                  const int volDepth,
                  char* fileName)
{
    // File stream
    ofstream fileStream(fileName, ios::out | ios::binary);

    int index = 0;
    for (int i = 0; i < volWidth; i++)
        for (int j = 0; j < volHeight; j++)
            for (int k = 0; k < volDepth; k++)
            {
                fileStream << volData[index];
                index++;
            }

    INFO("The volume has been successfully written");
}
