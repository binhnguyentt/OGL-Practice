#ifndef __common_h_included__
#define __common_h_included__

#define GfwDeclareSingleton(class_name) \
private: \
    static class_name* s_instance; \
    class_name(); \
    class_name(const class_name&); \
    \
public:\
    static class_name* getInstance(); \
    static bool createInstance(); \
    static void releaseInstance()

#define GfwImplementSingleton(class_name) \
    \
    class_name::class_name() {} \
    class_name::class_name(const class_name&) {} \
    \
    class_name* class_name::getInstance() { return s_instance; } \
    \
    bool class_name::createInstance() { \
        if (s_instance == nullptr) { \
            s_instance = new class_name(); \
            return true; \
        }\
        return false; \
    }\
    \
    void class_name::releaseInstance() {\
        if (s_instance != nullptr) { \
            delete s_instance; \
            s_instance = nullptr; \
        } \
    }\
    \
    class_name* class_name::s_instance = nullptr

#define SQR(x) (x*x)

#endif // __common_h_included__