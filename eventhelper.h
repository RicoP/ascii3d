#ifndef _EVENTHELPER_H_ 
#define _EVENTHELPER_H_ 

#include <pthread.h> 
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>

#define MAX_KEYS 256

class XEventHelper {
  private: 
    char keyBuffer[MAX_KEYS];
    Display* xdisplay; 
    pthread_t thread; 

    static void* innerLoop(void* that); 

  public: 
    XEventHelper(Display* display); 

    void startListener(); 
    bool isKeyDown(int key); 
    bool isKeyUp(int key); 
};

#endif
