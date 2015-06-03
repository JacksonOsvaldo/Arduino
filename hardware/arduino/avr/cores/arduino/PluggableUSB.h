/*
  IPAddress.h - Base class that provides IPAddress
  Copyright (c) 2011 Adrian McEwen.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef PUSB_h
#define PUSB_h

#include "USBAPI.h"
#include <stdint.h>

#if defined(USBCON)

typedef struct
{
  bool (*setup)(Setup& setup, u8 i);
  int (*getInterface)(u8* interfaceNum);
  int (*getDescriptor)(int t);
  int numEndpoints;
  u8 endpointType[6];
} PUSBCallbacks;

typedef struct
{
  u8 interface;
  u8 firstEndpoint;
} PUSBReturn;

int PUSBaddFunction(PUSBCallbacks *cb, PUSBReturn *ret);

int PUSB_GetInterface(u8* interfaceNum);

int PUSB_GetDescriptor(int t);

bool PUSB_Setup(Setup& setup, u8 i);

#endif

#endif
