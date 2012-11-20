#ifndef BYTE_FIFO_HPP
#define BYTE_FIFO_HPP

//TODO: make this a template. Once you know how...

#include <cstdint>

class ByteFifo {
public:
    std::uint16_t capacity();
    std::uint16_t space();
    std::uint16_t size();
    bool isFull();
    bool isEmpty();

private:
    std::uint8_t* buffer;

};

bool FIFO_bIsFull(Fifo* fifo);
bool FIFO_bIsEmpty(Fifo* fifo);
us FIFO_usSpace(Fifo* fifo);
us FIFO_usBytesInFifo(Fifo* fifo);
ss FIFO_ssPeek(Fifo* fifo);
ss FIFO_ssGetByte(Fifo* fifo);
ss FIFO_ssPutByte(Fifo* fifo, uc byte);
us FIFO_ssWrite(Fifo* fifo, uc* input_buf, us len);
void FIFO_vClear(Fifo* fifo);
void FIFO_vShiftLeft(Fifo* fifo, us num_bytes);

ARRAY_TYPE(uc) FIFO_stAsArray(Fifo* fifo);
// Debugging functions
void FIFO_vPrintToStdout(Fifo* buf);
void FIFO_vPrintToStdout_detailed(Fifo* buf);
void FIFO_vPrintStatus(Fifo* fifo);
void FIFO_vFifoUnitTest();

#endif
