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

#ifndef __ORIONAPI_OSL_OFILE_H__
#define __ORIONAPI_OSL_OFILE_H__

#include "../application.hpp"
#include "CLoggable.hpp"

namespace Orion{
	enum OFileType : char{
		OFT_UNKNOWN=-1,
		OFT_ERROR,
		OFT_TEXT,
		OFT_IMAGE,
		OFT_VIDEO,
		OFT_FONT,
		OFT_BINARY
	};

	enum OFileAction : char{
		OFILE_READ,
		OFILE_WRITE,
		OFILE_READWRITE,
		// OFILE_APPEND
	};

	class OFile : public CLoggable {
		protected:
			OFileAction action;
			char* path;
			void* FILERAW;
			int FILEDESC;
		public:
			OFileType type;

			~OFile(void);
			OFile(void);

			bool open(const char* directory, const char* file, OFileAction); OFile(const char* directory, const char* file, OFileAction);
			bool open(const char* file, OFileAction); OFile(const char* file, OFileAction);
			bool close(void);
	};

	extern bool OFileExists(const char* file);
	extern bool OFileExists(const char* directory, const char* file);
}

#endif /* !__ORIONAPI_OSL_OFILE_H__ */