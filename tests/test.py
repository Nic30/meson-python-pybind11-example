import unittest
from mesonPythonPybind11Example.myLib2 import addPy
from mesonPythonPybind11Example._mesonPythonPybind11Example import add, is_even


class TestCase(unittest.TestCase):

    def test_addPy(self):
        self.assertEqual(addPy(1, 1), 2)

    def test_add(self):
        self.assertEqual(add(1, 1), 2)

    def test_is_even(self):
        self.assertTrue(is_even(0))
        self.assertFalse(is_even(1))


if __name__ == '__main__':
    unittest.main()
