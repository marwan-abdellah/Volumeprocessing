#include <iostream>
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
    cout << "Hello World!" << endl;

    // char* volumeFile = ReadVolume("/home/abdellah/Software/Datasets/CTData/CTData");

    int iWidth = 256;
    int iHeight = 256;
    int iDepth = 256;

    // char* volumeSphere = CreateMultipleSpheres(iWidth, iHeight, iDepth);
    // char* volumeSphere = CreateCellWithBranch(iWidth, iHeight, iDepth);


    // char* volumeSphere = CreateMultipleSpheres(iWidth, iHeight, iDepth);

    char* volumeCube = CreateNoiseVolume(iWidth, iHeight, iDepth);
    VolumeWriter(volumeCube, iWidth, iHeight, iDepth, "Noise2.raw");


    return 0;
}
