/* I haven't used stdio FILE streams or c++'s iostreams much, but it looks as though iostreams
 * is out of the question when it comes to tiny embedded systems, and even stdio can be a bit big.
 *
 * For the moment I'll try to use stdio but I might come back here and try to re-make it with
 * a class interface.
 */

namespace ucToolbox {

class Stream {
public:
    Stream();
private:

};

} // end namespace ucToolbox
