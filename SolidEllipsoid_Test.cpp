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
using namespace std;

int main()
{
    cout << "Solid Ellipsoid ... !" << endl;

    int volumeWidth = 256;
    int volumeHeigh = 256;
    int volumeDepth = 256;

    int rX = 150 / 2;
    int rY = 200 / 2;
    int rZ = 100 / 2;

    // Create the solid ellipsoid
    char*** volumeFile_3D = Ellipsoid(rX, rY, rZ, volumeWidth, volumeHeigh, volumeDepth, 255, 0);

    // Convert it to a flat array
    char* volumeFile_1D = ConvertToFlatVolume(volumeFile_3D, volumeWidth, volumeHeigh, volumeDepth);

    // Write the volume to the disk
    VolumeWriter(volumeFile_1D, volumeWidth, volumeHeigh, volumeDepth, "SolidEllipsoid_255.raw");

    // Free volumes
    FreeVolume(volumeFile_3D, volumeWidth, volumeHeigh, volumeDepth);
    FreeVolume(volumeFile_1D);

    return 0;
}
