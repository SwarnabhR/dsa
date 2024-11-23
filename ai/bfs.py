from collections import deque
from typing import List, Dict, Set, Optional

class Node:
    def __init__(self, state: str, parent: Optional['Node'] = None, depth: int = 0):
        self.state = state
        self.parent = parent
        self.depth = depth
    def __repr__(self):
        return f"Node(state={self.state}, depth={self.depth})"
class BreadthFirstSearch:
    def __init__(self):
        self.visited: Set[str] = set()
        self.expanded: Set[str] = set()
        self.queue: deque = deque()
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
    def is_goal(self, state: str) -> bool:
        return state == 'I'
    def reconstruct_path(self, node: Node) -> List[str]:
        path = []
        current = node
        while current:
            path.append(current.state)
            current = current.parent
        return list(reversed(path))
    def search(self, start_state: str) -> Optional[List[str]]:
        start_node = Node(start_state)
        self.queue.append(start_node)
        self.visited.add(start_state)
        while self.queue:
            current_node = self.queue.popleft()
            current_state = current_node.state

            print(f"Exploring node: {current_node}")
            print(f"Queue: {[node.state for node in self.queue]}")
            if self.is_goal(current_state):
                self.path_to_goal = self.reconstruct_path(current_node)
                return self.path_to_goal
            self.expanded.add(current_state)
            for successor_state in self.get_successors(current_state):
                if successor_state not in self.visited:
                    successor_node = Node(
                        state = successor_state,
                        parent = current_node,
                        depth = current_node.depth + 1
                    )
                    self.queue.append(successor_node)
                    self.visited.add(successor_state)
            print(f"Visited: {self.visited}")
            print(f"Expanded: {self.expanded}\n")
        return None
    def get_search_stats(self) -> Dict:
        return {
            'visited_states': len(self.visited),
            'expanded_states': len(self.expanded),
            'path_length': len(self.path_to_goal) if self.path_to_goal else 0,
            'path': self.path_to_goal
        }
def main():
    bfs = BreadthFirstSearch()
    start_state = 'A'
    print(f"Starting BFS from state {start_state}")
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

