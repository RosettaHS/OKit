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
#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include "include/OKit.hpp"
using namespace Orion;

void myFunc(void* listener, X::CXEvent* event){
	printf("Printing from event listener! Values | Listener %p | Event %p\n",listener,event);
}

// void myFunc2(void* listener, void* event){
	// printf("Printing from event listener 2 2 2! Values | Listener %p | Event %p\n",listener,event);
// }

int main(){
	OKitStart("My OApp");
	
	OCol col(255,86,15);
	OCol col2(30,27,27);

	CContext context;
	context.init(0,100,100,400,350,"My OApp",&col,ExposureMask|EnterWindowMask|LeaveWindowMask,true);
	context.listenerFunc=myFunc;
	// CContext context2(&context,8,8,400-16,350-16,0,&col2,ButtonPressMask,true);
	// context2.listenerFunc=myFunc2;

	OKitEventLoop();
}