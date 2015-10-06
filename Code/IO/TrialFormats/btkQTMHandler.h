/* 
 * The Biomechanical ToolKit
 * Copyright (c) 2009-2015, Arnaud Barré
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

#ifndef __btkQTMHandler_h
#define __btkQTMHandler_h

#include "btkTrialIOHandler.h"
#include "btkIOHandlerOption.h"
#include "btkMacros.h" // _BTK_CONSTEXPR, _BTK_NOEXCEPT

namespace btk
{
  class QTMHandlerPrivate;
  
  class BTK_IO_EXPORT QTMHandler : public TrialIOHandler
  {
    BTK_DECLARE_PIMPL_ACCESSOR(QTMHandler)
    
  public:
    QTMHandler();
    ~QTMHandler() _BTK_NOEXCEPT;
    
    QTMHandler(const QTMHandler& ) = delete;
    QTMHandler(QTMHandler&& ) _BTK_NOEXCEPT = delete;
    QTMHandler& operator=(const QTMHandler& ) = delete;
    QTMHandler& operator=(const QTMHandler&& ) _BTK_NOEXCEPT = delete;
    
    virtual Capability capability() const _BTK_NOEXCEPT final;
    
    virtual std::vector<const char*> supportedTrialFormats() const _BTK_NOEXCEPT final;
    
  protected:
    virtual Signature validateSignature() const _BTK_NOEXCEPT final;
    virtual void readDevice(Node* output) final;
  };
};

#endif // __btkQTMHandler_h