from typing import Dict, List, Set, Optional, Tuple
import heapq

class Node:
    def __init__(self, state: str, parent: Optional['Node'] = None, depth: int = 0, h_value: float = float('inf')):
        self.state = state
        self.parent = parent
        self.depth = depth
        self.h_value = h_value
        
    def __lt__(self, other):
        return self.h_value < other.h_value
    
    def __repr__(self):
        return f"Node(state={self.state}, h={self.h_value}, depth={self.depth})"

class BestFirstSearch:
    def __init__(self):
        self.visited: Set[str] = set()
        self.expanded: Set[str] = set()
        self.priority_queue: List[Tuple[float, Node]] = []
        self.path_to_goal: List[str] = []
        
    def get_successors(self, state: str) -> List[str]:
        graph = {
            'A': ['B', 'C'],
            'B': ['D', 'E'],
            'C': ['F', 'G'],
            'D': [],
            'E': ['H', 'I'],
            'F': [],
            'G': [],
            'H': [],
            'I': []
        }
        return graph.get(state, [])

    def heuristic(self, state: str) -> float:
        h_values = {
            'A': 7.0,
            'B': 4.0,
            'C': 6.0,
            'D': 3.0,
            'E': 5.0,
            'F': 2.0,
            'G': 0.0,
            'H': 4.0,
            'I': 6.0
        }
        return h_values.get(state, float('inf'))

    def is_goal(self, state: str) -> bool:
        return state == 'G'

    def reconstruct_path(self, node: Node) -> List[str]:
        path = []
        current = node
        while current:
            path.append(current.state)
            current = current.parent
        return list(reversed(path))

    def search(self, start_state: str) -> Optional[List[str]]:
        start_node = Node(start_state, h_value=self.heuristic(start_state))
        heapq.heappush(self.priority_queue, (start_node.h_value, start_node))
        self.visited.add(start_state)
        
        print(f"\nStarting Best-First Search from state {start_state}")
        
        while self.priority_queue:
            _, current_node = heapq.heappop(self.priority_queue)
            current_state = current_node.state
            
            print(f"\nExploring node: {current_node}")
            print(f"Priority Queue: {[(h,n.state) for h,n in self.priority_queue]}")
            
            if self.is_goal(current_state):
                self.path_to_goal = self.reconstruct_path(current_node)
                return self.path_to_goal
            
            self.expanded.add(current_state)
            
            for successor_state in self.get_successors(current_state):
                if successor_state not in self.visited:
                    successor_node = Node(
                        state=successor_state,
                        parent=current_node,
                        depth=current_node.depth + 1,
                        h_value=self.heuristic(successor_state)
                    )
                    heapq.heappush(self.priority_queue, (successor_node.h_value, successor_node))
                    self.visited.add(successor_state)
                    
            print(f"Visited: {self.visited}")
            print(f"Expanded: {self.expanded}")
        
        return None

    def get_search_stats(self) -> Dict:
        return {
            'visited_states': len(self.visited),
            'expanded_states': len(self.expanded),
            'path_length': len(self.path_to_goal) if self.path_to_goal else 0,
            'path': self.path_to_goal
        }

def main():
    bfs = BestFirstSearch()
    start_state = 'A'
    
    path = bfs.search(start_state)
    
    if path:
        print("\nPath found!")
        print(f"Path: {' -> '.join(path)}")
    else:
        print("\nNo path found!")
        
    stats = bfs.get_search_stats()
    print("\nSearch statistics:")
    print(f"States visited: {stats['visited_states']}")
    print(f"States expanded: {stats['expanded_states']}")
    print(f"Path length: {stats['path_length']}")

if __name__ == "__main__":
    main()