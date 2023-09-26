## BINARY SEARCH TREE


Q. 2019 KAKAO RECURITMENT 길찾기 게임
링크: https://programmers.co.kr/learn/courses/30/lessons/42892


# 내가 간과한점 :   
C++의 메모리 구조, 노드들을 생성할 때 지역변수로 생성하면 스택에 할당이 되어 스코프가 끝나면 자동 해제되므로 메모리가 살아잇지를 못한다.
따라서 , Free storage에 할당해줘야한다.


# 구현한 순회 : DFS

PostOrder :  노드 방문 직후 방문 했다 기록

PreOrder : 자식 노드를 다 방문한후 방문 했다 기록
