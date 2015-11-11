#!/usr/bin/env cython

#---- licence header
###############################################################################
## file :               ChunkParser.pyx
##
## description :        This file has been made to provide a python access to
##                      the Pylon SDK from python.
##
## project :            TANGO
##
## author(s) :          S.Blanch-Torn\'e
##
## Copyright (C) :      2015
##                      CELLS / ALBA Synchrotron,
##                      08290 Bellaterra,
##                      Spain
##
## This file is part of Tango.
##
## Tango is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## Tango is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with Tango.  If not, see <http:##www.gnu.org/licenses/>.
##
###############################################################################


cdef extern from "pylon/ChunkParser.h" namespace "Pylon":
    cdef cppclass IChunkParser:
        void AttachBuffer( void*, int64_t, AttachStatistics_t* )
        void DetachBuffer()
        void UpdateBuffer()
        bool HasCRC()
        bool CheckCRC()
    cdef cppclass CChunkParser:
        AttachBuffer( void*, int64_t, AttachStatistics_t* )
        void DetachBuffer()
        void UpdateBuffer( void* )
        
cdef class __IChunkParser:
    pass
# 
# cdef class CChunkParserWrapper(IChunkParserWrapper):
#     pass

# cdef class ChunkParser(object):
#     cdef:
#         IPylonDevice* _pylonDevice
#         IChunkParser* _chunkParser
#     def __init__(self):
#         super(ChunkParser,self).__init__()
# 
# cdef ChunkParser_Init(IPylonDevice* pylonDevice):
#     res = ChunkParser()
#     res._pylonDevice = pylonDevice
#     try:
#         res._chunkParser = pylonDevice.CreateChunkParser()
#     except Exception,e:
#         print("ChunkParser_Init Exception: %s"%e)
#     return res