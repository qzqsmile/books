from kazoo.client import KazooClient
from zookeeper.d_lock.lock import lock

zk = KazooClient(hosts='127.0.0.1:2181')
zk.start()

def myfun(event=""):
    print("func2")

lock(myfun)

