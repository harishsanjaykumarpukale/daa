from collections import defaultdict
import heapq as hq
wt = defaultdict(int)
wet = defaultdict(int)
m = int(input())
adj = defaultdict(list)

for i in range(0,m):
  u,v,w=map(int,input().split())
  adj[u].append(v)
  adj[v].append(u)
  wt[(u,v)] = w

for (u,v) in list(wt):
  wet[(u,v)] = wt[(u,v)]
  wet[(v,u)] = wt[(u,v)]
  
cost=[]
inf=0
for (u,v) in wt:
  inf+=wt[(u,v)]

def minAndNotVis(dis,vis):
  minivertex =  vis.index(0)
  
  for w in range(1,301):
    if(dist[w] < dist[minivertex] and vis[w]==0):
      minivertex = w
  return minivertex 
  
  
def dijkstra(s):
  dist[s]=0
  dili = dist.copy()
  hq.heapify(dili)
  vis=[0]*301
  vis[0]=1
  for _ in range(1,301):
    try:
      u = dist.index(hq.heappop(dili))
    except:
      continue
    vis[u]=1
    for a in adj[u]:
      if vis[a]==0 and dist[a] > dist[u] + wet[(u,a)]:
        dist[a]=dist[u] + wet[(u,a)]
        hq.heappush(dili,dist[a])
        
        
for (u,v) in list(wt):
  adj[u].remove(v)
  adj[v].remove(u)
  
  dist = [inf]*301
  dijkstra(v)
  if(dist[u]!=inf):
    cost.append(dist[u]+wt[(u,v)])
    
  adj[u].append(v)
  adj[v].append(u)
  
print(min(cost))
