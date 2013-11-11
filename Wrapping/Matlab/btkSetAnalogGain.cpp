/* 
 * The Biomechanical ToolKit
 * Copyright (c) 2009-2013, Arnaud Barré
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 *     * Redistributions of source code must retain the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *     * Neither the name(s) of the copyright holders nor the names
 *       of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written
 *       permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "btkMEXObjectHandle.h"
#include "btkMXAnalog.h"

#include <btkAcquisition.h>
#include <btkAnalog.h>
#include <btkConvert.h>

// btkSetAnalogLabel(h, i, newLabel)
// btkSetAnalogLabel(h, label, newLabel)
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  if(nrhs < 3)
    mexErrMsgTxt("Three inputs required.");
  if (nlhs > 2)
    mexErrMsgTxt("Too many output arguments.");

  if ((mxGetClassID(prhs[2]) != mxDOUBLE_CLASS) || mxIsEmpty(prhs[2]) || mxIsComplex(prhs[2]) || (mxGetNumberOfElements(prhs[2]) != 1))
    mexErrMsgTxt("Analog's gain must be a double value representing an integer.");

  btk::Acquisition::Pointer acq = btk_MOH_get_object<btk::Acquisition>(prhs[0]);
  btk::Analog::Pointer analog = btkMXGetAnalog(acq, nrhs, prhs);
  
  int g = static_cast<int>(mxGetScalar(prhs[2]));
  btk::Analog::Gain gain = btk::Analog::Unknown;
  switch (g)
  {
  case 0: // already assigned
    break;
  case 1:
    gain = btk::Analog::PlusMinus10;
    break;
  case 2:
    gain = btk::Analog::PlusMinus5;
    break;
  case 3:
    gain = btk::Analog::PlusMinus2Dot5;
    break;
  case 4:
    gain = btk::Analog::PlusMinus1Dot25;
    break;
  case 5:
    gain = btk::Analog::PlusMinus1;
    break;
  default:
    mexErrMsgTxt("Unknown gain. Read the documentation of this fuction to know the possible values");
  }
  analog->SetGain(gain);

  // Return updated analog channels
  btkMXCreateAnalogsStructure(acq, nlhs, plhs);
};

