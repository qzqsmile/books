# not test this lock

from kazoo.client import KazooClient

zk = KazooClient(hosts='127.0.0.1:2181')
zk.start()


def rlock(myfunc):
    if not zk.exists("/shareLock/r"):
        zk.create("/shareLock/r")
    if not zk.exists("/shareLock/w"):
        zk.create("/shareLock/w")
    node = zk.create("/shareLock/r/", ephemeral=True, sequence=True)
    num = node.split('/')[-1]
    rlocks = zk.get_children("/shareLock/r")
    wlocks = zk.get_children("/shareLock/w")
    import pdb; pdb.set_trace()
    locks = sorted(rlocks)
    if not wlocks or num < wlocks[0]:
        myfunc()
    else:
        watch_num = wlocks[0]
        for i in range(len(wlocks)):
            if wlocks[i] > num:
                watch_num = wlocks[i-1]
                break
        zk.exists("/shareLock/w/"+watch_num, watch=myfunc)


def myfunc(event=""):
    pass

rlock(myfunc)
import pdb; pdb.set_trace()