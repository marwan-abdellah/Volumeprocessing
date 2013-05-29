#ifndef VOLUME_H
#define VOLUME_H

char* ConvertToFlatVolume(const char*** pData_3D,
                          const int volWidth,
                          const int volHeight,
                          const int volDepth);

void AddBrickToVolume(const int centerX, const int centerY, const int centerZ,
                      const int brickWidth, const int brickHeight, const int brickDepth,
                      const int volumeWidth, const int volumeHeight, const int volumeDepth,
                      char*** brickData, char*** volumeData);

void FreeVolume(char*** volume,
                const int volWidth,
                const int volHeight,
                const int volDepth);

void FreeVolume(char* volume);

#endif // VOLUME_H
