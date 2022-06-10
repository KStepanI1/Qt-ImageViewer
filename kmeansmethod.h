#ifndef KMEANSMETHOD_H
#define KMEANSMETHOD_H

#include "quantizationmethod.h"

class KMeansMethod : public QuantizationMethod
{
public:
    KMeansMethod();

    // QuantizationMethod interface
protected:
    void process() override;
};

#endif // KMEANSMETHOD_H
