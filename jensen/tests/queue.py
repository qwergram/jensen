import unittest

class APIExistTest(unittest.TestCase):

    def setUp(self):
        from jensen import Queue
        self.item_class = Queue

    def test_documented_api(self):
        "Test that this class has the documented API"
        self.assertTrue(hasattr(self.item_class, "push"))
        self.assertTrue(hasattr(self.item_class, "pushFront"))
        self.assertTrue(hasattr(self.item_class, "pop"))
        self.assertTrue(hasattr(self.item_class, "size"))
    
    def test_push(self):
        item = self.item_class()
        self.assertEqual(item.size(), 0)
        item.push(b"test")
        self.assertEqual(item.size(), 1)
        self.assertEqual(item.pop(), b"test")
        self.assertEqual(item.size(), 0)

    def test_pushFront(self):
        item = self.item_class()
        self.assertEqual(item.size(), 0)
        item.push(b"test2")
        self.assertEqual(item.size(), 1)
        item.pushFront(b"test")
        self.assertEqual(item.size(), 2)
        self.assertEqual(item.pop(), b"test")
        self.assertEqual(item.size(), 1)
        self.assertEqual(item.pop(), b"test2")
        self.assertEqual(item.size(), 0)

    def test_push_empty(self):
        item = self.item_class()
        self.assertEqual(item.size(), 0)
        self.assertRaises(RuntimeError, item.pop)
        