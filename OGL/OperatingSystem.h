#ifndef __OperatingSystem_h_included__
#define __OperatingSystem_h_included__

#define GFW_OS_WINDOW 1
#define GFW_OS_MAC 2
#define GFW_OS_LINUX 3

#if defined(WIN32) || defined(_WIN32)

#define GFW_OS GFW_OS_WINDOW

#endif

#endif // __OperatingSystem_h_included__