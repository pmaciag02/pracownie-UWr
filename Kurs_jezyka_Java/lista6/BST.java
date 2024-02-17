import org.w3c.dom.Node;

class BST <T extends Comparable<T>> implements Dictionary<T>
{
    private class Node <T extends Comparable<T>>
    {
        Node<T> left, right;
        T value;
        // wewnętrzna implementacja metod słownikowych...

        Node(T value) {
            this.value = value;
            this.left = this.right = null;
        }
    }
    
    private Node<T> root; // korzeń drzewa BST
    // opakowanie dla metod słownikowych zdefiniowanych w węzłach...

    public BST() {
        this.root = null;
    }

    @Override
    public boolean search(T x) {
        return search(root, x);
    }

    private boolean search(Node<T> root, T x) {
        if (root == null) {
            return false;
        }

        int compareResult = x.compareTo(root.value);

        if (compareResult < 0) {
            return search(root.left, x);
        } else if (compareResult > 0) {
            return search(root.right, x);
        } else {
            return true; // Znaleziono element
        }
    }

    @Override
    public void insert(T x) {
        if (x == null) {
            throw new IllegalArgumentException("Wartość nie może być null");
        }
        root = insert(root, x);
    }

    private Node insert(Node<T> root, T x) {
        if (root == null) {
            return new Node(x);
        }

        int compareResult = x.compareTo(root.value);

        if (compareResult < 0) {
            root.left = insert(root.left, x);
        } else if (compareResult > 0) {
            root.right = insert(root.right, x);
        }

        return root;
    }

    @Override
    public void remove(T x) {
        root = remove(root, x);
    }

    private Node remove(Node<T> root, T x) {
        if (root == null) {
            return null;
        }

        int compareResult = x.compareTo(root.value);

        if (compareResult < 0) {
            root.left = remove(root.left, x);
        } else if (compareResult > 0) {
            root.right = remove(root.right, x);
        } else {
            // Znaleziono węzeł do usunięcia
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            }

            // Węzeł ma dwoje dzieci, znalezienie najmniejszego w prawym poddrzewie
            root.value = minValue(root.right);
            root.right = remove(root.right, root.value);
        }

        return root;
    }

    private T minValue(Node<T> root) {
        T minValue = root.value;
        while (root.left != null) {
            minValue = root.left.value;
            root = root.left;
        }
        return minValue;
    }

    @Override
    public T min() {
        if (isEmpty()) {
            throw new IllegalStateException("Puste drzewo");
        }
        return minValue(root);
    }

    @Override
    public T max() {
        if (isEmpty()) {
            throw new IllegalStateException("Puste drzewo");
        }
        return maxValue(root);
    }

    private T maxValue(Node<T> root) {
        T maxValue = root.value;
        while (root.right != null) {
            maxValue = root.right.value;
            root = root.right;
        }
        return maxValue;
    }

    // @Override
    public int size() {
        return size(root);
    }

    private int size(Node<T> root) {
        if (root == null) {
            return 0;
        }
        return 1 + size(root.left) + size(root.right);
    }

    // @Override
    public void clear() {
        root = null;
    }

    private boolean isEmpty() {
        return root == null;
    }


    

    public Node getRoot() {
        return root;
    }

    public T RootValue() {
        return root.value;
    }

    // public BST(Node<T> n) {
    //     this.root = n;
    // }
    // public BST getLeft() {
    //     return BST(root.left);
    // }

    // public static void main(String[] args) {
    //     BST<Integer> bst = new BST<>();
    //     bst.insert(5);
    //     bst.insert(2);
    //     bst.insert(8);

    //     System.out.println("Search 2: " + bst.search(2)); // true
    //     System.out.println("Search 7: " + bst.search(7)); // false

    //     System.out.println("Min: " + bst.min()); // 2
    //     System.out.println("Max: " + bst.max()); // 8

    //     bst.remove(5);
    //     System.out.println("Search 5 after removal: " + bst.search(5)); // false

    //     System.out.println("Size: " + bst.size()); // 2
    //     bst.clear();
    //     System.out.println("Size after clear: " + bst.size()); // 0
    // }
}


