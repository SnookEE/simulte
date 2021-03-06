//
//                           SimuLTE
//
// This file is part of a software released under the license included in file
// "license.pdf". This license can be also found at http://www.ltesimulator.com/
// The above file and the present reference are part of the software itself,
// and cannot be removed from it.
//

#ifndef _LTE_X2COMPMSG_H_
#define _LTE_X2COMPMSG_H_

#include "LteX2Message.h"
#include "LteCommon.h"

/**
 * @class X2CompMsg
 *
 * Class derived from LteX2Message
 * It defines the message exchanged between CoMP managers
 */
class X2CompMsg : public LteX2Message
{

  public:

    X2CompMsg(const char* name = NULL, int kind = 0) :
        LteX2Message(name, kind)
    {
        type_ = X2_COMP_MSG;
    }

    X2CompMsg(const X2CompMsg& other) : LteX2Message() { operator=(other); }

    X2CompMsg& operator=(const X2CompMsg& other)
    {
        if (&other == this)
            return *this;
        LteX2Message::operator=(other);
        return *this;
    }

    virtual X2CompMsg* dup() const { return new X2CompMsg(*this); }

    virtual ~X2CompMsg() { }
};

Register_Class(X2CompMsg);

#endif

