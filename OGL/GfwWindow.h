#ifndef __GfwWindow_h_included__
#define __GfwWindow_h_included__

#include <iostream>
#include "Def.h"
#include "GfwObject.h"
#include "GfwString.h"
#include "GfwWindowEvents.h"
#include "GfwPorting/GfwWindowPortable.h"

class GfwWindow: public GfwObject
{
protected:
    GfwPorting::GfwWindowPortable * m_Window;
    GfwWindowEvents *m_evtWindow;

public:
    GfwWindow();
    virtual ~GfwWindow();

    void setWidth(s32 width);
    void setHeight(s32 height);
    void setCaption(const GfwString& caption);
    bool processEvents();

    void setEventHandler(GfwWindowEvents *handler);

    bool initializeOpenGL(OpenGLVersions version, s32 color_bit, s32 depth_bit);
    void swapBuffers();
};

#endif // __GfwWindow_h_included__