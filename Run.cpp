#include <iostream>
#include "VolumeReader.h"
#include "VolumeWriter.h"
#include "CreateSphereVolume.h"
#include "CreateSpheres.h"
#include "CreateCellWithBranching.h"
#include "CreateBigEllipsoid.h"
#include "Globals.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    // char* volumeFile = ReadVolume("/home/abdellah/Software/Datasets/CTData/CTData");

    iWidth = 256;
    iHeight = 256;
    iDepth = 256;

    // char* volumeSphere = CreateMultipleSpheres(iWidth, iHeight, iDepth);
    // char* volumeSphere = CreateCellWithBranch(iWidth, iHeight, iDepth);

    char* volumeSphere = CreateBigEllipsoid(iWidth, iHeight, iDepth,
                                            iWidth / 2, iHeight/4, iDepth/6);

    VolumeWriter(volumeSphere, iWidth, iHeight, iDepth, "P2.raw");

    return 0;
}
