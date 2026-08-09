import random
from collections import Counter

def brute(strings):
    cnt = Counter(strings)
    best_len = 0
    best = ""
    def dfs(left, counts):
        nonlocal best_len, best
        total = 2 * len(left)
        cand = ''.join(left) + ''.join(s[::-1] for s in reversed(left))
        if total > best_len:
            best_len = total; best = cand
        for p in list(counts):
            if counts[p] > 0 and p == p[::-1]:
                total = 2 * len(left) + 1
                cand = ''.join(left) + p + ''.join(s[::-1] for s in reversed(left))
                if total > best_len:
                    best_len = total; best = cand
        for s in list(counts):
            r = s[::-1]
            if s == r:
                if counts[s] >= 2:
                    counts[s] -= 2
                    left.append(s)
                    dfs(left, counts)
                    left.pop()
                    counts[s] += 2
            else:
                if counts[s] >= 1 and counts[r] >= 1:
                    counts[s] -= 1; counts[r] -= 1
                    left.append(s)
                    dfs(left, counts)
                    left.pop()
                    counts[s] += 1; counts[r] += 1
    dfs([], cnt.copy())
    return best

# 用户的算法（去掉哈希，用精确字符串分组）
def user_logic_no_hash(strings):
    cnt = Counter(strings)
    groups = {}
    for s in cnt:
        r = s[::-1]
        key = min(s, r)
        if key in groups:
            continue
        s1 = key; s2 = s1[::-1]
        self_ = (s1 == s2)
        groups[key] = [cnt.get(s1, 0), cnt.get(s2, 0) if not self_ else 0, self_, s1]
    front = ""; mid = ""
    for key, (num1, num2, self_, s1) in groups.items():
        if self_:
            front += s1 * (num1 // 2)
        else:
            front += s1 * min(num1, num2)
        if self_ and num1 % 2:
            mid = s1
    return front + mid + front[::-1]

# 用户的算法（带真实哈希，完全复刻 F.cpp）
MOD1 = 10**9 + 7; BASE1 = 114
MOD2 = 212370440130137957; BASE2 = 514
def hash1(s):
    re = 0
    for c in s: re = (re * BASE1 + ord(c)) % MOD1
    return re
def hash2(s):
    re = 0
    for c in s: re = (re * BASE2 + ord(c)) % MOD2
    return re
def revhash(s):
    re1 = hash1(s); re2 = 0
    for c in reversed(s): re2 = (re2 * BASE1 + ord(c)) % MOD1
    a = (re1 + re2) % MOD1
    re1 = hash2(s); re2 = 0
    for c in reversed(s): re2 = (re2 * BASE2 + ord(c)) % MOD2
    b = (re1 + re2) % MOD2
    return (a, b)
def user_logic_hash(strings):
    d = {}
    for s in strings:
        key = revhash(s)
        if key not in d:
            r = s[::-1]
            d[key] = dict(num1=0, num2=0, self_=(s == r), s1=s,
                          sh1=(hash1(s), hash2(s)), sh2=(hash1(r), hash2(r)))
        node = d[key]
        sh = (hash1(s), hash2(s))
        if sh == node['sh1']:
            node['num1'] += 1
        else:
            node['num2'] += 1
    front = ""; mid = ""
    for node in d.values():
        if node['self_']:
            front += node['s1'] * (node['num1'] // 2)
        else:
            front += node['s1'] * min(node['num1'], node['num2'])
        if node['self_'] and node['num1'] % 2:
            mid = node['s1']
    return front + mid + front[::-1]

random.seed(12345)

# 1) 无哈希版本 vs 暴力
bad = 0
for it in range(50000):
    n = random.randint(1, 7); m = random.randint(1, 3); alpha = random.randint(1, 3)
    chars = [chr(ord('a') + i) for i in range(alpha)]
    strings = [''.join(random.choice(chars) for _ in range(m)) for _ in range(n)]
    b = brute(strings); u = user_logic_no_hash(strings)
    if len(b) != len(u) or not (b == u):
        print("NO-HASH MISMATCH", strings, "brute", repr(b), len(b), "user", repr(u), len(u))
        bad += 1
        if bad >= 5: break
if bad == 0:
    print("OK: 无哈希版本与暴力在 50000 组随机数据上全部一致")

# 2) 带哈希版本 vs 暴力（随机数据下理论上不应出错）
bad = 0
for it in range(50000):
    n = random.randint(1, 7); m = random.randint(1, 3); alpha = random.randint(1, 3)
    chars = [chr(ord('a') + i) for i in range(alpha)]
    strings = [''.join(random.choice(chars) for _ in range(m)) for _ in range(n)]
    b = brute(strings); u = user_logic_hash(strings)
    if len(b) != len(u):
        print("HASH MISMATCH", strings, "brute", repr(b), len(b), "user", repr(u), len(u))
        bad += 1
        if bad >= 5: break
if bad == 0:
    print("OK: 带哈希版本在 50000 组随机数据上也未出错")
