/****************************************************************************
**
** This file is part of the Ponder library.
**
** The MIT License (MIT)
**
** Copyright (C) 2015-2018 Nick Trout.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
** THE SOFTWARE.
**
****************************************************************************/

#ifndef PONDER_USES_SERIALISE_HPP
#define PONDER_USES_SERIALISE_HPP

#include <ponder/class.hpp>
//#include <iostream>

namespace ponder {
namespace archive {
    
    namespace detail {
    } // namespace detail
    
    enum class ValueKind
    {
        UserObject
    };
    
//    class TextArchive
//    {
//    public:
//
//        struct Node
//        {
//        };
//
//        using node_t = Node;
//
//        node_t beginNode(node_t parent, ValueKind vk)
//        {
//            indent();
//            ++m_indent;
//
//            return Node();
//        }
//
//    private:
//
//        void indent()
//        {
//            for (auto i = 0u; i < m_indent; ++i)
//                m_stream << '\t';
//        }
//
//        std::ostream m_stream;
//        unsigned int m_indent{ 0 };
//    };

    template <class ARCHIVE>
    class ArchiveWriter
    {
    public:
        
        using archive_t = ARCHIVE;
        using node_t = typename archive_t::node_t;
        
        ArchiveWriter(archive_t& archive)
        :   m_archive(archive)
        {}
        
        void write(node_t parent, const UserObject& obj)
        {
            auto& item = m_archive.beginNode(obj);
            item.setValue(obj);
            m_archive.endNode(item);
        }
        
    private:
        
        archive_t m_archive;

    };
    
} // namespace archive
} // namespace ponder

#endif // PONDER_USES_SERIALISE_HPP
