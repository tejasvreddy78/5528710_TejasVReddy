def decodeHuff(root, s):
    node = root
    for bit in s:
        node = node.left if bit == '0' else node.right
        if node.left is None and node.right is None:
            print(node.data, end="")
            node = root