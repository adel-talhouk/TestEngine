// Class implementation for String

// Engine includes
#include <String/String.h>


String String::sEmptyString = String("");

// Empty constructor
String::String()
{
    mSize = 0;
    mBuffer = new char[1];
    mBuffer[0] = '\0';
}



// Constructor
String::String(const char* inBuffer)
{
    if (inBuffer)
    {
        mSize = std::strlen(inBuffer);
        mBuffer = new char[mSize+1];
        std::strcpy(mBuffer, inBuffer);
        mBuffer[mSize] = '\0';
    }
    else
    {
        mSize = 0;
        mBuffer = new char[1];
        mBuffer[0] = '\0';
    }
}



// Copy constructor
String::String(const String& inString)
{
    mSize = inString.mSize;
    mBuffer = new char[mSize+1];
    std::strcpy(mBuffer, inString.mBuffer);
}



// Move constructor
String::String(String&& inString) noexcept
{
    mSize = std::move(inString.mSize);
    mBuffer = std::move(inString.mBuffer);

    inString.mBuffer = nullptr;
    inString.mSize = 0;
}



// Destructor
String::~String()
{
    delete mBuffer;
    mBuffer = nullptr;

    mSize = 0;
}



String& String::operator=(const String& inString)
{
    if (this != &inString)
    {
        delete[] mBuffer; // Free existing buffer

        mSize = inString.mSize;
        mBuffer = new char[mSize + 1];
        std::strcpy(mBuffer, inString.mBuffer);
    }
    return *this;
}



String& String::operator=(String&& inString) noexcept
{
    if (this != &inString)
    {
        delete[] mBuffer; // Free existing buffer

        mSize = std::move(inString.mSize);
        mBuffer = std::move(inString.mBuffer);

        inString.mBuffer = nullptr;
        inString.mSize = 0;
    }
    return *this;
}



String operator+(const String& inLhs, const String& inRhs)
{
    int size = inLhs.mSize + inRhs.mSize;
    char* buffer = new char[size + 1];

    // Fill the buffers
    std::strcpy(buffer, inLhs.mBuffer);
    std::strcat(buffer, inRhs.mBuffer);
    buffer[size] = '\0';

    // Create a new String with the new buffer, cleanup the buffer
    String result = String(buffer);
    delete[] buffer;
    return result;
}



String& String::operator+=(const String& inString)
{
    int size = mSize + inString.mSize;
    char* buffer = new char[size + 1];

    // Fill the buffers
    std::strcpy(buffer, mBuffer);
    std::strcat(buffer, inString.mBuffer);
    buffer[size] = '\0';

    // Replace the buffer with the newly concatenated one, update mSize
    mBuffer = buffer;
    mSize = size;
    delete[] buffer;
    return *this;
}



std::ostream& operator<<(std::ostream& os, const String& inString)
{
    os << inString.mBuffer;
    return os;
}



std::istream& operator>>(std::istream& is, String& inString)
{
    // Create a new buffer to store the input in
    char* buffer = new char[1000];
    std::memset(&buffer, 0, sizeof(buffer));    // Set the data to 0
    is >> *buffer;

    // Create a new string with the buffer we just filled, cleanup the buffer
    inString = String(buffer);
    delete[] buffer;

    return is;
}