from queue import PriorityQueue
"""
    The idea:
        Using max heap
        - Each topic: We use calculate new z_score and difference between old z_score
            and new z_score then put [ID, new_score, diff score] into heap (maximun O(log(N-1))
        - After that We get top 5 trends from heap (O(5*log(N)))
    -> The complexity: O(logN)
"""
class PQEntry:
    def __init__(self, id = 0, score = 0, diff_score = 0):
        self.id = id
        self.score = score
        self.diff_score = diff_score
    def __lt__(self, other):
        if self.diff_score > other.diff_score:
            return True
        elif self.diff_score== other.diff_score:
            return self.id > other.id
        return False

def cal_score(topic):
    topic[2] *= 50
    topic[3] *= 5
    topic[4] *= 10
    topic[5] *= 20
    new_z_score =  topic[2] + topic[3] + topic[4] + topic[5]
    diff_z_score = new_z_score - topic[1]
    return [topic[0],new_z_score,diff_z_score]
if __name__=="__main__":
    q = PriorityQueue()
    n = int(input())
    for i in range(n):
        topic = list(map(int,input().strip().split()))
        z_score = cal_score(topic)
        q.put(PQEntry(z_score[0],z_score[1],z_score[2]))
    for i in range(5):
        trend = q.get()
        print(trend.id, trend.score)