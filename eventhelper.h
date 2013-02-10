#ifndef _EVENTHELPER_H_ 
#define _EVENTHELPER_H_ 

//#include <pthread.h> 
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>

#define MAX_KEYS 256

class XEventHelper {
  private: 
    char keyBuffer[MAX_KEYS];

    Display* xdisplay; 

  public: 
    XEventHelper(Display* display); 
};

#endif
