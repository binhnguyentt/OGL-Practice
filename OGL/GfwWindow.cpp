#include "OperatingSystem.h"
#include "GfwWindow.h"

GfwWindow::GfwWindow()
{
#if GFW_OS == GFW_OS_WINDOW
    m_Window = GfwPorting::createPortableInstance();
#endif 

    m_evtWindow = NULL; 
}

GfwWindow::~GfwWindow()
{
    if (m_Window != nullptr) {
        delete m_Window;
    }
}

void GfwWindow::setWidth(s32 width)
{
    m_Window->setWidth(width);
}

void GfwWindow::setHeight(s32 height)
{
    m_Window->setHeight(height);
}

void GfwWindow::setCaption(const GfwString& caption)
{
    m_Window->setCaption(caption);
}

bool GfwWindow::processEvents()
{
    return m_Window->processEvent();
}

void GfwWindow::swapBuffers()
{
    m_Window->swapBuffers();
}

bool GfwWindow::initializeOpenGL(OpenGLVersions version, s32 color_bit, s32 depth_bit)
{
    return m_Window->initOpenGL(version, color_bit, depth_bit);
}

void GfwWindow::setEventHandler(GfwWindowEvents *handler)
{
    m_evtWindow = handler;
    m_Window->setEventsHandler(m_evtWindow);
}
