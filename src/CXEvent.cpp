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

#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include "include/CXEvent.hpp"

namespace Orion{
	namespace X{
		void CXEvent::compose(void* _e){
			XEvent* e=(XEvent*)_e;
			xtype=e->type;
			switch(e->type){
				case Expose:{type=CXE_EXPOSE;return;}
				case KeyPress:{type=CXE_KEYCHAR;XLookupString(&e->xkey,&key.letter,1,0,0);key.pressed=true;key.code=e->xkey.keycode;key.mod=e->xkey.state;return;}
				case KeyRelease:{type=CXE_KEYCHAR;key.pressed=false;key.code=e->xkey.keycode;key.mod=e->xkey.state;return;}
			}
		}


		void CXEvent::log(void){
			printf("CXEvent %p | type %d | xtype %d | {\n",this,type,xtype);
			switch(type){
				case CXE_EXPOSE:{printf("\tExpose\n}\n");return;}
				case CXE_MFOCUS_CHANGED:{return;} /* TODO: Add logging data */
				case CXE_XWIN_MODDED:{return;} /* TODO: Add logging data */
				case CXE_KEYCHAR:{printf("\tkey.letter \"%c\"\n\tkey.pressed %d\n\tkey.code %u\n\tkey.mod %u\n}\n",key.letter,key.pressed,key.code,key.mod);return;}
			}
		}
	}
}