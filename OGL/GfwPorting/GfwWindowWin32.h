#ifndef __GfwWindowWin32_h_included__
#define __GfwWindowWin32_h_included__

#include <windows.h>
#include "GfwWindowPortable.h"

namespace GfwPorting {
    class GfwWindowWin32 : public GfwPorting::GfwWindowPortable
    {
    private:
        HWND m_hWnd;
        HDC m_hDC;
        HGLRC m_hGL;

        static LRESULT APIENTRY WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
        LRESULT RealProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    public:
        GfwWindowWin32();
        ~GfwWindowWin32();

        void setWidth(s32 width);
        void setHeight(s32 height);
        void setCaption(const GfwString& caption);

        void show(bool isShow);

        bool processEvent();

        void swapBuffers();

        bool initOpenGL(OpenGLVersions version, s32 color, s32 depth);

    };
}

#endif // __GfwWindowWin32_h_included__