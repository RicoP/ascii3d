#include <pthread.h> 
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <stdio.h>       
#include <stdlib.h>       
#include "eventhelper.h"

XEventHelper::XEventHelper(Display* display) {
  this->xdisplay = display;   
}

void* XEventHelper::innerLoop(void* that) {
    XEventHelper* instance = (XEventHelper*)that; 
    int code;
    XEvent event;
    Display* display = instance->xdisplay; 
    char* keyBuffer = instance->keyBuffer; 

    for(int i = 0; i != MAX_KEYS; i++) {
      keyBuffer[i] = 0;   
    }

    for(;;) {
      XNextEvent(display, &event);
      printf("EventType = %i\n", event.type);

      switch (event.type) {
      case ConfigureNotify:
         //reshape(event.xconfigure.width, event.xconfigure.height);
         break;
      case KeyPress:
         {
            code = XLookupKeysym(&event.xkey, 0);
            printf("EventCode = %i\n", code);
            if (code < MAX_KEYS) {
              keyBuffer[code] = 1;              
            }
         }
         break;

      case KeyRelease:
         {
            code = XLookupKeysym(&event.xkey, 0);
            printf("EventCodeUp = %i\n", code);
            if (code < MAX_KEYS) {
              keyBuffer[code] = 0;
            }
         }
         break;

      case DestroyNotify: 
        {
          //We are done
          return NULL; 
        }
      }
   }

   return NULL; 
}

bool XEventHelper::isKeyDown(int key) {
    if(key >= 0 && key < MAX_KEYS) {
      return this->keyBuffer[key];   
    }

    return 0; 
}

bool XEventHelper::isKeyUp(int key) {
  return !isKeyDown(key); 
} 


void XEventHelper::startListener() {
    pthread_create( &this->thread, NULL, &XEventHelper::innerLoop, (void*) this);  
}
