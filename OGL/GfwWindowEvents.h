#ifndef __GfwWindowEvents_h_included__
#define __GfwWindowEvents_h_included__

#include "GfwPorting/Def.h"

class GfwWindowEvents
{
public:
    virtual void onResize(s32 width, s32 height) = 0;
    virtual bool onClose() = 0;
};

#endif // __GfwWindowEvents_h_included__