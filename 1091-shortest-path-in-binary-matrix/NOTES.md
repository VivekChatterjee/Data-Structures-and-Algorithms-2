We don't need priority queue in this question as it will increase our time complexity by sorting elements with log n.
Reason we won't use PQ:
* If we use simple queue, elements would be stored in same manner as in PQ
* Distances are incremented by 1 only so distance +1 will be stored in the queue
* As all distances would be same, we don't need PQ to sort them out
* We used PQ when different distances were incremented