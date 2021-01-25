/**********************************************************************************/
/*                                                                                */
/*                              Copyright (c) 2021                                */
/*                           Rosetta H&S International                            */
/*                                                                                */
/*  Permission is hereby granted, free of charge, to any person obtaining a copy  */
/*  of this software and associated documentation files (the "Software"), to deal */
/*  in the Software without restriction, including without limitation the right   */
/*    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell   */
/*       copies of the Software, and to permit persons to whom the Software is    */
/*          furnished to do so, subject to the following conditions:              */
/*                                                                                */
/* The above copyright notice and this permission notice shall be included in all */
/*                copies or substantial portions of the Software.                 */
/*                                                                                */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     */
/* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       */
/* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    */
/* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         */
/* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  */
/* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  */
/* SOFTWARE.                                                                      */
/*                                                                                */
/**********************************************************************************/

#include <stdlib.h>
#include "include/errdef.h"
#include "include/xservice.hpp"
#include "include/OLog.hpp"
#include "include/OWindow.hpp"
#include "include/OService.hpp"

#define _OWINDOW_DEFMASK 0

namespace Orion{

	OWindow::~OWindow(void){
		type=OT_ERROR;
		minW=400,minH=350;
		title=0;
		ready=false;
	}

	OWindow::OWindow(void){
		type=OT_OWINDOW;
		minW=400,minH=350;
		title=0;
		ready=false;
	}

	OWindow::OWindow(int _x, int _y, unsigned int _w, unsigned int _h, const char* _t){
		OXONLY{
			type=OT_OWINDOW;
			OVec _screenSize=OScreenGetSize();
		/* Variable Initialisation */
			title=_t;
			w=_w,h=_h;
			if(_w<minW){minW=_w;}
			if(_h<minH){minH=_h;}
			
			switch(_x){
				default:{ x=_x; break; }
				case CENTER:{ x=((_screenSize.x/2)-(_w/2)); break; }
			}

			switch(_y){
				default:{ y=_y; break; }
				case CENTER:{ y=((_screenSize.y/2)-(_h/2)); break; }
			}
		/* Context Initialisation */
			if(selfContext.init(0,x,y,w,h,title,theme.accent,_OWINDOW_DEFMASK,CCT_TOPLEVEL,true)){
				selfContext.listener=(void*)this;
				// selfContext.listenerFunc=HANDLE::OWindow;
				// drawPtr=DRAW::OWindow;

				context=&selfContext;
				contextToUse=&selfContext;
				drawableToUse=(CDrawable*)this;
				containerToUse=(CContainer*)this;
				arr.init(5,1);
			}else{type=OT_ERROR;}
			
			
		}else{
			OLog("OKIT | ERROR! FAILED TO CREATE OWINDOW(%d %d %u %u %s) BECAUSE X IS NOT INITIALISED!\n",_x,_y,_w,_h,_t);
			type=OT_ERROR;
			exit(OERR_X11_NOT_INITED);
		}
	}

	// namespace DRAW{
		// void OWindow(CDrawable* obj){
			// Orion::OWindow* win=(Orion::OWindow*)obj;
		// }
	// }

	// namespace HANDLE{
		// void OWindow(void* obj,X::CXEvent* event){
			// Orion::OWindow* win=(Orion::OWindow*)obj;
		// }
	// }
}