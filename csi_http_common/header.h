//
// header.h
// ~~~~~~~~~~
// Copyright 2014 Svante Karlsson CSI AB (svante.karlsson at csi dot se)
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#pragma once
#include <string>
namespace csi
{
    namespace http
    {
        struct header_t
        {
            header_t() {}
            header_t(const std::string& n, const std::string& v) : name(n), value(v) {}
            std::string name;
            std::string value;
        };
    }; // namespace http
}; // namespace csi

