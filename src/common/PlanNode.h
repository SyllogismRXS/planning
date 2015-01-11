#ifndef PLANNODE_H_
#define PLANNODE_H_
/// ---------------------------------------------------------------------------
/// @file PlanNode.h
/// @author Kevin DeMarco <kevin.demarco@gmail.com>
///
/// Time-stamp: <2014-04-14 21:29:06 syllogismrxs>
///
/// @version 1.0
/// Created: 14 Apr 2014
///
/// ---------------------------------------------------------------------------
/// @section LICENSE
/// 
/// The MIT License (MIT)  
/// Copyright (c) 2012 Kevin DeMarco
///
/// Permission is hereby granted, free of charge, to any person obtaining a 
/// copy of this software and associated documentation files (the "Software"), 
/// to deal in the Software without restriction, including without limitation 
/// the rights to use, copy, modify, merge, publish, distribute, sublicense, 
/// and/or sell copies of the Software, and to permit persons to whom the 
/// Software is furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in 
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
/// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
/// DEALINGS IN THE SOFTWARE.
/// ---------------------------------------------------------------------------
/// @section DESCRIPTION
/// 
/// The PlanNode class ...
/// 
/// ---------------------------------------------------------------------------

#include <iostream>

class PlanNode {
public:

     typedef enum PlanNodeType {
          none = 0,
          literal,
          action
     } PlanNodeType_t;

     void init (std::string text, int level)
     {
          level_ = level;
          text_ = text;
     }
     
     PlanNode(std::string text, int level)
     {
          this->init(text, level);
     }

     PlanNode()
     {
          this->init("NONE", 0);
     }

     void set_level(int level) { level_ = level; }
     int level() { return level_; }
     void set_type(PlanNodeType_t type) { type_ = type; }
     PlanNodeType_t type()  { return type_; }
protected:
private:
     int level_;
     std::string text_;
     PlanNodeType_t type_;
};

#endif
