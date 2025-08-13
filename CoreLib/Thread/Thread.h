#pragma once
// Class declaration for Thread

// Common includes
#include <Defines.h>

// Engine includes
#include <String/String.h>

class Thread
{
public:
    Thread();
#ifdef _DEBUG
    Thread(String inId);
#endif // _DEBUG
    ~Thread();

private:
#ifdef _DEBUG
    String mDebugId { String::sEmptyString };
#endif // _DEBUG
};