/* Trying to make a generic class for serial device input/output, to be used with UARTs, i2c etc..
 *
 * Will be loosely based on unix's <termios.h>
 */

#ifndef SERIALIO_HPP
#define SERIALIO_HPP

#include <termios.h>

class SerialIO {
public:
    virtual void transmit_off();
    virtual void transmit_on();
    virtual void receive_off();
    virtual void receive_on();

    virtual void flush_input();
    virtual void flush_output();
    void flush() {
        flush_input();
        flush_output();
    }


private:
    int control_flags;
};

#endif // #ifndef SERIALIO_HPP
