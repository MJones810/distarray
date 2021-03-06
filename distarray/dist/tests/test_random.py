# encoding: utf-8
# ---------------------------------------------------------------------------
#  Copyright (C) 2008-2014, IPython Development Team and Enthought, Inc.
#  Distributed under the terms of the BSD License.  See COPYING.rst.
# ---------------------------------------------------------------------------

"""Test random.py"""

import unittest

from distarray.dist.context import Context
from distarray.dist.maps import Distribution
from distarray.dist.random import Random


class TestRandom(unittest.TestCase):
    """Test the Random classes methods, since the expected results are
    'random' we just check for the correct shape. Which is dumb, but
    better than nothing.
    """

    @classmethod
    def setUpClass(cls):
        cls.context = Context()
        cls.random = Random(cls.context)

    @classmethod
    def tearDownClass(cls):
        cls.context.close()

    def test_rand(self):
        shape = (3, 4)
        distribution = Distribution.from_shape(context=self.context,
                                               shape=shape)
        a = self.random.rand(distribution)
        self.assertEqual(a.shape, shape)

    def test_normal(self):
        shape = (3, 4)  # aka shape
        distribution = Distribution.from_shape(context=self.context,
                                               shape=shape)
        a = self.random.normal(distribution)
        self.assertEqual(a.shape, shape)

    def test_randint(self):
        low = 1
        shape = (3, 4)  # aka shape
        distribution = Distribution.from_shape(context=self.context,
                                               shape=shape)
        a = self.random.randint(distribution, low=low)
        self.assertEqual(a.shape, shape)

    def test_randn(self):
        shape = (3, 4)
        distribution = Distribution.from_shape(context=self.context,
                                               shape=shape)
        a = self.random.randn(distribution)
        self.assertEqual(a.shape, shape)

    def test_seed_same(self):
        """ Test that the same seed generates the same sequence. """
        shape = (8, 6)
        distribution = Distribution.from_shape(self.context, shape)
        seed = 0xfeedbeef
        # Seed and get some random numbers.
        self.random.seed(seed)
        a = self.random.rand(distribution)
        aa = a.toarray()
        # Seed again and get more random numbers.
        self.random.seed(seed)
        b = self.random.rand(distribution)
        bb = b.toarray()
        # For an explicit seed, these should match exactly.
        self.assertTrue((aa == bb).all())

    def test_seed_none(self):
        """ Test that if seed=None, the sequences are not deterministic. """
        shape = (8, 6)
        # Seed and get some random numbers.
        self.random.seed(None)
        d = Distribution.from_shape(self.context, shape)
        a = self.random.rand(d)
        aa = a.toarray()
        # Seed again and get more random numbers.
        self.random.seed(None)
        b = self.random.rand(d)
        bb = b.toarray()
        # For seed=None, these should *not* match.
        self.assertFalse((aa == bb).all())

    def test_engines_distinct(self):
        """ Test that each engine makes a different sequence of numbers. """

        def get_rand_array_per_engine(context, num_cols):
            """ Get a distarray of random numbers,
            with each row coming from a separate engine.
            """
            num_engines = len(context.targets)
            shape = (num_engines, num_cols)
            distribution = Distribution.from_shape(self.context,
                                                   shape=shape,
                                                   dist={0: 'b', 1: 'n'})
            darr = self.random.rand(distribution)
            return darr

        # Seed generators.
        seed = [0x12345678, 0xdeadbeef, 42]
        self.random.seed(seed)
        # Get array of random values, with one row per engine.
        a = get_rand_array_per_engine(self.context, 6)
        aa = a.toarray()
        # Each row should be different. We just test consecutive rows.
        # If the rows are not different, then the generators on
        # distinct engines are in the same state.
        num_rows = aa.shape[0]
        for r in range(num_rows - 1):
            r0 = aa[r, :]
            r1 = aa[r + 1, :]
            self.assertFalse((r0 == r1).all())


if __name__ == '__main__':
    unittest.main(verbosity=2)
