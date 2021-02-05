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
#include "include/OLog.hpp"
#include "include/errdef.h"
#include "include/application.hpp"
#include "include/xservice.hpp"
#include "include/OTheme.hpp"
#include "include/CContext.hpp"
#include "include/OService.hpp"

namespace Orion{

	/* This function is merely for testing and is not final, ignore the sloppy work. */
	static bool _setThemeFromSystem(){
		char themepath[OPATH_MAX];
		sprintf(themepath,"%s/.orion/theme",getenv("HOME"));

		if( access(themepath,F_OK)==0 ){
			unsigned char place=0;
			unsigned char section=0;
			unsigned char line=0;
			unsigned char rgb[3];
			OCol* theme[4] = {&OTHEME_PRIMARY,&OTHEME_SECONDARY,&OTHEME_TERTIARY,&OTHEME_ACCENT};
			char current[4] = {0,0,0,0};
			FILE* file=fopen(themepath,"r");

			if(file){
				char c;
				while( (c=fgetc(file))!=EOF ){
					switch(c){
						default:{
							current[place]=c;
							place++;
							continue;
						}
						case ' ':{
							rgb[section]=atoi(current);
							place=0;
							section++;
							continue;
						}
						case '\n':{
							rgb[section]=atoi(current);
							theme[line]->setTo(rgb[0],rgb[1],rgb[2]);
							section=0,place=0,line++;continue;
						}
					}
				}
				rgb[section]=atoi(current);
				theme[line]->setTo(rgb[0],rgb[1],rgb[2]);

				OVLog("OKIT | Successfully set OApp's theme from system theme!\n");
				return true;
			}else{ OVLog("OKIT | OApp theme could not  be set from the system because system theme file exists but could not be opened. Resorting to fallback."); return false; }

		}else{ OLog("OKIT | OApp theme could not be set from the system because system theme file does not exist. Resorting to fallback.\n"); }
		return false; /* Add proper support here! */
	}

	static void _setThemeToFallback(){
		OTHEME_PRIMARY.setTo(30,25,25);
		OTHEME_SECONDARY.setTo(40,35,35);
		OTHEME_TERTIARY.setTo(25,15,15);
		OTHEME_ACCENT.setTo(255,86,15);
	}

	bool OKitStart(const char* name,bool ForceONative){
		if(OAPP_INITED){return false;}
		if(name){Application::setName(name);}
		Application::init();
		if(ForceONative){
			if(!OAPP_NATIVE){OLog("OKIT | ERROR! SERVICE FORCED AS ORION-NATIVE, BUT APPLICATION EXECUTED AS STANDALONE BINARY!\n");exit(OERR_NOT_NATIVE_OAPP);}
			if(OAPP_BINPATH==0||OAPP_BINDIR==0||OAPP_DATAPATH==0){OLog("OKIT | ERROR! SERVICE FORCED AS ORION-NAITVE, BUT ONE OR MORE OF THE REQUIRED PATHS HAS FAILED TO INITIALISE!\n");exit(OERR_NOT_NATIVE_OAPP);}
		}
		X::connect();
		X::CXHA_INIT();
		if(!_setThemeFromSystem()){_setThemeToFallback();}
		OVLog("OKIT | Service sucessfully initialised!\n\n");
		OAPP_INITED=true;
		return true;
	}

	bool OKitEventLoop(void){
		if(!OAPP_INITED){return false;}
		X::eventLoop(); /* TODO: Actually add something to this!! */
		X::disconnect();
		OVLog("\nOKIT | Service sucessfully finished!\n\n");
		return true;
	}

	OVec OScreenGetSize(void){
		OVec v;
		XWindowAttributes attr;
		XGetWindowAttributes(OXDPY,OXROOT,&attr);
		v.x=attr.width,v.y=attr.height;
		return v;
	}
}