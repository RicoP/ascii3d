#include <pthread.h> 
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include "eventhelper.h"

XEventHelper::XEventHelper(Display* display) {
  this->xdisplay = display;   
}
