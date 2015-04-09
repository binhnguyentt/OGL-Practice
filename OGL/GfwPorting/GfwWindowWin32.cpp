#include <windows.h>
#include "GfwWindowWin32.h"

#define LPSZCLASSNAME TEXT("__glfw_window__")

void GfwPorting::GfwWindowWin32::setWidth(s32 width)
{
    m_width = width;
}

void GfwPorting::GfwWindowWin32::setHeight(s32 height)
{
    m_height = height;
}

void GfwPorting::GfwWindowWin32::setCaption(const GfwString& caption)
{
    m_caption = caption;
}

void GfwPorting::GfwWindowWin32::show(bool isShow)
{
    m_isShow = isShow;
}

GfwPorting::GfwWindowWin32::GfwWindowWin32()
{
    m_isShow = false;
    m_caption = GfwString("Window");
    m_width = 640;
    m_height = 480;

    WNDCLASSEX wcex;

    wcex.cbClsExtra = 0;
    wcex.cbSize = sizeof(wcex);
    wcex.cbWndExtra = 0;
    wcex.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hInstance = GetModuleHandle(NULL);
    wcex.lpfnWndProc = WndProc;
    wcex.lpszClassName = LPSZCLASSNAME;
    wcex.lpszMenuName = NULL;
    wcex.style = CS_DBLCLKS;

    if (RegisterClassEx(&wcex) != 0) {
        m_isShow = true;

        m_hWnd = CreateWindowEx(NULL,
            LPSZCLASSNAME,
            m_caption.getUnicode(),
            WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            CW_USEDEFAULT, CW_USEDEFAULT,
            m_width, m_height, NULL, NULL, GetModuleHandle(NULL),
            (LPVOID) this);

        if (m_hWnd != NULL) {
            ShowWindow(m_hWnd, SW_SHOW);
        }
    }
}

GfwPorting::GfwWindowWin32::~GfwWindowWin32()
{

}

bool GfwPorting::GfwWindowWin32::processEvent()
{
    MSG msg;

    if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            return false;
        } else {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return true;
}

LRESULT APIENTRY GfwPorting::GfwWindowWin32::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static GfwPorting::GfwWindowWin32 *obj = nullptr;
    
    if (uMsg == WM_CREATE) {
        if (obj == nullptr) {
            CREATESTRUCT *cs = reinterpret_cast<CREATESTRUCT *>(lParam);
            obj = reinterpret_cast<GfwPorting::GfwWindowWin32 *>(cs->lpCreateParams);
        }
    }

    if (obj != nullptr) {
        return obj->RealProc(hWnd, uMsg, wParam, lParam);
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LRESULT GfwPorting::GfwWindowWin32::RealProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_CREATE:
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_CLOSE:
    {
        if (m_evtWindow != nullptr) {
            if (m_evtWindow->onClose()) {
                DestroyWindow(m_hWnd);
            }
        } else {
            DestroyWindow(m_hWnd);
        }
        
        break;
    }

    case WM_SIZE:
    {
        int x = LOWORD(lParam);
        int y = HIWORD(lParam);

        if (m_evtWindow != nullptr) {
            m_evtWindow->onResize(x, y);
        }

        break;
    }

    default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    return NULL;
}

void GfwPorting::GfwWindowWin32::swapBuffers()
{
    SwapBuffers(m_hDC);
}

bool GfwPorting::GfwWindowWin32::initOpenGL(OpenGLVersions version, s32 color, s32 depth)
{
    m_hDC = GetDC(m_hWnd);

    PIXELFORMATDESCRIPTOR pfd;
    memset(&pfd, 0, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = color;
    pfd.cDepthBits = depth;
    pfd.cStencilBits = 0;
    pfd.nVersion = 1;
    pfd.iLayerType = PFD_MAIN_PLANE;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL;

    int pixelFormat = ChoosePixelFormat(m_hDC, &pfd); 
    SetPixelFormat(m_hDC, pixelFormat, &pfd);

    m_hGL = wglCreateContext(m_hDC);
    wglMakeCurrent(m_hDC, m_hGL);

    return true;
}
