#pragma once
// Preprocessor definitions

#define _DEBUG

#ifdef _DEBUG
#define IF_DEBUG(x) (x)
#else
#define IF_DEBUG(x)
#endif // _DEBUG