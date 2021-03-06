# encoding: utf-8
# ---------------------------------------------------------------------------
#  Copyright (C) 2008-2014, IPython Development Team and Enthought, Inc.
#  Distributed under the terms of the BSD License.  See COPYING.rst.
# ---------------------------------------------------------------------------

import unittest

import numpy as np
from numpy.testing import assert_array_equal

from distarray.testing import MpiTestCase, assert_localarrays_equal
from distarray.local import arecompatible
import distarray.local.localarray as localarray
from distarray.local.localarray import LocalArray
from distarray.local.maps import Distribution


class TestFunctions(MpiTestCase):

    def test_arecompatible(self):
        """Test if two DistArrays are compatible."""
        d0 = Distribution.from_shape((16,16), comm=self.comm)
        a = LocalArray(d0, dtype='int64')
        b = LocalArray(d0, dtype='float32')
        self.assertTrue(arecompatible(a,b))

        da = Distribution.from_shape((16, 16), dist='c', comm=self.comm)
        a = LocalArray(da, dtype='int64')
        db = Distribution.from_shape((16, 16), dist='b', comm=self.comm)
        b = LocalArray(db, dtype='float32')
        self.assertFalse(arecompatible(a,b))

    def test_fromfunction(self):
        """Can we build an array using fromfunction and a trivial function?"""
        def f(*global_inds):
            return 1.0

        d = Distribution.from_shape((16, 16), dist=('b', 'c'), comm=self.comm)
        a = localarray.fromfunction(f, d, dtype='int64')
        self.assertEqual(a.global_shape, (16, 16))
        self.assertEqual(a.dtype, np.dtype('int64'))
        for global_inds, value in localarray.ndenumerate(a):
            self.assertEqual(1.0, value)

    def test_fromfunction_complicated(self):
        """Can we build an array using fromfunction and a nontrivial function."""
        def f(*global_inds):
            return sum(global_inds)

        d = Distribution.from_shape((16, 16), dist=('b', 'c'), comm=self.comm)
        a = localarray.fromfunction(f, d,  dtype='int64')
        self.assertEqual(a.global_shape, (16,16))
        self.assertEqual(a.dtype, np.dtype('int64'))
        for global_inds, value in localarray.ndenumerate(a):
            self.assertEqual(sum(global_inds), value)

    def test_fromndarray_like(self):
        """Can we build an array using fromndarray_like?"""
        d = Distribution.from_shape((16, 16), dist=('c', 'b'), comm=self.comm)
        la0 = LocalArray(d, dtype='int8')
        la1 = localarray.fromndarray_like(la0.ndarray, la0)
        assert_localarrays_equal(la0, la1, check_dtype=True)

class TestCreationFunctions(MpiTestCase):

    def test_empty(self):
        size = self.comm_size
        nrows = size * 3
        d = Distribution.from_shape((nrows, 20), comm=self.comm)
        a = localarray.empty(d)
        self.assertEqual(a.global_shape, (nrows, 20))

    def test_zeros(self):
        size = self.comm_size
        nrows = size * 3
        d = Distribution.from_shape((nrows, 20), comm=self.comm)
        a = localarray.zeros(d)
        expected = np.zeros((nrows // size, 20))
        assert_array_equal(a.ndarray, expected)

    def test_ones(self):
        size = self.comm_size
        nrows = size * 3
        d = Distribution.from_shape((nrows, 20), comm=self.comm)
        a = localarray.ones(d)
        expected = np.ones((nrows // size, 20))
        assert_array_equal(a.ndarray, expected)


if __name__ == '__main__':
    try:
        unittest.main()
    except SystemExit:
        pass
