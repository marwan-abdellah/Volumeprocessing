#ifndef SPHERE_H
#define SPHERE_H

char*** Sphere(const int radius,
               const int volWidth, const int volHeight, const int volDepth,
               const int filledValue, int emptyValue);

char*** SphereShell(const int innerRadius, const int outerRadius,
                    const int volWidth, const int volHeight, const int volDepth,
                    const int filledValue, int emptyValue);

#endif // SPHERE_H
