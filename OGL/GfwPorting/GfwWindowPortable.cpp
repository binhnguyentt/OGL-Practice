
#if GFW_OS == GFW_OS_WINDOW
#include "Windows/GfwWindowWin32.h"
#endif

#include "GfwWindowPortable.h"

void GfwPorting::GfwWindowPortable::setEventsHandler(GfwWindowEvents* eventHandler)
{
    m_evtWindow = eventHandler;
}

GfwPorting::GfwWindowPortable::GfwWindowPortable()
{
    m_evtWindow = nullptr;
}

GfwPorting::GfwWindowPortable::~GfwWindowPortable()
{
}

GfwPorting::GfwWindowPortable * GfwPorting::createPortableInstance()
{
#if GFW_OS == GFW_OS_WINDOW
    return new GfwPorting::GfwWindowWin32();
#endif
}
