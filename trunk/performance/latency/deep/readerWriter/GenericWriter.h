#ifndef GENERICWRITER_H_
#define GENERICWRITER_H_

namespace Deep {

class GenericWriter {
public:
    virtual void initData(unsigned int payload) = 0;
    virtual void writeData() = 0;
    virtual void incrementData() = 0;
};

typedef GenericWriter *GenericWriter_ptr;
}

#endif /*GENERICWRITER_H_*/
