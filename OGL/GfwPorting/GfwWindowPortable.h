#ifndef __GfwPorting_GfwWindow_h_included__
#define __GfwPorting_GfwWindow_h_included__

#include "../Def.h"
#include "../GfwString.h"
#include "../GfwVersions.h"
#include "../GfwWindowEvents.h"

namespace GfwPorting
{
    /**
     * Abstract class for porting
     */
    class GfwWindowPortable {
    protected:
        s32                 m_width;
        s32                 m_height;
        GfwString           m_caption;
        bool                m_isShow;
        GfwWindowEvents *   m_evtWindow;

    public:
        GfwWindowPortable();
        virtual ~GfwWindowPortable();

        virtual void setWidth(s32 width) = 0;
        virtual void setHeight(s32 height) = 0;

        virtual void setCaption(const GfwString& caption) = 0;
        virtual void show(bool isShow) = 0;

        virtual bool processEvent() = 0;
        void setEventsHandler(GfwWindowEvents* eventHandler);

        virtual bool initOpenGL(OpenGLVersions version, s32 color, s32 depth) = 0;

        virtual void swapBuffers() = 0;
    };

    GfwWindowPortable * createPortableInstance();
}

#endif // __GfwPorting_GfwWindow_h_included__