import unittest
import fizzbuzz.py

class TestStringMethods(unittest.TestCase):

    def test_fizz(self):
        self.assertEqual(test_gate(['3']), 'fizz')

    def test_buzz(self):
        self.assertEqual(test_gate(['5']), 'buzz')

    def test_none(self):
        self.assertEqual(test_gate(['2']), '2')

    def test_complex(self):
        self.assertEqual(test_gate(['535555555555', '5500000000000000000000000', '10', '15',
                '35',  '000',  '-2', '-67', '-55']), 'buzz fizzbuzz buzz fizzbuzz buzz fizzbuzz -2 -67 buzz')

if __name__ == '__main__':
    unittest.main()