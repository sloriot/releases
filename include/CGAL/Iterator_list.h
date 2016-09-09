// Copyright (c) 2000  Max-Planck-Institute Saarbruecken (Germany).
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
// $Source: /CVSROOT/CGAL/Packages/Partition_2/include/CGAL/Iterator_list.h,v $
// $Revision: 1.7 $ $Date: 2003/10/21 12:22:18 $
// $Name: CGAL_3_0_1  $
//
// Author(s)     : Susan Hert <hert@mpi-sb.mpg.de>

#ifndef CGAL_ITERATOR_LIST_H
#define CGAL_ITERATOR_LIST_H

#include <list>

namespace CGAL {

template <class Iterator>
class Iterator_list : public std::list<Iterator> {

public:
  Iterator_list() {}

  Iterator_list(Iterator first, Iterator beyond) 
  {
      if (first == beyond) return;

      for (Iterator current = first; current != beyond; current++)
      {
         push_back(current);
      } 
  }
};

}

#endif // CGAL_ITERATOR_LIST_H