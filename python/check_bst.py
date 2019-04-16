import math

class Node:

	def __init__(self, data):
		self.data = data
		self.left = None 
		self.right = None

def check_bst(root, min, max):
	if root == None:
		return True

	if root.data > max or root.data <= min:
		return False

	return(check_bst(root.left, min, root.data) and check_bst(root.right, root.data, max))

if __name__ == "__main__":
	root = Node(6)
	a = Node(4)
	b = Node(7)
	c = Node(3) 
	d = Node(5)
	e = Node(6.5)
	f = Node(8)

	root.left = a
	root.right = b
	a.left = c
	a.right = d
	b.left = e
	b.right = f
	
	print(check_bst(root, -10000, 10000))