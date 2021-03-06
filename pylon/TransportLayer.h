/*---- licence header
###############################################################################
## file :               TransportLayer.h
##
## description :        This file has been made to provide a python access to
##                      the Pylon SDK from python.
##
## project :            python-pylon
##
## author(s) :          S.Blanch-Torn\'e
##
## Copyright (C) :      2015
##                      CELLS / ALBA Synchrotron,
##                      08290 Bellaterra,
##                      Spain
##
## This file is part of python-pylon.
##
## python-pylon is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## python-pylon is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with python-pylon.  If not, see <http://www.gnu.org/licenses/>.
##
###############################################################################
*/

#ifndef TRANSPORTLAYER_H
#define TRANSPORTLAYER_H

#include <pylon/PylonIncludes.h>
#include "Logger.h"
#include "DevInfo.h"

class CppTransportLayer : public Logger
{
public:
  CppTransportLayer(Pylon::CTlInfo);
  ~CppTransportLayer();
  Pylon::String_t getTlClass();
  int EnumerateDevices();
  Pylon::DeviceInfoList_t::iterator getFirst();
  Pylon::DeviceInfoList_t::iterator getLast();
  CppDevInfo* buildDeviceInfo(Pylon::CDeviceInfo);
private:
  Pylon::ITransportLayer *tl;
  Pylon::CTlInfo info;
  Pylon::DeviceInfoList_t _deviceList;
  Pylon::DeviceInfoList_t::iterator _deviceIterator;
};

#endif /* TRANSPORTLAYER_H */
