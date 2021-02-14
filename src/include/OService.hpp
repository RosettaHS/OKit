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

#ifndef __ORION_OAPI_SERVICE_H__
#define __ORION_OAPI_SERVICE_H__

#include "OVec.hpp"

namespace Orion{
	/* Starts the OrionAPI service. This is required to use any Orion UI elements. Optionally you can pass a name for your application, and pass a boolean to force Orion-exclusivity. */
	extern bool OAppStart(const char* AppName=0,bool ForceONative=false);
	/* Runs the OrionAPI - OKit service. Blocks function execution until the service ends. Place this at the bottom of main(). */
	extern bool OAppEventLoop(void);
	/* Frees all memory allocated by the OrionAPI service. Place this at the bottom of main(). Automatically called by OAppEventLoop(), do not call this manually if that is present! */
	extern bool OAppClose(void);

	/* Returns the current screen size. */
	extern OVec OScreenGetSize(void);
}

#endif /* !__ORION_OAPI_SERVICE_H__ */
