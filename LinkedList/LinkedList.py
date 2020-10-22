# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

class Node :
    def __init__(self,value=None):
        self.next_node=None
        self.past_node = None
        self.value=value

    def get_data(self):

        return self.value

    def set_next(self, nextnode = None):
        self.next_node = nextnode
    def get_next(self):
        return self.next_node

class LinkedList:
    def __init__(self,head=None):
        self.head= head
    def search( self , value ):

        tmp_node=self.head
        found = False
        while tmp_node and found is False :
            if tmp_node.get_data() == value:
                found=True
            else:
                tmp_node=tmp_node.get_next()
        if tmp_node is None:
            raise ValueError('Data in  not in List' )
        print('find node : %d' %tmp_node.get_data())
        return tmp_node
    def delete(self,value):
        tmp_node = self.head
        previous = None
        delete =False
        while tmp_node and delete is False  :
            if tmp_node.get_data() == value :
                delete = True
            else:
                previous = tmp_node
                tmp_node = tmp_node.get_next()
        if tmp_node is None :
            raise ValueError('Data is not in List')
        if previous == None :
            self.head = tmp_node.get_next()
        else :
            previous.set_next(tmp_node.get_next())




    def insert(self , value):

        node = Node(value=value)

        self.tail.set_next(node)

        self.tail = node



# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    n1 = Node(value = 3)
    l1 = LinkedList(head=n1)
    l1.insert(4)
    l1.insert(5)

    l1.search(7)
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
