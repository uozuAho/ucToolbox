#ifndef STREAM_PARSER_H
#define STREAM_PARSER_H

#include <stdint.h>
#include "stream.hpp"

class StreamParser {
public:
    // Possible states of the parser
    enum eParserState {
        eSEARCHING,     // searching for messages in the stream
        ePARSING,       // parsing a message in the byte stream
        ePARSER_OFF     // not parsing
    };

    // Possible return values for message parsing functions
    enum eMsgParserResult {
        eWAITING,       // waiting for more bytes
        eSUCCESS,       // successfully parsed a message
        eERROR          // message invalid
    };

    // Function pointer type
    typedef bool (*headerByteChecker)(uint8_t byte);
    typedef eMsgParserResult (*eMsgParserPtr)(uint8_t* begin, uint8_t* end, uint16_t bytes_read);

private:
    eParserState state;
    Stream* stream;
};

struct ParserData_st {
    enum eParserState state;
    Stream* stream;
    Fifo* msg_buf;

    bHeaderByteCheckerPtr isHeaderByte;
    eMsgParserPtr parseCurrentMsg;

    bool bStreamIsSet;
    ui uiLastHeaderRxTime;
    us usMsgTimeout_ms;
};

void BS_PARSER_vInitialiseParser(struct ParserData_st* parser, Stream* stream, Fifo* msg_buffer,
                                 bHeaderByteCheckerPtr headerByteCheckFunction,
                                 eMsgParserPtr msgParser, us msg_timeout_ms);
void BS_PARSER_vSetStream(struct ParserData_st* parser, Stream* stream);
void BS_PARSER_vParseStream(struct ParserData_st* parser);

#endif // #ifndef STREAM_PARSER_H
