class DLL:
    def __init__(self):
        self.cur=None
        self.head=None
        self.end=None
        self.garbage=[]
        self.size=0
    def insert(self,node):
        node.previous=self.end
        self.end.next=node
        self.end=node
        self.size+=1
    def delete(self):
        if self.cur == self.head:
            self.head=self.cur.next
        if self.cur.previous is not None : self.cur.previous.next= self.cur.next
        if self.cur.next is not None: self.cur.next.previous=self.cur.previous
        self.garbage.append(self.cur)
        if self.cur.next!=None :self.cur=self.cur.next 
        else : self.cur=self.cur.previous
        self.size-=1
    def recovery(self):#  가장최근노드만
        node=self.garbage.pop()
        if node.previous is not None : node.previous.next=node
        else : self.head=node
        if node.next is not None : node.next.previous=node
        self.size+=1
    def D(self,steps):
        for i in range(steps) : 
            self.cur=self.cur.next
    def U(self,steps):
        for i in range(steps) :
            self.cur=self.cur.previous  
    def d_set(self,head):
        self.head=head
        self.end=head
        self.size+=1
class Node:
    def __init__(self,val):
        self.previous=None
        self.next=None
        self.val=val
    def get_value(self):
        return self.val