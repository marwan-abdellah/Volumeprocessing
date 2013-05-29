#ifndef ELLIPSOID_H
#define ELLIPSOID_H

char*** Ellipsoid(const float rX, const float rY, const float rZ,
                  const int volWidth, const int volHeight, const int volDepth,
                  const int filledValue,
                  const int emptyValue);

#endif // ELLIPSOID_H
