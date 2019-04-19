import math

class Node:
	def __init__(self, data):
		self.data = data
		self.left = None 
		self.right = None

def find_height(root):
	if root == None:
		return 0
	else:
		return max(find_height(root.left), find_height(root.right)) + 1

def check_balanced_node(root):
	left_height = find_height(root.left)
	right_height = find_height(root.right)
	if abs(left_height-right_height) > 1:
		return False
	else:
		return 	True 

def check_balanced_tree(root):
	if root == None:
		return True
	else:
		return(check_balanced_tree(root.left) and check_balanced_tree(root.right) and check_balanced_node(root))

		

if __name__ == "__main__":
	root = Node(6)
	a = Node(4)
	b = Node(7)
	c = Node(3) 
	d = Node(5)
	e = Node(9)
	f = Node(8)

	root.left = a
	root.right = b
	a.left = c
	a.right = d
	b.left = e
	d.right = f
	f.right = e
	
	print(check_balanced_tree(root))