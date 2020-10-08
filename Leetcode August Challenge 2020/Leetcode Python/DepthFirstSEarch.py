from collections import defaultdict 
class Graph:
    def __init__(self):
        self.graph=defaultdict(list)
    def addEdge(self,u,v):
        self.graph[u].append(v)
    def DFSF(self,v,vs):
        vs[v]=True
        print(v,end=' ')
        for i in self.graph[v]:
            if vs[i]==False:
                self.DFSF(i,vs)
    def DFS(self,v):
        vs=[False]*(max(self.graph)+1)
        self.DFSF(v,vs)
g = Graph() 
g.addEdge(0, 1) 
g.addEdge(0, 2) 
g.addEdge(1, 2) 
g.addEdge(2, 0) 
g.addEdge(2, 3) 
g.addEdge(3, 3) 
n=int(input("Enter Starting node: "))
print ("Depth First Traversal"
                  " (starting from vertex :",n)
g.DFS(n) 
