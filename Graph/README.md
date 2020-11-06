# Graph

## graph 란?

### 1.vetex혹은 node라고 불리는 것들의 finite set이다.

### 2. node의 pair인 (u,v) , 혹은 엣지라 불리는 것들의 finite set이다. 이 pair의 원소들의 순서는 정해져 있다. 왜냐하면 , (u,v) 와 (v,u)가 유향 그래프에서는 같지 않기 때문이다.
### edge는 가중치(weight), value,cost의 값을 가질수 있다.


## graph를 표현하는방법

### 1. matrix

![image](https://user-images.githubusercontent.com/50165842/98331453-f0358580-203f-11eb-8912-fc1799877e4f.png)


공간 : V**2

삭제 : O(1)
탐색: O(1)  -> u,v 간에 엣지가 존재하는지

vertex 삽입: O(V**2)
### 2. List
![image](https://user-images.githubusercontent.com/50165842/98331478-fb88b100-203f-11eb-90c2-dc828bffa034.png)
