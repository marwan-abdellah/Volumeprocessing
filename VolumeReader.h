#ifndef VOLUMEREADER_H
#define VOLUMEREADER_H

#include "MACROS.h"
#include "Globals.h"

#include <fstream>

using namespace std;

void ReadHeader(char *prefix,
                int &volumeWidth,
                int &volumeHeight,
                int &volumeDepth);

char* ReadVolume(char *prefix);

void ReadHeader(char *prefix,
                int &volumeWidth, int &volumeHeight, int &volumeDepth)
{
    char hdrFile[300];
    std::ifstream inputFileStream;

    // Adding the ".hdr" prefix to the dataset path
    sprintf(hdrFile, "%s.hdr", prefix);

    INFO("Dataset HDR hdrFile");

    // Open the eader hdrFile to read the dataset dimensions
    inputFileStream.open(hdrFile, std::ios::in);

    // Checking the openning of the file
    if (inputFileStream.fail())
    {
        INFO("Could not open the HDR file");
        INFO("Exiting");
        exit(0);
    }

    // Reading the dimensions
    inputFileStream >> volumeWidth;
    inputFileStream >> volumeHeight;
    inputFileStream >> volumeDepth;

    // Closing the ".hdr" file
    inputFileStream.close();

    INFO("HDR file has been read SUCCESSFULLY");
}

char* ReadVolume(char *prefix)
{
    char imgFile[100];
    ifstream inputFileStream;

    // Reading the header file
    ReadHeader(prefix, iWidth, iHeight, iDepth);

    // Adding the ".img" prefix to the dataset path
    sprintf(imgFile, "%s.img", prefix);

    // Total number of voxels
    int numVoxels = iWidth * iHeight * iDepth;

    // Allocating the luminance image
    unsigned char* luminanceImage = new unsigned char [numVoxels];

    // Allocating the RGBA image
    unsigned char* rgbaImage = new unsigned char [numVoxels * 4];

    // Reading the volume image (luminance values)
    inputFileStream.open(imgFile, ios::in);
    if (inputFileStream.fail())
    {
        exit(0);
    }

    // Read the image byte by byte
    inputFileStream.read((unsigned char *)luminanceImage, numVoxels);

    // for (int i = 0; i < iWidth * iDepth * iHeight; i++)
        // std::cout << (int)(luminanceImage[i]) << " ";

    // Closing the input volume stream
    inputFileStream.close();

    INFO("The volume has been read successfull and the RGBA one is DONE");

    return luminanceImage;
}

#endif // VOLUMEREADER_H
