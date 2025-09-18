class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False

def noPrefix(words):
    root = TrieNode()

    for word in words:
        node = root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]

            if node.is_end:
                print("BAD SET")
                print(word)
                return

        if node.children:
            print("BAD SET")
            print(word)
            return

        node.is_end = True

    print("GOOD SET")