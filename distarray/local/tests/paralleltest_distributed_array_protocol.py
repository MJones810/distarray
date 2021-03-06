# encoding: utf-8
# ---------------------------------------------------------------------------
#  Copyright (C) 2008-2014, IPython Development Team and Enthought, Inc.
#  Distributed under the terms of the BSD License.  See COPYING.rst.
# ---------------------------------------------------------------------------

import unittest
import numpy as np
from numpy.testing import assert_array_equal

from distarray.externals import six
import distarray.local
from distarray.local.localarray import LocalArray
from distarray.local.maps import Distribution
from distarray.testing import MpiTestCase, CommNullPasser, validate_distbuffer


@six.add_metaclass(CommNullPasser)
class DapRoundTripEqualityMixin(object):

    """Mixin for running round-trip tests on DAP exports.

    NOTE: Dimensions with the 'n' dist_type are currently translated to 'b' on
    export, so these tests would not pass for LocalArrays with 'n' distributed
    dimensions.

    Overload `setUp` and add a `self.larr` LocalArray to run this test suite
    on.
    """

    def assert_round_trip_equality(self, larr):
        self.assertEqual(larr.dist, self.larr.dist)
        self.assertEqual(larr.global_shape, self.larr.global_shape)
        self.assertEqual(larr.ndim, self.larr.ndim)
        self.assertEqual(larr.global_size, self.larr.global_size)
        self.assertEqual(larr.comm_size, self.larr.comm_size)
        self.assertEqual(larr.comm_rank, self.larr.comm_rank)
        self.assertEqual(larr.cart_coords, self.larr.cart_coords)
        self.assertEqual(larr.grid_shape, self.larr.grid_shape)
        self.assertEqual(len(larr.distribution), len(self.larr.distribution))
        self.assertEqual(larr.local_shape, self.larr.local_shape)
        self.assertEqual(larr.ndarray.shape, self.larr.ndarray.shape)
        self.assertEqual(larr.ndarray.dtype, self.larr.ndarray.dtype)
        assert_array_equal(larr.ndarray, self.larr.ndarray)

    def test_round_trip_equality_from_object(self):
        larr = LocalArray.from_distarray(self.larr, comm=self.comm)
        self.assert_round_trip_equality(larr)

    def test_round_trip_equality_from_dict(self):
        larr = LocalArray.from_distarray(self.larr.__distarray__(),
                                         comm=self.comm)
        self.assert_round_trip_equality(larr)


@six.add_metaclass(CommNullPasser)
class DapValidatorMixin(object):

    """Mixin for running the DAP validator and testing elements.

    Overload `setUp` and add a `self.larr` LocalArray to run this test suite
    on.
    """

    def test_with_validator(self):
        validate_distbuffer(self.larr.__distarray__())

    def test_round_trip_elements(self):
        larr = LocalArray.from_distarray(self.larr, comm=self.comm)
        if self.comm.Get_rank() == 0:
            idx = (0,) * larr.ndarray.ndim
            larr.ndarray[idx] = 99
        assert_array_equal(larr.ndarray, self.larr.ndarray)


class TestDapBasic(DapValidatorMixin, MpiTestCase):

    def setUp(self):
        d = Distribution.from_shape((16, 16), grid_shape=(4, 1),
                                    comm=self.comm)
        self.larr = LocalArray(d)


class TestDapUint(DapValidatorMixin, MpiTestCase):

    def setUp(self):
        d = Distribution.from_shape((16, 16), grid_shape=(4, 1),
                                    comm=self.comm)
        self.larr = LocalArray(d, dtype='uint8', buf=None)


class TestDapComplex(DapValidatorMixin, MpiTestCase):

    def setUp(self):
        d = Distribution.from_shape((16, 16), grid_shape=(4, 1),
                                    comm=self.comm)
        self.larr = LocalArray(d, dtype='complex128', buf=None)


class TestDapExplicitNoDist0(DapValidatorMixin, MpiTestCase):

    def setUp(self):
        d = Distribution.from_shape((16, 16), dist={0: 'b', 1: 'n'},
                                    grid_shape=(4, 1), comm=self.comm)
        self.larr = LocalArray(d)


class TestDapExplicitNoDist1(DapValidatorMixin, MpiTestCase):

    def setUp(self):
        d = Distribution.from_shape((30, 60), dist={0: 'n', 1: 'b'},
                                    grid_shape=(1, 4), comm=self.comm)
        self.larr = LocalArray(d)


class TestDapTwoDistDims(DapRoundTripEqualityMixin, DapValidatorMixin,
                         MpiTestCase):

    def setUp(self):
        d = Distribution.from_shape((53, 77), dist={0: 'b', 1: 'b'},
                                    grid_shape=(2, 2), comm=self.comm)
        self.larr = LocalArray(d)


class TestDapThreeBlockDims(DapRoundTripEqualityMixin, DapValidatorMixin,
                            MpiTestCase):

    comm_size = 12

    def setUp(self):
        d = Distribution.from_shape((53, 77, 99),
                                    dist={0: 'b', 1: 'b', 2: 'b'},
                                    grid_shape=(2, 2, 3), comm=self.comm)
        self.larr = LocalArray(d)


class TestDapCyclicDim(DapValidatorMixin, MpiTestCase):

    def setUp(self):
        d = Distribution.from_shape((53, 77), dist={0: 'c'},
                                    grid_shape=(4, 1), comm=self.comm)
        self.larr = LocalArray(d)


class TestDapCyclicBlock(DapRoundTripEqualityMixin, DapValidatorMixin,
                         MpiTestCase):

    def setUp(self):
        d = Distribution.from_shape((53, 77), dist={0: 'c', 1: 'b'},
                                    grid_shape=(2, 2), comm=self.comm)
        self.larr = LocalArray(d)


class TestDapThreeMixedDims(DapValidatorMixin, MpiTestCase):

    def setUp(self):
        d = Distribution.from_shape((53, 77, 99),
                                    dist={0: 'b', 1: 'n', 2: 'c'},
                                    grid_shape=(2, 1, 2), comm=self.comm)
        self.larr = LocalArray(d, dtype='float64')


class TestDapLopsided(DapValidatorMixin, MpiTestCase):

    comm_size = 2

    def setUp(self):
        if self.comm.Get_rank() == 0:
            arr = np.arange(20)
        elif self.comm.Get_rank() == 1:
            arr = np.arange(30)

        d = Distribution.from_shape((50,), dist={0: 'b', 1: 'n'},
                                    grid_shape=(2,), comm=self.comm)

        self.larr = LocalArray(d, dtype='float64', buf=arr)

    def test_values(self):
        if self.comm.Get_rank() == 0:
            assert_array_equal(np.arange(20), self.larr.ndarray)
        elif self.comm.Get_rank() == 1:
            assert_array_equal(np.arange(30), self.larr.ndarray)

        larr = LocalArray.from_distarray(self.larr, comm=self.comm)
        if self.comm.Get_rank() == 0:
            assert_array_equal(np.arange(20), larr.ndarray)
        elif self.comm.Get_rank() == 1:
            assert_array_equal(np.arange(30), larr.ndarray)


if __name__ == '__main__':
    try:
        unittest.main()
    except SystemExit:
        pass
