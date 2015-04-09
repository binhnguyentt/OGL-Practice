#include "GfwString.h"

GfwString::GfwString()
{

}

GfwString::GfwString(const char *str)
{

}

GfwString::GfwString(const GfwString& str)
{

}

GfwString::~GfwString()
{

}

unicode_t* GfwString::getUnicode()
{
    return L"Hello";
}
