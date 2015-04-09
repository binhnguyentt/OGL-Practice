#pragma comment (lib, "opengl32.lib")

#include <windows.h>
#include <gl/GL.h>
#include <iostream>
#include "GfwWindow.h"

class EventHandler : public GfwWindowEvents
{
    void onResize(s32 width, s32 height)
    {
        std::cout << "onResize event (" << width << ", " << height << ")" << std::endl;
    }

    bool onClose()
    {
        std::cout << "onClose" << std::endl;
        return true;
    }

} g_evtWnd;

bool init()
{
    glClearColor(1.0f, 0.0f, 0.0f, 0.5f);

    return true;
}

int main(int arg, char *argv[]) {
    GfwWindow window;

    window.initializeOpenGL(OpenGLVersions::V2_1, 32, 16);
    window.setEventHandler(&g_evtWnd);

    init();

    while (window.processEvents()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        window.swapBuffers();
    }
    
    return 0;
}