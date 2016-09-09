// ======================================================================
//
// Copyright (c) 1997 The CGAL Consortium
//
// This software and related documentation is part of the
// Computational Geometry Algorithms Library (CGAL).
//
// Every use of CGAL requires a license. Licenses come in three kinds:
//
// - For academic research and teaching purposes, permission to use and
//   copy the software and its documentation is hereby granted free of  
//   charge, provided that
//   (1) it is not a component of a commercial product, and
//   (2) this notice appears in all copies of the software and
//       related documentation.
// - Development licenses grant access to the source code of the library 
//   to develop programs. These programs may be sold to other parties as 
//   executable code. To obtain a development license, please contact
//   the CGAL Consortium (at cgal@cs.uu.nl).
// - Commercialization licenses grant access to the source code and the
//   right to sell development licenses. To obtain a commercialization 
//   license, please contact the CGAL Consortium (at cgal@cs.uu.nl).
//
// This software and documentation is provided "as-is" and without
// warranty of any kind. In no event shall the CGAL Consortium be
// liable for any damage of any kind.
//
// The CGAL Consortium consists of Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Free University of Berlin (Germany),
// INRIA Sophia-Antipolis (France), Max-Planck-Institute Saarbrucken
// (Germany), RISC Linz (Austria), and Tel-Aviv University (Israel).
//
// ----------------------------------------------------------------------
//
// release       : CGAL-1.1
// release_date  : 1998, July 24
//
// file          : include/CGAL/IO/File_writer_inventor.h
// package       : Polyhedron_IO (1.9)
// chapter       : $CGAL_Chapter: Support Library ... $
// source        : polyhedron_io.fw
// revision      : $Revision: 1.6 $
// revision_date : $Date: 1998/06/03 20:34:54 $
// author(s)     : Lutz Kettner
//
// coordinator   : Herve Bronnimann
//
// Writer for polyhedral surfaces in OpenInventor format (.iv)
// email         : cgal@cs.uu.nl
//
// ======================================================================

#ifndef CGAL_IO_FILE_WRITER_INVENTOR_H
#define CGAL_IO_FILE_WRITER_INVENTOR_H 1
#ifndef CGAL_BASIC_H
#include <CGAL/basic.h>
#endif // CGAL_BASIC_H
#ifndef CGAL_PROTECT_IOSTREAM_H
#include <iostream.h>
#define CGAL_PROTECT_IOSTREAM_H
#endif // CGAL_PROTECT_IOSTREAM_H

class CGAL_File_writer_inventor {
    ostream*      out;
    size_t        _facets;
public:
    CGAL_File_writer_inventor() {}
    void header( ostream& o,
                 size_t vertices,
                 size_t halfedges,
                 size_t facets);
    void footer() const;

    void write_vertex( const double& x, const double& y, const double& z) {
        *out << "            " << x << ' ' << y << ' ' << z << ',' << '\n';
    }
    void write_facet_header() const;

    void write_facet_begin( size_t no) {
        *out << "            ";
    }
    void write_facet_vertex_index( size_t index) {
        *out << index << ',';
    }
    void write_facet_end() {
        *out << "-1,\n";
    }
};
#endif // CGAL_IO_FILE_WRITER_INVENTOR_H //
// EOF //