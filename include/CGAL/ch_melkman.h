// Copyright (c) 1999  Max-Planck-Institute Saarbruecken (Germany).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $Source: /CVSROOT/CGAL/Packages/Convex_hull_2/include/CGAL/ch_melkman.h,v $
// $Revision: 1.3 $ $Date: 2003/10/21 12:15:04 $
// $Name: CGAL_3_0_1  $
//
// Author(s)     : Lutz Kettner


#ifndef CGAL_CH_MELKMAN_H
#define CGAL_CH_MELKMAN_H

#include <CGAL/basic.h>
#include <iterator>

CGAL_BEGIN_NAMESPACE

template <class InputIterator, class OutputIterator, class Traits>
OutputIterator
ch_melkman( InputIterator first, InputIterator last,
            OutputIterator result, const Traits& ch_traits);


template <class InputIterator, class OutputIterator>
OutputIterator
ch_melkman( InputIterator first, InputIterator last,  OutputIterator result)
{ 
    typedef std::iterator_traits<InputIterator>   ITraits;
    typedef typename ITraits::value_type          value_type;
    typedef CGAL::Kernel_traits<value_type>       KTraits;
    typedef typename KTraits::Kernel              Kernel;
    return ch_melkman( first, last, result, Kernel()); 
}

CGAL_END_NAMESPACE

#ifdef CGAL_CFG_NO_AUTOMATIC_TEMPLATE_INCLUSION
#include <CGAL/ch_melkman.C>
#endif // CGAL_CFG_NO_AUTOMATIC_TEMPLATE_INCLUSION

#endif // CGAL_CH_MELKMAN_H
