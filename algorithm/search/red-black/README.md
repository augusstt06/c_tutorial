## Red-Black Tree

기존 이진탐색트리의 노드의 어느 한쪽이 기형적으로 성장하게 되면 검색효율이 떨어진다는 단점을 보완하기 위해 고안된 알고리즘.

```bash
> 아래와 같은 트리구조를 가진다면 이진탐색트리의 성능을 보장할 수 없다.

                            root
                node1                  node2
        node3
node4
.
.
.
```

이진 탐색트리와의 차이점은 노드의 색을 표시하여 트리의 균형을 유지 하는 것이다.
따라서 노드구조체에 아래와 같이 색 구분을 위한 필드를 생성해야 한다.

```bash
typedef struct Node {
    struct Node* parent;
    struct Node* left;
    struct Node* right;

    enum { RED, BLACK } Color;

    Elementtype data;
} Node;
```

레드 블랙트리는 아래와 같은 규칙을 가진다.

- 모든 노드는 빨간색 또는 검은색이다.

- 뿌리노드는 검은색이다.

- 잎노드는 검은색이다.

- 빨간색 노드의 자식은 모두 검은색이다. 따라서 검은색 노드는 빨간색과 검은색 모두 자식으로 가질 수 있다.

- 뿌리노드와 모든 잎 노드 사이에 있는 검은색 노드의 수는 모두 동일하다.

```bash
> 간단한 예시
                            root (black)
                node1(red)                      node2(black)
        node3(black)   node4(black)                       node5 (red)
```
