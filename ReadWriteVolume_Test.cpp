#include <iostream>
#include <Volume.h>
#include "VolumeReader.h"
#include "VolumeWriter.h"
#include "CreateSphereVolume.h"
#include "NoiseVolume.h"
#include "CreateSpheres.h"
#include "CreateCellWithBranching.h"
#include "CreateBigEllipsoid.h"
#include "Globals.h"

using namespace std;

int main()
{
    cout << "Read Write Volume ... !" << endl;

    int volumeWidth = 0;
    int volumeHeigh = 0;
    int volumeDepth = 0;

    // Read the volume from the file
    char* volumeFile = ReadVolume("/Software/Datasets/CTData/CTData",
                                  volumeWidth, volumeHeigh, volumeDepth);

    // Write the volume to the disk
    VolumeWriter(volumeFile, volumeWidth, volumeHeigh, volumeDepth, "SimpleVolumeData.raw");

    // Free volume
    FreeVolume(volumeFile);

    return 0;
}

