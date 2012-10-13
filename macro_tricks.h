#ifndef MACRO_TRICKS_H
#define MACRO_TRICKS_H

//FROM BOOST:
//Helper macro BOOST_JOIN:
//The following piece of macro magic joins the two
//arguments together, even when one of the arguments is
//itself a macro (see 16.3.1 in C++ standard).  The key
//is that macro expansion of macro arguments does not
//occur in BOOST_DO_JOIN2 but does in BOOST_DO_JOIN.
#define JOIN_MACROS( X, Y ) BOOST_DO_JOIN( X, Y )
#define BOOST_DO_JOIN( X, Y ) BOOST_DO_JOIN2(X,Y)
#define BOOST_DO_JOIN2( X, Y ) X##Y

#endif
