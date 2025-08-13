#pragma once
// Class declaration for String

// STL includes
#include <iostream>

class String
{
public:

    static String sEmptyString;

    // Constructors/Destructor
    String();
    String(const char* inBuffer);
    String(const String& inString);
    String(String&& inString) noexcept;
    ~String();

    // Overloads
    String& operator=(const String& inString);
    String& operator=(String&& inString) noexcept;
    
    friend String operator+(const String& inLhs, const String& inRhs);   // Return a new string that's the concatenation result of the passed in Strings
    String& operator+=(const String& inString); // Concatenate this string with the passed in String

    friend std::ostream& operator<<(std::ostream& os, const String& inString);
    friend std::istream& operator>>(std::istream& is, String& inString);

private:
    char* mBuffer { nullptr };
    uint64_t mSize { 0 };
};
