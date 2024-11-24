def aoStar(graph, H, startNode):    

    openList  = list()
    closeList = list() 
    G = dict()         
    S = dict()         
    P = dict()         
    U = dict()         
    
    openList.append([startNode])   
    H[startNode] = 0               
    G[startNode] = 0               
    S[startNode] = False           
    P[startNode] = startNode      
    U[startNode] = False


    while S[startNode]==False:     
        print("--------------------------------------------------------------------------------------")
        print(openList)
        print(closeList)
        print(H)
        print(S)
        print("---------------------------------------------------------------------------------------")
       
        bestNodeList=None
        bestNodeCost=0
        for nodeList in openList:
            currentNodeListHCost=0
            currentNodeListGCost=0
            for node in nodeList:
                currentNodeListHCost = currentNodeListHCost + H[node]
                currentNodeListGCost = currentNodeListGCost + 1
            currentNodeListGCost=currentNodeListGCost + G[P[nodeList[0]]]      
            if bestNodeList==None or bestNodeCost>(currentNodeListGCost+currentNodeListHCost):
                bestNodeList=nodeList
                bestNodeCost=(currentNodeListGCost+currentNodeListHCost)
            print((currentNodeListGCost+currentNodeListHCost),":",nodeList)
        openList.remove(bestNodeList)              
        closeList.append(bestNodeList)
                         
                                        
        for node in bestNodeList:                 
            if graph.get(node,None) == None:      
                S[node]=True                      
            elif S[node]==True:
                continue
            else:            
                for childNodeList in graph[node]: 
                    if childNodeList not in openList and childNodeList not in closeList:
                        openList.append(childNodeList)
                        
                        for child in childNodeList:
                            U[child] = False
                            S[child] = False
                            P[child] = node
                            G[child] = G[node] + 1        
                    else:
                        for child in childNodeList:
                            if G[child] > G[node] + 1:
                                U[child] = False
                                S[child] = False
                                G[child] = G[node] + 1
                                P[child] = node         

                    if childNodeList in closeList: 
                        closeList.remove(childNodeList)
                        openList.append(childNodeList)
    
        solved=True                                 
        HeuristicCost=0
        for node in bestNodeList:
            solved=solved & S[node]
            HeuristicCost = HeuristicCost + H[node]

        if solved == True:                          
            for node in bestNodeList:
                if U[P[node]] == False:             
                    U[P[node]] = True
                    S[P[node]] = True
                    H[P[node]] = HeuristicCost + len(bestNodeList)
                    break
                    
                elif H[P[node]] > (HeuristicCost + len(bestNodeList)):  
                    H[P[node]]  = (HeuristicCost + len(bestNodeList))  
                    S[P[node]]  = True
                    break
            
            for andedOrNodes in AOList:               
                for node in bestNodeList:
                    if P[node] in andedOrNodes:
                        status  = True
                        for aoNode in andedOrNodes:                 
                            status = status & S[aoNode]
                        if status==True:                 
                            if andedOrNodes not in openList:            
                                openList.append(andedOrNodes)
    print("Final Heuristic values of nodes:",H)
    print("Final Solved status of nodes:",S)
                                       
h1 = {'A': 0, 'B': 4, 'C': 2, 'D': 3, 'E': 6, 'F': 8, 'G': 2, 'H': 0, 'I': 0, 'J': 0}
graph1 = {                                                                             
    'A': [['C', 'D'], ['B']],
    'B': [['E'], ['F']],
    'C': [['G'],['H', 'I']],
    'D': [['J']]   
}
AOList=[['A'],['B'],['C','D'],['E'],['F'],['G'],['H','I'],['J']]                 
aoStar(graph1, h1, 'A')                                                       

h2 = {'A': 1, 'B': 6, 'C': 2, 'D': 12, 'E': 2, 'F': 1, 'G': 5, 'H': 7, 'I': 7, 'J': 1, 'T': 3}
graph2 = {
    'A': [['B','C'], ['D']],
    'B': [['G'], ['H']],
    'C': [['J']],
    'D': [['E','F']],
    'G': [['I']]   
}
AOList=[['A'],['B','C'],['D'],['G'],['H'],['J'],['E','F'],['I']]
aoStar(graph2, h2, 'A')
print("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&")
h3 = {'A': 1, 'B': 6, 'C': 12, 'D': 11, 'E': 4, 'F': 4, 'G': 5, 'H': 7}  # Heuristic values of Nodes 

graph3 = {         
    'A': [['B','C'], ['D']],                     
    'B': [['G'], ['H']],                      
    'D': [['E','F']]                            
}
AOList=[['A'],['B','C'],['D'],['G'],['H'],['E','F']]
aoStar(graph3, h3, 'A')