/*---- licence header
###############################################################################
## file :               Camera.h
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

#ifndef CAMERA_H
#define CAMERA_H

#include <pylon/PylonIncludes.h>
//#include <pylon/gige/BaslerGigECamera.h>
#include <GenApi/INode.h>
#include "Logger.h"
#include "DevInfo.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include "PyCallback.h"

class CppCamera : public Logger
{
protected:
  CppCamera(){};
public:
  CppCamera( Pylon::CInstantCamera::DeviceInfo_t,
             Pylon::IPylonDevice*, Pylon::CInstantCamera* );
  ~CppCamera();
  bool IsCameraPresent();
  bool IsOpen();
  bool Open();
  bool Close();
  bool IsGrabbing();
  bool Snap(void*, size_t&, uint32_t&, uint32_t&, Pylon::EPixelType&);
  bool Start();
  bool Stop();
  bool getImage(Pylon::CPylonImage *image);

  uint32_t GetNumStreamGrabberChannels();
  unsigned int getGrabTimeout();
  void setGrabTimeout(unsigned int);

  GenApi::INode *getNextNode();
  GenApi::INode *getTLNextNode();
  GenApi::INode *getNode(std::string name);
  GenApi::INode *getTLNode(std::string name);

  //Camera Removal notification to upper layers
  std::vector<PyCallback*>::iterator registerRemovalCallback(PyCallback*);
  void deregisterRemovalCallback(std::vector<PyCallback*>::iterator pos);
protected:
  Pylon::CInstantCamera::DeviceInfo_t devInfo;
  Pylon::IPylonDevice *pylonDevice;
  Pylon::CInstantCamera *instantCamera;
  unsigned int grabTimeout;
  //INodes
  GenApi::INodeMap *control;
  GenApi::NodeList_t nodesList;
  void prepareNodeIteration();
  GenApi::NodeList_t::iterator controlIt;
  //INodes TL
  GenApi::INodeMap *control_tl;
  GenApi::NodeList_t nodesList_tl;
  void prepareTLNodeIteration();
  GenApi::NodeList_t::iterator controlIt_tl;
  //StreamGrabber
  bool HasStreamGrabber();
  Pylon::IStreamGrabber* streamGrabber;
  void prepareStreamGrabber();
  //EventGrabber
  Pylon::IEventGrabber *eventGrabber;
  Pylon::IEventAdapter *eventAdapter;
  Pylon::WaitObjects waitObjects;
  void prepareEventGrabber();
  //Camera Removal handler
  bool cameraPresent;
  Pylon::DeviceCallbackHandle cbHandle;
  std::vector<PyCallback*> aboveCallbacks;
  void prepareRemovalCallback();
  void removalCallback(Pylon::IPylonDevice* pDevice);
};

#endif /* CAMERA_H */
