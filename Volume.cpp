#include "Volume.h"
#include "MACROS.h"
#include "Globals.h"

#include <stdlib.h>

char* ConvertToFlatVolume(const char*** pData_3D,
                          const int volWidth,
                          const int volHeight,
                          const int volDepth)
{
    const int volumeSize = volWidth * volHeight * volDepth;
    char* pData_1D = (char*) malloc (volumeSize * sizeof(char));

    int index = 0;
    for (int i = 0; i < volWidth; i++)
        for (int j = 0; j < volHeight; j++)
            for (int k = 0; k < volDepth; k++)
            {
                pData_1D[index] = pData_3D[i][j][k];
                index++;
            }

    return pData_1D;
}

void AddBrickToVolume(const int centerX, const int centerY, const int centerZ,
                      const int brickWidth, const int brickHeight, const int brickDepth,
                      const int volumeWidth, const int volumeHeight, const int volumeDepth,
                      char*** brickData, char*** volumeData)
{
    if (brickWidth > volumeWidth || brickHeight > volumeHeight || brickDepth > volumeDepth)
    {
        INFO("The volumes dimensions are not correct ... ");
        exit(0);
    }

    for (int i = 0; i < volumeWidth; i++)
        for (int j = 0; j < volumeHeight; j++)
            for(int k = 0; k < volumeDepth; k++)
            {
                if (i == centerX && j == centerY && k == centerZ)
                {
                    for (int a = 0; a < brickWidth; a++)
                        for (int b = 0; b < brickHeight; b++)
                            for (int c = 0; c < brickDepth; c++)
                            {
                                const int cI = i   + a - brickWidth / 2;
                                const int cJ = j +  b - brickHeight / 2;
                                const int cK = k +  c - brickDepth / 2;

                                if (cI < 0 || cI > volumeWidth - 1 ||
                                        cJ < 0 || cJ > volumeHeight - 1 ||
                                        cK < 0 || cK > volumeDepth - 1)
                                    continue;
                                else
                                    volumeData[cI][cJ][cK] +=
                                            brickData[a][b][c];
                            }
                }
            }
}

void FreeVolume(char*** volume,
                const int volWidth,
                const int volHeight,
                const int volDepth)
{
    for (int i = 0; i < volWidth; i++)
    {
        for (int j = 0; j < volHeight; j++)
        {
            free(volume[i][j]);
        }
        free(volume[i]);
    }
    free(volume);
}

void FreeVolume(char* volume)
{
    free(volume);
}

