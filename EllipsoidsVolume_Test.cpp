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
#include "Sphere.h"
#include "Ellipsoid.h"
#include "CreateVolume.h"

using namespace std;

int main()
{
    cout << "Ellipsoid  ... !" << endl;

    int volumeWidth = 256;
    int volumeHeigh = 256;
    int volumeDepth = 256;

    // Create the solid sphere
    char* volumeFile_1D = CreateEllipsoidesVolume(volumeWidth, volumeHeigh, volumeDepth);

    // Write the volume to the disk
    VolumeWriter(volumeFile_1D, volumeWidth, volumeHeigh, volumeDepth, "EllipsoidsVolume.raw");

    // Free volume
    FreeVolume(volumeFile_1D);

    return 0;
}


