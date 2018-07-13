# python3
import sys

# NA = -1
#
# class Node:
# 	def __init__ (self):
# 		self.next = [NA] * 4

def build_trie(patterns):
    tree = dict()
    # write your code here
    # node -> loc : c
    tree[0] = dict()
    loc = 1
    for pat in patterns:
        node = 0
        for i in range(len(pat)):
            if node not in tree:
                tree[node] = dict()
            if pat[i] in tree[node]:
                node = tree[node][pat[i]] # get the next node
            else:
                tree[node][pat[i]] = loc
                node = loc
                loc += 1
    # print(tree)
    return tree

def matching(text, tree):
	l = len(text)
	v = 0 # tree
	i = 0 # text
	pp = text[i]
	while True:
		if v not in tree:
			return True
		elif pp in tree[v]:
			v = tree[v][pp]
			if i < l-1:
				i += 1
				pp = text[i]
			elif v in tree:
				return False
		else:
			return False

def solve(text, patterns):
	result = []

	# write your code here
	tree = build_trie(patterns)
	# print(tree)
	for i in range(len(text)):
		if matching(text[i:], tree):
			result.append(i)

	return result

text = sys.stdin.readline ().strip ()
n = int (sys.stdin.readline ().strip ())
patterns = []
for i in range (n):
	patterns += [sys.stdin.readline ().strip ()]

ans = solve (text, patterns)

sys.stdout.write (' '.join (map (str, ans)) + '\n')
