#include <iostream>
#include "VolumeReader.h"
#include "VolumeWriter.h"
#include "CreateSphereVolume.h"
#include "CreateNoiseVolume.h"
#include "CreateSpheres.h"
#include "Globals.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    // char* volumeFile = ReadVolume("/home/abdellah/Software/Datasets/CTData/CTData");

    iWidth = 256;
    iHeight = 256;
    iDepth = 256;

    //char* volumeSphere = CreateSphere(iWidth, iHeight, iDepth);

    // char* volumeSphere = CreateMultipleSpheres(iWidth, iHeight, iDepth);

    char* volumeCube = CreateNoiseVolume(iWidth, iHeight, iDepth);
    VolumeWriter(volumeCube, iWidth, iHeight, iDepth, "Noise2.raw");

    return 0;
}
