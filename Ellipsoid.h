#ifndef ELLIPSOID_H
#define ELLIPSOID_H

char*** Ellipsoid(const float rX,
                  const float rY,
                  const float rZ,const int volWidth,
                  const int volHeight,
                  const int volDepth,

                  const int filledValue = 255,
                  const int emptyValue = 0)
{
    // 3D spatial array
    char*** pData_3D;
    pData_3D = (char***) malloc(sizeof(char**) * volWidth);
    for (int i = 0; i < volWidth; i++)
    {
        pData_3D[i] = (char**) malloc(sizeof(char*) * volHeight);

        for(int j = 0; j < volHeight; j++)
            pData_3D[i][j] = (char*) malloc(sizeof(char) * volDepth);
    }

    for (int i = -volWidth/2; i < volWidth/2; i++)
        for (int j = -volHeight/2; j < volHeight/2; j++)
            for (int k = -volDepth/2; k < volDepth/2; k++)
            {
                float unitRadius = ((i * i) / (rX * rX)) +
                        ((j * j) / (rY * rY)) +
                        ((k * k) / (rZ * rZ));

                if (unitRadius < 1)
                    pData_3D[i + volWidth / 2]
                            [j + volHeight / 2]
                            [k + volDepth / 2] = filledValue;
                else
                    pData_3D[i + volWidth / 2]
                            [j + volHeight / 2]
                            [k + volDepth / 2] = emptyValue;
            }

    return pData_3D;
}

/*
char*** EllipsoidShell(const float innerRX,
                       const float innerRY,
                       const float innerRZ,
                       const float outerRX,
                       const float outerRY,
                       const float outerRZ,
                       const int volWidth,
                       const int volHeight,
                       const int volDepth,
                       const int filledValue = 255,
                       const int emptyValue = 0)
{
    // 3D spatial array
    char*** pData_3D;
    pData_3D = (char***) malloc(sizeof(char**) * volWidth);
    for (int i = 0; i < volWidth; i++)
    {
        pData_3D[i] = (char**) malloc(sizeof(char*) * volHeight);

        for(int j = 0; j < volHeight; j++)
            pData_3D[i][j] = (char*) malloc(sizeof(char) * volDepth);
    }

    for (int i = -volWidth/2; i < volWidth/2; i++)
        for (int j = -volHeight/2; j < volHeight/2; j++)
            for (int k = -volDepth/2; k < volDepth/2; k++)
            {
                float unitRadius = ((i * i) / (rX * rX)) +
                        ((j * j) / (rY * rY)) +
                        ((k * k) / (rZ * rZ));

                if (unitRadius < 1)
                    pData_3D[i + volWidth / 2]
                            [j + volHeight / 2]
                            [k + volDepth / 2] = filledValue;
                else
                    pData_3D[i + volWidth / 2]
                            [j + volHeight / 2]
                            [k + volDepth / 2] = emptyValue;
            }

    return pData_3D;
}
*/

#endif // ELLIPSOID_H
