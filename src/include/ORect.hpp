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

#ifndef __ORION_OKIT_ORECT_H__
#define __ORION_OKIT_ORECT_H__

#include "CDrawable.hpp"
#include "CContainer.hpp"

namespace Orion{
	namespace DRAW{ void ORect(CDrawable*); }
	/* A solid, coloured Rectangle. Merely visual. */
	class ORect : public CDrawable{ friend void DRAW::ORect(CDrawable*);
		protected:
			/* The real rectangle on the screen. */
			CContext rect;

			/* Internal. Calls this method when linked. */
			virtual void onLink(void) override;
			/* Internal. Calls this method when unlinked. */
			virtual void onUnlink(void) override;
		public:
			/* Destructor. Sets all values to 0. */
			~ORect(void);
			/* Empty constructor. Sets all values to 0. */
			ORect(void);
			/* Creates a Rectangle with the given parameters on the parent container. Pass an OCol on the last value to override the theme. */
			ORect(CContainer& parent,int x, int y, unsigned int w, unsigned int h, OCol& col=OTHEME_SECONDARY);

			/* Sets the position of this Rectangle. */
			virtual void setPos(int x, int y) override;
			/* Sets the size of this Rectangle. */
			virtual void setSize(unsigned int w,unsigned int h, bool force=false) override;
			/* Sets the colour of this Rectangle. */
			virtual void setCol(unsigned char r, unsigned char g, unsigned char b) override;
	};
}

#endif /* !__ORION_OKIT_ORECT_H__ */