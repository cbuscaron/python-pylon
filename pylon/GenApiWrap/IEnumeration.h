/*---- licence header
###############################################################################
## file :               IEnumeration.h
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

#ifndef IENUMERATION_H
#define IENUMERATION_H

#include "INode.h"
//#include "GenApi/IEnumeration.h"
//#include <iostream>
//#include <vector>
//#include "pylon/stdinclude.h"

class CppIEnumeration : public CppINode
{
public:
  CppIEnumeration(GenApi::INode* node);
  std::vector<std::string> getEntries();
  std::string getValue();
//  bool setValue(std::string);
//protected:
  //std::map<std::string, int64_t> _entries;
};

class CppIEnumEntry : public CppINode
{
public:
  CppIEnumEntry(GenApi::INode* node);
  std::string getValue();
};

#endif /* IENUMERATION_H */
