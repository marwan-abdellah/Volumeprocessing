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

using namespace std;

int main()
{
    cout << "Shell Sphere ... !" << endl;

    int volumeWidth = 256;
    int volumeHeigh = 256;
    int volumeDepth = 256;

    int sphereRadius_i = 128;
    int sphereRadius_o = 130;

    // Create the solid sphere
    char*** volumeFile_3D = SphereShell(sphereRadius_i,sphereRadius_o, volumeWidth, volumeHeigh, volumeDepth, 255, 0);

    // Convert it to a flat array
    char* volumeFile_1D = ConvertToFlatVolume(volumeFile_3D, volumeWidth, volumeHeigh, volumeDepth);

    // Write the volume to the disk
    VolumeWriter(volumeFile_1D, volumeWidth, volumeHeigh, volumeDepth, "ShellSphere_255.raw");

    // Free volumes
    FreeVolume(volumeFile_3D, volumeWidth, volumeHeigh, volumeDepth);
    FreeVolume(volumeFile_1D);

    return 0;
}

