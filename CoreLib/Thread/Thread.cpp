// Class implementation for Thread

// STL includes


// Engine includes
#include <Thread/Thread.h>

 
Thread::Thread()
{

}
#ifdef _DEBUG



Thread::Thread(String inId)
        : mDebugId(inId)
{
    
}
#endif // _DEBUG



Thread::~Thread()
{

}