# encoding: utf-8
# ---------------------------------------------------------------------------
#  Copyright (C) 2008-2014, IPython Development Team and Enthought, Inc.
#  Distributed under the terms of the BSD License.  See COPYING.rst.
# ---------------------------------------------------------------------------

import unittest
from distarray import utils

from numpy import arange
from numpy.testing import assert_array_equal


class TestMultPartitions(unittest.TestCase):
    """
    Test the multiplicative parition code.
    """

    def test_mult_partitions(self):
        self.assertEqual(utils.mult_partitions(1, 2), [(1, 1)])
        self.assertEqual(utils.mult_partitions(2, 2), [(1, 2)])
        self.assertEqual(utils.mult_partitions(1, 7), [(1,) * 7])
        self.assertEqual(utils.mult_partitions(7, 2), [(1, 7)])
        self.assertEqual(utils.mult_partitions(7, 3), [(1, 1, 7)])
        self.assertEqual(utils.mult_partitions(16, 4), [(1, 1, 1, 16),
                                                        (1, 1, 2, 8),
                                                        (1, 1, 4, 4),
                                                        (1, 2, 2, 4),
                                                        (2, 2, 2, 2)])
        self.assertEqual(utils.mult_partitions(6, 3), [(1, 1, 6), (1, 2, 3)])


class TestSanitizeIndices(unittest.TestCase):

    def test_point(self):
        itype, inds = utils.sanitize_indices(1)
        self.assertEqual(itype, 'point')
        self.assertEqual(inds, (1,))

    def test_slice(self):
        itype, inds = utils.sanitize_indices(slice(1,10))
        self.assertEqual(itype, 'view')
        self.assertEqual(inds, (slice(1,10),))

    def test_mixed(self):
        provided = (5, 3, slice(7, 10, 2), 99, slice(1,10))
        itype, inds = utils.sanitize_indices(provided)
        self.assertEqual(itype, 'view')
        self.assertEqual(inds, provided)


class TestSliceIntersection(unittest.TestCase):

    def test_containment(self):
        arr = arange(20)
        slc = utils.slice_intersection(slice(1,10), slice(2, 4))
        assert_array_equal(arr[slc], arr[slice(2, 4, 1)])

    def test_overlapping(self):
        arr = arange(20)
        slc = utils.slice_intersection(slice(1,10), slice(4, 15))
        assert_array_equal(arr[slc], arr[slice(4, 10)])

    def test_disjoint(self):
        arr = arange(20)
        slc = utils.slice_intersection(slice(1,10), slice(11, 15))
        assert_array_equal(arr[slc], arr[slice(11, 10)])


class TestAllEqual(unittest.TestCase):

    def test_all_equal_false(self):
        self.assertFalse(utils.all_equal([1, 2, 3, 4, 5]))

    def test_all_equal_true(self):
        self.assertTrue(utils.all_equal([7, 7, 7, 7, 7]))

    def test_all_equal_vacuously_true(self):
        self.assertTrue(utils.all_equal([]))
        self.assertTrue(utils.all_equal([99]))


class TestHasExactlyOne(unittest.TestCase):

    def test_has_exactly_one_true(self):
        iterable = [None, None, None, 55, None]
        self.assertTrue(utils.has_exactly_one(iterable))

    def test_has_exactly_one_all_none(self):
        iterable = [None, None, None, None, None]
        self.assertFalse(utils.has_exactly_one(iterable))

    def test_has_exactly_one_multi_non_none(self):
        iterable = [None, 5, 'abc', None, None]
        self.assertFalse(utils.has_exactly_one(iterable))

if __name__ == '__main__':
    unittest.main(verbosity=2)
