#test by process1.py and process2.py

from kazoo.client import KazooClient

zk = KazooClient(hosts='127.0.0.1:2181')
zk.start()

from queue import Queue
q = Queue()

q1 = Queue()
q1.put(1)
q1.
def lock(myfunc):
    if not zk.exists("/shareLock/"):
        zk.create("/shareLock")
    node = zk.create("/shareLock/", ephemeral=True, sequence=True)
    num = node.split('/')[-1]
    locks = zk.get_children("/shareLock")
    locks = sorted(locks)
    if num == locks[0]:
        myfunc()
    else:
        watch_num = locks[0]
        for i in range(len(locks)):
            if locks[i] == num:
                watch_num = locks[i-1]
                break
        zk.exists("/shareLock/"+watch_num, watch=myfunc)