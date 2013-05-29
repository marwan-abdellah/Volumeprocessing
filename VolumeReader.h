#ifndef VOLUMEREADER_H
#define VOLUMEREADER_H

void ReadHeader(char *prefix,
                int &volumeWidth,
                int &volumeHeight,
                int &volumeDepth);

char* ReadVolume(char *prefix, int &volumeWidth, int &volumeHeight, int &volumeDepth);



#endif // VOLUMEREADER_H
