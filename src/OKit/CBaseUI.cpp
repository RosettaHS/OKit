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

#define ORION_INTERNAL

#include "../include/OKit/CBaseUI.hpp"

namespace Orion{
	CBaseUI::CBaseUI() : type{OT_ERROR},ready{0} {}

	const char* CBaseUI::getTypeAsString(void){
		switch(type){
			case OT_ERROR:{return "OT_ERROR";}
			case OT_CDRAWABLE:{return "OT_CDRAWABLE";}
			case OT_OCONTAINER:{return "OT_OCONTAINER";}
			case OT_ORECT:{return "OT_ORECT";}
			case OT_OLABEL:{return "OT_OLABEL";}
			case OT_OMARGINCONTAINER:{return "OT_OMARGINCONTAINER";}

			case OT_OWINDOW:{return "OT_OWINDOW";}
		}

		return 0;
	}
}