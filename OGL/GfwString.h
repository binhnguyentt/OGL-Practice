#ifndef __GfwString_h_included___
#define __GfwString_h_included___

#include "GfwObject.h"
#include "Def.h"

class GfwString: public GfwObject
{
protected:
    char *m_data;

public:
    GfwString();
    GfwString(const char *str);
    GfwString(const GfwString& str);
    ~GfwString();

    unicode_t* getUnicode();

};

#endif // __GfwString_h_included___